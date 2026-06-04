#!/usr/bin/env python3
"""
根据 XML 配置移动头文件
源文件：./Source/{dir}/{name}
目标文件：./include/{dir}/{name}
XML 文件：copylist.xml（硬编码）
"""

import os
import shutil
import xml.etree.ElementTree as ET
from pathlib import Path

class HeaderMover:
    def __init__(self, xml_file, source_root="./Source", include_root="./include"):
        self.xml_file = xml_file
        self.source_root = Path(source_root)
        self.include_root = Path(include_root)
        self.moved_files = []
        
    def parse_xml(self):
        """解析 XML 文件"""
        tree = ET.parse(self.xml_file)
        root = tree.getroot()
        
        files_info = []
        for file_elem in root.findall('file'):
            name = file_elem.get('name')
            dir_path = file_elem.get('dir')
            
            files_info.append({
                'name': name,
                'dir': dir_path
            })
        
        print(f"解析到 {len(files_info)} 个文件")
        return files_info
    
    def move_files(self, files_info):
        """移动文件到 include 目录"""
        for file_info in files_info:
            name = file_info['name']
            dir_path = file_info['dir']
            
            # 源文件路径
            src_file = self.source_root / dir_path / name
            
            # 目标文件路径
            dest_file = self.include_root / dir_path / name
            
            # 创建目标目录
            dest_file.parent.mkdir(parents=True, exist_ok=True)
            
            # 移动文件
            if src_file.exists():
                shutil.move(str(src_file), str(dest_file))
                self.moved_files.append({
                    'src': src_file,
                    'dest': dest_file,
                    'dir': dir_path
                })
                print(f"✓ 移动: {src_file} -> {dest_file}")
            else:
                print(f"✗ 文件不存在: {src_file}")
        
        return self.moved_files
    
    def cleanup_empty_dirs(self):
        """清理空的源目录"""
        # 收集所有需要检查的目录
        dirs_to_check = set()
        for item in self.moved_files:
            src_dir = item['src'].parent
            dirs_to_check.add(src_dir)
        
        # 删除空目录（从最深层开始）
        for src_dir in sorted(dirs_to_check, key=lambda p: len(p.parts), reverse=True):
            if src_dir.exists() and not any(src_dir.iterdir()):
                src_dir.rmdir()
                print(f"✓ 删除空目录: {src_dir}")
    
    def generate_summary(self):
        """生成移动摘要"""
        print("\n" + "="*60)
        print(f"移动完成！共移动 {len(self.moved_files)} 个文件")
        
        # 按目录分组统计
        dir_stats = {}
        for item in self.moved_files:
            dir_name = item['dir'].rstrip('/')
            dir_stats[dir_name] = dir_stats.get(dir_name, 0) + 1
        
        print("\n目录统计：")
        for dir_name, count in sorted(dir_stats.items()):
            print(f"  {dir_name}: {count} 个文件")
    
    def generate_cmake_config(self):
        """生成 CMake 配置建议"""
        print("\n" + "="*60)
        print("建议添加到 CMakeLists.txt：")
        print('include_directories(${CMAKE_SOURCE_DIR}/include)')
        print('\n然后在代码中使用：')
        print('#include "Core/Aspect/Aspect.h"')
        print('#include "Serialization/json/json.h"')
    
    def run(self):
        """执行移动流程"""
        print(f"XML 文件: {self.xml_file}")
        print(f"源目录: {self.source_root}")
        print(f"目标目录: {self.include_root}")
        print("="*60)
        
        # 检查 XML 文件是否存在
        if not os.path.exists(self.xml_file):
            print(f"错误: XML 文件 {self.xml_file} 不存在！")
            return
        
        # 创建 include 根目录
        self.include_root.mkdir(parents=True, exist_ok=True)
        
        # 解析 XML
        files_info = self.parse_xml()
        
        # 移动文件
        self.move_files(files_info)
        
        # 清理空目录
        self.cleanup_empty_dirs()
        
        # 生成摘要
        self.generate_summary()
        
        # 生成 CMake 配置建议
        self.generate_cmake_config()


def main():
    # 硬编码配置
    XML_FILE = "copylist.xml"
    SOURCE_ROOT = "./Source"
    INCLUDE_ROOT = "./include"
    
    # 警告确认
    print(f"警告：将移动头文件从 {SOURCE_ROOT} 到 {INCLUDE_ROOT}")
    print("源目录中的头文件将被删除！")
    response = input("是否继续？(yes/no): ")
    
    if response.lower() != 'yes':
        print("已取消")
        return
    
    # 执行移动
    mover = HeaderMover(XML_FILE, SOURCE_ROOT, INCLUDE_ROOT)
    mover.run()


if __name__ == "__main__":
    main()