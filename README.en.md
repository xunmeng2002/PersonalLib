# Spark
[![License](https://img.shields.io/badge/License-BSD--4--Clause-blue.svg)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C++20+-orange.svg)]()
[![Build](https://img.shields.io/badge/Build-CMake3.10+-green.svg)]()

**Spark** is a cross-platform C++ general-purpose foundational library designed for **financial trading systems and risk management systems**. It integrates high-performance logging, multi-model network communication, protocol serialization, high-performance data structures, and utility components. It supports Linux / Windows platforms and can accelerate financial backend service development.

Created by [Fireseeker](https://fireseeker.cn/)

## 1. Project Overview

This is a personal open-source foundational component library focused on encapsulating low-level common capabilities for financial scenarios. The library is developed in standard C++20, uses CMake for cross-platform building, includes Python scripts for automatic code generation, and comes with a comprehensive Google Test-based unit test suite. It is suitable for learning, secondary development, and integration into small-to-medium financial business systems.

## 2. Core Features

The library is divided into four core modules plus utility scripts:

### 2.1 Core Module

Provides low-level system capabilities with cross-platform compatibility:
- **Logger**: High-performance asynchronous logging system supporting log levels, file rolling, and thread-safe writing
- **MD5**: Standard MD5 encryption algorithm implementation
- **Platform**: Cross-platform directory, file, and system interface wrappers
- **Thread**: Basic thread encapsulation supporting start/stop, synchronization, and management
- **Timer**: General-purpose timer component
- **Utility**: Collection of common utility functions (Double precision comparison, time utilities, etc.)
- **Aspect**: AOP (Aspect-Oriented Programming) support for logging aspects and performance monitoring

### 2.2 Network Module

Adapts to mainstream I/O models, supports protocol communication and shared memory interaction, optimized for low-latency financial scenarios:
- **IO**: Unified I/O abstraction interface masking platform differences; multiplexing models: `Select` (general), `Epoll` (Linux), `IOCP` (Windows)
- **Tcp**: TCP communication wrappers with full client/server support for Select / Epoll / IOCP models
- **Protocol**: Financial protocol support — Step protocol (text-based tag-value) and XTP protocol (binary high-performance); includes package serialization (`Package::MakePackage`), package parsing (`PackageReader`), buffer management, and checksum calculation
- **Shm**: Shared memory communication for high-speed inter-process data exchange

### 2.3 Serialization Module

Data encoding/decoding, format parsing, and character encoding conversion:
- **JSON**: JSON parsing and serialization based on JsonCpp
- **Base64**: Base64 encoding/decoding utility
- **CSV**: Lightweight CSV file parser (CsvParser + CsvRecord)
- **Encode**: Character encoding conversion (GBK / UTF-8 / Unicode)

### 2.4 Template Library (TemplateLib)

High-performance data structures and reusable business components:
- **Buffer**: Generic buffer
- **RingBuffer**: Ring buffer (lock-free and locked variants)
- **ShmBuffer**: Shared memory buffer
- **ObjectPool**: Object pool to reduce frequent memory allocation overhead
- **LockFreeQueue**: Lock-free queue
- **ThreadSafeList**: Thread-safe linked list container

### 2.5 Utility Scripts

Built-in Python scripts for automation tasks such as code parsing, model generation, and batch processing.

## 3. Project Directory Structure

```
Spark/
├── include/                    # Public headers
│   ├── Spark/Core/             # Core module headers
│   ├── Spark/Network/          # Network module headers
│   ├── Spark/Serialization/    # Serialization module headers
│   └── Spark/TemplateLib/      # TemplateLib module headers
├── src/                        # Source code
│   ├── Core/                   # Core module implementations
│   ├── Network/                # Network module implementations
│   └── Serialization/          # Serialization module implementations
├── test/                       # Test programs
│   ├── unittest/               # GTest unit tests (primary test entry)
│   │   ├── Core/               # Core module tests (9 files)
│   │   ├── Network/            # Network module tests (4 files)
│   │   ├── Serialization/      # Serialization module tests (4 files)
│   │   ├── TemplateLib/        # TemplateLib module tests (6 files)
│   │   └── CMakeLists.txt      # Unit test build configuration
│   ├── src/TestCommon/         # Shared test library (Package factory, subscribers, etc.)
│   ├── TestClient/             # Network client tests (legacy)
│   ├── TestServer/             # Network server tests (legacy)
│   └── TestCore/               # Core component tests (legacy)
├── model/                      # Data model definitions
├── submodules/                 # Submodule dependencies (CMakeCommon)
├── CMakeLists.txt              # CMake main build configuration
├── CMakeSettings.json          # VS CMake configuration
├── *.py                        # Python automation scripts
├── UpdateSubmodule.bat/sh      # Submodule update scripts
├── .gitmodules                 # Git submodule configuration
├── .gitignore                  # Git ignore rules
└── LICENSE                     # BSD-4-Clause license
```

## 4. Environment Dependencies

### Prerequisites

- C++ compiler supporting **C++20 or later** (GCC, Clang, MSVC)
- Build tool: **CMake 3.10+**
- Script runtime: **Python 3.6+** (only for code generation scripts, not a runtime dependency)
- Test framework: **Google Test** (auto-detected by CMake; must be installed via vcpkg or system package manager)
- Platform: Linux, Windows

### Submodule Dependencies

The project depends on the `CMakeCommon` submodule. After cloning, you need to synchronize and pull the submodule.

> For detailed environment setup steps (proxy configuration, vcpkg installation, WSL mirrored networking, etc.), see the [Environment Setup Guide](docs/environment-setup.en.md).

## 5. Quick Build & Compilation

### 5.1 Clone Repository (with Submodules)

```bash
git clone --recursive https://gitee.com/xunmeng200/Spark.git
cd Spark
```

### 5.2 Update Submodules (if not cloned recursively)

```bash
# Linux / Mac
sh UpdateSubmodule.sh

# Windows
UpdateSubmodule.bat
```

### 5.3 CMake Build

```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

After compilation, library files (Core / Network / Serialization / TemplateLib) and the test executable (UnitTests) will be output to the `build` directory.

### 5.4 Run Unit Tests

```bash
cd build
ctest --output-on-failure
# or directly
./test/unittest/UnitTests
```

## 6. Basic Usage Examples

### 6.1 High-Performance Logging

```cpp
#include "Spark/Core/Logger/Logger.h"

int main()
{
    // Initialize the logger with an application name
    Logger::GetInstance().Init("FinancialDemo");
    // Set the log output level
    Logger::GetInstance().SetLogLevel(LogLevel::Info);

    // Level-based logging
    LOG_INFO("Application started successfully");
    LOG_DEBUG("Debug message: system init done");
    LOG_ERROR("Demo running");

    return 0;
}
```

### 6.2 JSON Serialization & Parsing

```cpp
#include "Spark/Serialization/json/json.h"
#include <iostream>

int main()
{
    Json::Value root;
    root["order_id"] = "20260615001";
    root["price"] = 123.45;
    root["volume"] = 1000;
    root["is_buy"] = true;

    // Serialize JSON object to string
    Json::StreamWriterBuilder builder;
    std::string json_str = Json::writeString(builder, root);
    std::cout << "JSON String: " << json_str << std::endl;

    return 0;
}
```

### 6.3 Network Communication (Step Protocol Client)

```cpp
#include <Spark/Network/Protocol/Protocol.h>
#include <Spark/Network/Protocol/PackageFactory.h>
#include <Spark/Network/IO/IOThread.h>
#include <Spark/Core/Logger/Logger.h>

// Custom client: inherit Protocol and implement ProtocolSubscriber callbacks
class MyStepClient : public Protocol, public ProtocolSubscriber
{
public:
    MyStepClient()
        : Protocol(ProtocolTypeType::Step, ServerTypeType::Client,
                   IOModelType::Epoll, 0, new PackageFactory())
    {
        Subscribe(this);                        // Register self as message subscriber
        RegisterFront("tcp://127.0.0.1:20001"); // Connect to server address
        // Shared memory format: RegisterFront("shm://TestShm:4");  // "shm://" + serviceName + ":" + maxConnections
    }

    // Connection established callback
    void OnProtocolConnect(SessionIDType sessionID, const char* ip, int port) override
    {
        LOG_INFO("Connected SessionID:[{}], IP:[{}], port:[{}]", sessionID, ip, port);
    }

    // Connection disconnected callback
    void OnProtocolDisConnect(SessionIDType sessionID, const char* ip, int port) override
    {
        LOG_INFO("DisConnected SessionID:[{}]", sessionID);
    }

    // Incoming message callback
    void OnMessage(Package* package) override
    {
        LOG_INFO("Recv Package: {}", package->GetDebugString());

        // Build and send a response
        ReqInsertOrderPackage* resp = new ReqInsertOrderPackage();
        resp->Prepare(package->SessionID, false, package->Head.MsgSeqNum);
        resp->ReqInsertOrder = ObjectPool<ReqInsertOrderField>::GetInstance().Allocate();
        resp->ReqInsertOrder->Price = 100.5;
        resp->ReqInsertOrder->Volume = 1000;
        Send(resp);
        resp->Deallocate();
    }
};

int main()
{
    // Initialize logger
    Logger::GetInstance().Init("StepClient");
    Logger::GetInstance().SetLogLevel(LogLevel::Info);

    // Create IO thread and start the client
    IOThread* ioThread = new IOThread("StepClient");
    MyStepClient client;
    client.SetIOThread(ioThread);
    if (!client.Init())
        return -1;

    ioThread->Start();      // Start the event loop (blocks current thread)
    ioThread->Join();

    return 0;
}
```

## 7. Unit Tests

The project includes a comprehensive **Google Test**-based unit test suite with **23 test files** across four modules:

| Module | Test Files | Coverage |
| --- | --- | --- |
| **Core** | `AspectTest` | Logging & performance aspects |
| | `DirTest` | Directory creation, deletion, traversal |
| | `DoubleUtilityTest` | Floating-point precision comparison |
| | `LoggerTest` | Log levels, file rolling, thread safety |
| | `MD5Test` | MD5 hash correctness |
| | `ThreadBaseTest` | Thread start/stop, synchronization |
| | `TimerTest` | Timer firing and cancellation |
| | `TimeUtilityTest` | Time formatting and conversion |
| | `UtilityTest` | General utility functions |
| **Network** | `StepUtilityTest` | Step protocol field parsing, Head/Tail stream conversion (15 cases) |
| | `ProtocolUtilityTest` | CHECKSUM calculation (7 cases) |
| | `PackageReaderTest` | Buffer management: Append/PopFront/Shift/Reset (15 cases) |
| | `PackageSerializationTest` | End-to-end MakePackage ↔ ParsePackage round-trip (6 cases) |
| **Serialization** | `Base64Test` | Base64 encoding/decoding |
| | `CSVParserTest` | CSV row/column parsing, quote escaping |
| | `CSVRecordTest` | CSV record reading/writing |
| | `EncodeTest` | GBK/UTF-8/Unicode conversion |
| **TemplateLib** | `BufferTest` | Buffer read/write and expansion |
| | `LockFreeQueueTest` | Lock-free queue push/pop |
| | `ObjectPoolTest` | Object pool allocation and reuse |
| | `RingBufferTest` | Ring buffer read/write wrap-around |
| | `ShmBufferTest` | Shared memory buffer |
| | `ThreadSafeListTest` | Thread-safe insert/delete/traverse |

### Running All Tests

```bash
cd build
ctest
```

Or run `test/unittest/UnitTests` directly for detailed console output.

## 8. Script Reference

Python scripts in the root directory are used for automated code processing:

| Script | Description |
|--------|-------------|
| Parse*.py | Data model, table, and field parsing scripts |
| pump.py / pumpall.py | Batch data processing scripts |
| geninc.py | Automatic header file generation |
| copyheader.py / copymodel.py | Batch file/model copying |
| clearall.py | Temporary file cleanup |

## 9. License & Disclaimer

- **License**: BSD-4-Clause. See the [LICENSE](LICENSE) file for details.
- **Scope**: This project is intended solely for personal learning and research purposes.
- **Disclaimer**: This is a personal open-source project. For production use, please conduct thorough testing and evaluate risks.

## 10. Additional Notes

- **Cross-platform differences**: `Epoll` is only supported on Linux, `IOCP` only on Windows. The code has been adapted accordingly. `Select` is the general model and works on both platforms.
- **Financial protocols**: Built-in wrappers for Step (text-based tag-value, commonly used in futures CTP protocol family) and XTP (binary high-performance) protocols, ready to connect to corresponding market/trading interfaces.
- **Extensibility**: Custom protocols, data structures, and business components can be added based on the existing modules.
- **Include path style**: Headers use `#include <Spark/Module/HeaderName.h>` convention.
