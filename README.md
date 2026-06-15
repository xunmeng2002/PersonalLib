# PersonalLib
[![License](https://img.shields.io/badge/License-BSD--4--Clause-blue.svg)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C++14+-orange.svg)]()
[![Build](https://img.shields.io/badge/Build-CMake3.10+-green.svg)]()

**PersonalLib** 是一套面向**金融交易系统、风险管理系统**设计的跨平台 C++ 通用基础库，集成高性能日志、多模型网络通信、序列化、数据结构、工具组件等常用能力，适配 Linux / Windows 双平台，可快速落地金融后端服务开发。

## 一、项目概述
本项目为个人开源基础组件库，聚焦金融场景下的底层通用能力封装，规避重复造轮子。库基于标准 C++14 开发，采用 CMake 跨平台构建，配套 Python 脚本实现代码自动生成，内置完整测试用例，适合学习、二次开发及中小型金融业务系统集成。

## 二、核心功能模块
整体分为四大核心模块 + 工具脚本，覆盖后端开发高频场景：

### 1. 核心基础模块（Core）
提供系统底层通用能力，跨平台兼容：
- **Logger**：高性能异步日志系统，支持日志分级、文件滚动、多线程安全写入
- **MD5**：标准 MD5 加密算法实现
- **Platform**：跨平台目录、文件、系统接口封装
- **Thread**：线程基础封装，支持线程启停、同步、管理
- **Timer**：通用定时器组件
- **Utility**：通用工具函数集合
- **Aspect**：AOP 面向切面编程，支持日志切面、性能监控切面

### 2. 网络通信模块（Network）
适配主流 IO 模型，支持协议通信与共享内存交互，专为金融低时延场景优化：
- 统一 IO 抽象接口，屏蔽平台差异
- 多路复用模型：`Select`(通用)、`Epoll`(Linux)、`IOCP`(Windows)
- 协议支持：Step 协议、XTP 金融协议
- **Shm**：共享内存通信，适用于进程间高速数据交互

### 3. 序列化模块（Serialization）
数据编解码、格式解析与字符编码转换：
- **JSON**：基于 JsonCpp 实现 JSON 解析与序列化
- **Base64**：Base64 编解码工具
- **CSV**：轻量 CSV 文件解析器
- **Encode**：字符编码互转（GBK / UTF-8 / Unicode）

### 4. 模板工具库（TemplateLib）
高性能数据结构与通用业务组件：
- 缓冲区：通用 Buffer、环形缓冲区 `RingBuffer`、共享内存缓冲区 `ShmBuffer`
- 数据库（DB）简易操作封装
- 内存缓存 `MemCache`
- 对象池 `ObjectPool`，减少频繁内存分配开销
- 线程安全容器 `ThreadSafeContainer`

### 5. 辅助工具
项目内置 Python 脚本，用于代码解析、模型生成、批量处理等自动化工作。

## 三、项目目录结构
PersonalLib/
├── include/ # 头文件目录（对外暴露接口）
│ ├── PersonalLib/Core/ # 核心模块头文件
│ ├── PersonalLib/Network/ # 网络模块头文件
│ ├── PersonalLib/Serialization/ # 序列化模块头文件
│ └── PersonalLib/TemplateLib/ # 模板库头文件
├── src/ # 源码实现目录
│ ├── Core/ # 核心模块实现
│ ├── Network/ # 网络模块实现
│ └── Serialization/ # 序列化模块实现
├── test/ # 测试程序（客户端 / 服务端 / 单元测试）
│ ├── TestClient/ # 网络客户端测试
│ ├── TestServer/ # 网络服务端测试
│ └── TestCore/ # 核心组件单元测试
├── model/ # 数据模型定义文件
├── submodules/ # 子模块依赖（CMakeCommon）
├── CMakeLists.txt # CMake 主构建配置
├── CMakeSettings.json # VS CMake 配置
├── *.py # Python 自动化脚本
├── UpdateSubmodule.bat/sh # 子模块更新脚本
├── .gitmodules # Git 子模块配置
├── .gitignore # Git 忽略规则
└── LICENSE # 开源许可证

## 四、环境依赖
### 基础要求
- C++ 编译器：支持 **C++14 及以上**（GCC、Clang、MSVC）
- 构建工具：**CMake 3.10+**
- 脚本环境：**Python 3.6+**（仅用于代码生成类脚本，非运行依赖）
- 平台：Linux、Windows

### 依赖子模块
项目依赖 `CMakeCommon` 子模块，克隆代码后需同步拉取子模块。

## 五、快速构建 & 编译
### 1. 克隆代码（含子模块）
```bash
git clone --recursive https://gitee.com/xunmeng200/PersonalLib.git
cd PersonalLib
```

### 2. 更新子模块（若未递归克隆）
```bash
# Linux / Mac
sh UpdateSubmodule.sh

# Windows
UpdateSubmodule.bat
```

### 3. CMake 编译（通用流程）
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

编译完成后，库文件、测试程序会输出至 build 目录对应路径。

## 六、基础使用示例
### 示例 1：高性能日志组件

```cpp
#include "PersonalLib/Core/Logger/Logger.h"

int main()
{
    // 初始化日志器，指定应用名称
    Logger::GetInstance().Init("FinancialDemo");
    // 设置日志输出级别
    Logger::GetInstance().SetLogLevel(LogLevel::Info);

    // 分级日志输出
    LOG_INFO("Application started successfully");
    LOG_DEBUG("Debug message: system init done");
    LOG_ERROR("Demo running");

    return 0;
}
```

### 示例 2：JSON 序列化与解析

```cpp
#include "PersonalLib/Serialization/json/json.h"
#include <iostream>

int main()
{
    Json::Value root;
    root["order_id"] = "20260615001";
    root["price"] = 123.45;
    root["volume"] = 1000;
    root["is_buy"] = true;

    // JSON 对象转字符串
    Json::StreamWriterBuilder builder;
    std::string json_str = Json::writeString(builder, root);
    std::cout << "JSON String: " << json_str << std::endl;

    return 0;
}
```

### 示例 3：网络通信（Step 协议客户端）

```cpp
#include "PersonalLib/Network/Protocol/Protocol.h"

int main()
{
    // 初始化协议对象：Step协议 + 客户端模式 + Epoll模型
    Protocol protocol(ProtocolTypeType::Step, ServerTypeType::Client,
                      IOModelType::Epoll, 5000, new PackageFactory());

    // 注册消息回调
    protocol.Subscribe(new MyProtocolSubscriber());
    // 连接服务端地址
    protocol.RegisterFront("127.0.0.1:9000");
    // 启动网络服务
    protocol.Start();

    return 0;
}
```

## 七、测试程序说明
项目内置全套测试用例，位于 test/ 目录：
TestServer：网络服务端测试程序
TestClient：网络客户端测试程序
TestCore：核心组件（日志、线程、工具类）单元测试
编译完成后可直接运行对应可执行文件验证功能。

## 八、脚本说明
根目录下 Python 脚本用于自动化代码处理，常用脚本说明：
Parse*.py：数据模型、数据表、字段解析脚本
pump.py / pumpall.py：批量数据处理脚本
geninc.py：头文件自动生成
copyheader.py / copymodel.py：文件、模型批量复制
clearall.py：临时文件清理

## 九、许可证 & 声明
开源协议：BSD-4-Clause，详见 LICENSE 文件
适用范围：本项目仅供个人学习、研究使用
风险提示：本库为个人开源项目，生产环境使用请自行充分测试并评估风险

## 十、补充说明
跨平台差异：Epoll 仅支持 Linux，IOCP 仅支持 Windows，代码已做平台适配；
金融协议：内置 XTP 等金融标准协议封装，可直接对接对应行情 / 交易接口；
扩展开发：可基于现有模块扩展自定义协议、数据结构、业务组件。

