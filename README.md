

# PersonalLib

PersonalLib 是一个基于 C++ 的通用基础库，主要用于构建交易系统、风险管理系统等金融应用。该库提供了完善的网络通信、协议处理、序列化、日志记录等功能模块。

## 项目结构

```
PersonalLib/
├── include/                  # 头文件目录
│   ├── PersonalLib/Core/     # 核心基础模块
│   ├── PersonalLib/Network/  # 网络通信模块
│   ├── PersonalLib/Serialization/  # 序列化模块
│   └── PersonalLib/TemplateLib/     # 模板库
├── src/                      # 源代码目录
│   ├── Core/                 # 核心模块实现
│   ├── Network/              # 网络模块实现
│   └── Serialization/         # 序列化实现
├── test/                     # 测试程序
├── model/                    # 数据模型定义
├── CMakeLists.txt            # CMake 构建配置
└── *.py                      # Python 工具脚本
```

## 功能特性

### 核心模块 (Core)

- **Logger**: 高性能日志系统，支持多级别日志、文件滚动、异步写入
- **MD5**: MD5 加密算法实现
- **Platform**: 跨平台基础功能，目录操作等
- **Thread**: 线程基础封装，支持启动、停止、同步
- **Timer**: 定时器功能
- **Utility**: 通用工具函数
- **Aspect**: AOP 面向切面编程支持（日志切面、性能切面）

### 网络模块 (Network)

- **IO**: 统一 IO 接口，支持多种网络模型
  - TcpSelect: 基于 select 的 IO 模型
  - TcpEpoll: 基于 epoll 的 IO 模型（Linux）
  - TcpIocp: 基于 IOCP 的 IO 模型（Windows）
- **Protocol**: 多种协议支持
  - Step 协议
  - XTP 协议
- **Shm**: 共享内存通信支持

### 序列化模块 (Serialization)

- **Base64**: Base64 编解码
- **CSV**: CSV 解析器
- **JSON**: JSON 解析和生成（基于 JsonCpp）
- **Encode**: 字符编码转换（GBK/UTF-8/Unicode）

### 模板库 (TemplateLib)

- **Buffer**: 缓冲区管理
- **RingBuffer**: 环形缓冲区
- **ShmBuffer**: 共享内存缓冲区
- **DB**: 数据库操作封装
- **MemCache**: 内存缓存
- **ObjectPool**: 对象池
- **ThreadSafeContainer**: 线程安全容器

## 构建说明

### 环境要求

- C++ 编译器（支持 C++14 及以上）
- CMake 3.10+
- Python 3.6+（用于代码生成脚本）

### 构建步骤

```bash
# 创建构建目录
mkdir build && cd build

# 配置项目
cmake ..

# 编译
cmake --build . --config Release
```

## 使用示例

### 日志系统

```cpp
#include "PersonalLib/Core/Logger/Logger.h"

int main() {
    Logger::GetInstance().Init("TestApp");
    Logger::GetInstance().SetLogLevel(LogLevel::Info);
    
    LOG_INFO("Application started");
    return 0;
}
```

### 网络通信

```cpp
#include "PersonalLib/Network/Protocol/Protocol.h"

// 创建协议对象
Protocol protocol(ProtocolTypeType::Step, ServerTypeType::Client, 
                 IOModelType::Epoll, 5000, new PackageFactory());

// 设置回调
protocol.Subscribe(new MyProtocolSubscriber());

// 连接服务器
protocol.RegisterFront("127.0.0.1:9000");
protocol.Start();
```

### JSON 处理

```cpp
#include "PersonalLib/Serialization/json/json.h"

Json::Value root;
root["name"] = "test";
root["value"] = 123;

Json::StreamWriterBuilder builder;
std::string jsonStr = Json::writeString(builder, root);
```

## 测试程序

项目包含完整的客户端和服务器测试程序：

- `test/TestClient/`: 客户端测试
- `test/TestServer/`: 服务器测试
- `test/TestCore/`: 核心模块测试

## 许可证

本项目仅供个人学习和研究使用。

## 注意事项

- 该库为个人项目，生产环境使用请自行评估风险
- 部分模块可能需要根据实际平台进行适配