

# PersonalLib

PersonalLib 是一个用 C++ 编写的个人通用库，提供了用于构建高性能网络应用和交易系统的核心组件。该库支持多种网络模型和通信协议，适用于金融交易、风险管理等场景。

## 功能特性

### 核心模块 (Core)

- **Logger** - 高性能日志系统，支持多级别日志输出和文件轮转
- **Thread** - 线程基础封装，支持线程启动、停止和超时控制
- **Timer** - 定时器组件，支持周期性事件触发
- **Utility** - 通用工具函数
- **MD5** - MD5 加密实现
- **Platform** - 平台相关操作（目录管理等）
- **Aspect** - 面向切面编程支持（日志、性能监控）

### 网络模块 (Network)

- **TCP** - TCP 通信
  - TcpEpoll - 基于 Epoll 的高效模型（Linux）
  - TcpIocp - 基于 IOCP 的异步模型（Windows）
  - TcpSelect - 基于 Select 的模型
- **Shm** - 共享内存通信
- **Protocol** - 通信协议
  - Step 协议
  - XTP 协议
- **IO** - IO 事件处理和线程封装

### 序列化模块 (Serialization)

- **Base64** - Base64 编解码
- **CSV** - CSV 解析
- **JSON** - JSON 处理
- **Encode** - 字符编码转换（GBK/UTF-8）

### 模板库 (TemplateLib)

- **Buffer** - 缓冲区管理
- **DB** - 数据库操作
- **MemCache** - 内存缓存
- **ObjectPool** - 对象池
- **ThreadSafeContainer** - 线程安全容器

## 项目结构

```
PersonalLib/
├── include/          # 头文件
│   └── PersonalLib/
│       ├── Core/        # 核心模块
│       ├── Network/     # 网络模块
│       ├── Serialization/  # 序列化模块
│       └── TemplateLib/ # 模板库
├── src/              # 源文件
│   └── PersonalLib/
├── test/             # 测试代码
└── model/            # 数据模型定义
```

## 构建要求

- C++14 或更高版本
- CMake 3.10+
- 支持 Linux (Epoll) 或 Windows (IOCP)

## 快速开始

```cpp
#include <PersonalLib/Network/Network.h>
#include <PersonalLib/Core/Logger/Logger.h>

int main() {
    // 初始化日志
    Logger::GetInstance().Init("TestApp");
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Debug);
    
    // 创建 TCP 服务器
    TcpEpollServer server("127.0.0.1:9000", 5000);
    if (server.Init()) {
        server.Start();
    }
    
    return 0;
}
```

## 许可证

MIT License