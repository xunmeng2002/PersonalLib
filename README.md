

# PersonalLib

PersonalLib 是一个基于 C++ 的高性能通用库，提供了核心基础组件、网络通信、序列化处理、模板库等功能模块。该库设计用于构建分布式交易系统、风控系统等金融软件，支持 Windows 和 Linux 双平台。

## 项目结构

```
PersonalLib/
├── include/PersonalLib/          # 头文件目录
│   ├── Core/                     # 核心基础模块
│   │   ├── Aspect/               # 面向切面编程 (AOP)
│   │   ├── Logger/                # 日志系统
│   │   ├── MD5/                  # MD5 加密
│   │   ├── Platform/             # 平台相关工具
│   │   ├── Thread/               # 线程基础类
│   │   ├── Timer/                # 定时器
│   │   └── Utility/              # 通用工具函数
│   ├── Network/                  # 网络通信模块
│   │   ├── IO/                    # I/O 管理
│   │   ├── Protocol/              # 协议处理
│   │   ├── Shm/                  # 共享内存
│   │   └── Tcp/                  # TCP 网络 (多模式)
│   ├── Serialization/             # 序列化模块
│   │   ├── Base64/               # Base64 编解码
│   │   ├── Csv/                  # CSV 解析
│   │   ├── Encode/               # 字符编码转换
│   │   └── json/                 # JSON 处理
│   ├── TemplateLib/              # 模板库
│   │   ├── Buffer/               # 缓冲区管理
│   │   ├── ConfigStructs/        # 配置结构体
│   │   ├── Constant/             # 常量定义
│   │   ├── DB/                   # 数据库操作
│   │   ├── MemCache/             # 内存缓存
│   │   ├── ObjectPool/           # 对象池
│   │   └── ThreadSafeContainer/  # 线程安全容器
│   └── Types.h                   # 类型定义
├── src/PersonalLib/               # 源代码目录
├── test/                         # 测试代码
├── model/                        # 数据模型定义
└── *.py                         # 构建脚本工具
```

## 核心特性

### 1. Core 核心模块

- **Logger**: 高性能异步日志系统，支持多级别日志输出、文件滚动、线程安全
- **MD5**: MD5 加密算法实现
- **Platform**: 跨平台目录操作、路径处理
- **Thread**: 线程基类，封装线程创建、管理、销毁
- **Timer**: 定时器功能，支持周期性任务调度
- **Utility**: 常用工具函数（时间处理、类型转换等）
- **Aspect**: 面向切面编程，支持日志、性能监控

### 2. Network 网络模块

支持多种 I/O 模型：

- **Select**: 基于 select 的 I/O 模型
- **Epoll**: Linux 高性能 epoll 模型
- **IOCp**: Windows IOCP (I/O Completion Port) 模型

网络协议支持：

- **Protocol**: 通用协议处理框架
- **Step**: Step 协议（金融行业标准协议）
- **XTP**: XTP 协议

共享内存：

- **Shm**: 共享内存通信机制
- **Sem**: 信号量同步

### 3. Serialization 序列化模块

- **Base64**: Base64 编解码
- **Csv**: CSV 文件解析器
- **Encode**: GBK/UTF-8/Unicode 字符编码转换
- **Json**: JSON 解析与生成

### 4. TemplateLib 模板库

- **Buffer**: 环形缓冲区、共享缓冲区
- **ObjectPool**: 对象池，减少内存分配开销
- **ThreadSafeContainer**: 线程安全容器（无锁队列、线程安全列表）
- **MemCache**: 内存缓存模板

## 编译要求

- C++14 及以上编译器
- CMake 3.10+
- Windows: Visual Studio 2015+ 或 MinGW
- Linux: GCC 5.0+

## 快速开始

### 编译

```bash
mkdir build
cd build
cmake ..
make
```

### 使用示例

```cpp
#include "PersonalLib/Core/Core.h"
#include "PersonalLib/Network/Network.h"
#include "PersonalLib/Serialization/Serialization.h"

int main() {
    // 使用日志系统
    Logger::GetInstance().Init("TestApp");
    LOG_INFO("Application started");
    
    // 使用时间工具
    auto now = TimeUtility::GetTime();
    std::string dateTime = TimeUtility::GetLocalDateTime();
    
    // 使用 JSON
    Json::Value root;
    root["name"] = "test";
    root["value"] = 123;
    std::string jsonStr = root.toStyledString();
    
    return 0;
}
```

## 模块依赖

```
Core
├── Logger (依赖 Thread)
├── Thread
├── Timer
├── Utility
└── Aspect (依赖 Logger)

Network
├── Core
├── Protocol (依赖 IO)
├── Tcp (依赖 Core, IO)
└── Shm (依赖 Core, IO)

Serialization
└── Core

TemplateLib
├── Core
└── Buffer
```

## 许可证

MIT License

## 贡献者

项目为个人开发库，欢迎提交 Issue 和 Pull Request。