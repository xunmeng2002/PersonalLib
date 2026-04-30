#!/usr/bin/env python3
"""
根据 XML 配置拷贝头文件
源文件：./Source/{dir}/{name}
目标文件：./include/{dir}/{name}
"""

import os
import shutil
import xml.etree.ElementTree as ET
from pathlib import Path

class HeaderCopier:
    def __init__(self, xml_file, source_root="./Source", include_root="./Include"):
        self.xml_file = xml_file
        self.source_root = Path(source_root)
        self.include_root = Path(include_root)
        self.copied_files = []
        
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
    
    def copy_files(self, files_info):
        """拷贝文件到 include 目录"""
        for file_info in files_info:
            name = file_info['name']
            dir_path = file_info['dir']
            
            # 源文件路径
            src_file = self.source_root / dir_path / name
            
            # 目标文件路径
            dest_file = self.include_root / dir_path / name
            
            # 创建目标目录
            dest_file.parent.mkdir(parents=True, exist_ok=True)
            
            # 拷贝文件
            if src_file.exists():
                shutil.copy2(src_file, dest_file)
                self.copied_files.append({
                    'src': src_file,
                    'dest': dest_file,
                    'dir': dir_path
                })
                print(f"✓ {src_file} -> {dest_file}")
            else:
                print(f"✗ 文件不存在: {src_file}")
        
        return self.copied_files
    
    def generate_summary(self):
        """生成拷贝摘要"""
        print("\n" + "="*60)
        print(f"拷贝完成！共拷贝 {len(self.copied_files)} 个文件")
        
        # 按目录分组统计
        dir_stats = {}
        for item in self.copied_files:
            dir_name = item['dir'].rstrip('/')
            dir_stats[dir_name] = dir_stats.get(dir_name, 0) + 1
        
        print("\n目录统计：")
        for dir_name, count in sorted(dir_stats.items()):
            print(f"  {dir_name}: {count} 个文件")
    
    def generate_cmake_config(self):
        """生成 CMake 配置建议"""
        # 收集所有需要添加的目录
        include_dirs = set()
        for item in self.copied_files:
            dir_path = item['dir'].rstrip('/')
            include_dirs.add(f"${{CMAKE_SOURCE_DIR}}/include/{dir_path}")
        
        print("\n" + "="*60)
        print("建议添加到 CMakeLists.txt 的包含路径：")
        
        # 方式1：逐行添加
        print("\n# 方式1：逐行添加")
        for dir_path in sorted(include_dirs):
            print(f'include_directories({dir_path})')
        
        # 方式2：一行添加
        print("\n# 方式2：一行添加")
        dirs_str = ' '.join(sorted(include_dirs))
        print(f'include_directories({dirs_str})')
        
        # 方式3：只添加 include 根目录（如果所有头文件都在子目录中）
        print("\n# 方式3：最简单（推荐）")
        print('include_directories(${CMAKE_SOURCE_DIR}/include)')
        print('# 然后在代码中：')
        print('#include "Aspect/Aspect.h"')
        print('#include "json/json.h"')
    
    def run(self):
        """执行拷贝流程"""
        print(f"源目录: {self.source_root}")
        print(f"目标目录: {self.include_root}")
        print("="*60)
        
        # 创建 include 根目录
        self.include_root.mkdir(parents=True, exist_ok=True)
        
        # 解析 XML
        files_info = self.parse_xml()
        
        # 拷贝文件
        self.copy_files(files_info)
        
        # 生成摘要
        self.generate_summary()
        
        # 生成 CMake 配置建议
        self.generate_cmake_config()


def main():
    import sys
    
    # 获取 XML 文件路径
    if len(sys.argv) > 1:
        xml_file = sys.argv[1]
    else:
        xml_file = "copylist.xml"
    
    # 可选：指定源目录和目标目录
    source_root = "./Source"
    include_root = "./include"
    
    if len(sys.argv) > 2:
        source_root = sys.argv[2]
    if len(sys.argv) > 3:
        include_root = sys.argv[3]
    
    if not os.path.exists(xml_file):
        print(f"错误: XML 文件 {xml_file} 不存在")
        print(f"用法: python copy_headers.py [copylist.xml] [源目录] [目标目录]")
        sys.exit(1)
    
    # 确认执行
    print(f"将根据 {xml_file} 拷贝头文件")
    print(f"源目录: {source_root}")
    print(f"目标目录: {include_root}")
    response = input("是否继续？(yes/no): ")
    
    if response.lower() != 'yes':
        print("已取消")
        sys.exit(0)
    
    # 执行拷贝
    copier = HeaderCopier(xml_file, source_root, include_root)
    copier.run()


if __name__ == "__main__":
    main()