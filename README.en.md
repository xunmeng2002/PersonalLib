# PersonalLib
[![License](https://img.shields.io/badge/License-BSD--4--Clause-blue.svg)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C++20+-orange.svg)]()
[![Build](https://img.shields.io/badge/Build-CMake3.10+-green.svg)]()

**PersonalLib** is a cross-platform C++ general-purpose foundational library designed for **financial trading systems and risk management systems**. It integrates high-performance logging, multi-model network communication, serialization, data structures, utility components, and other commonly used capabilities. It supports Linux / Windows platforms and can quickly accelerate financial backend service development.

## 1. Project Overview

This is a personal open-source foundational component library focused on encapsulating low-level common capabilities for financial scenarios, avoiding reinventing the wheel. The library is developed based on standard C++20, uses CMake for cross-platform building, comes with Python scripts for automatic code generation, and includes comprehensive test cases. It is suitable for learning, secondary development, and integration into small-to-medium financial business systems.

## 2. Core Features

The library is divided into four core modules plus utility scripts, covering high-frequency scenarios in backend development:

### 2.1 Core Module

Provides low-level system capabilities with cross-platform compatibility:
- **Logger**: High-performance asynchronous logging system supporting log levels, file rolling, and thread-safe writing
- **MD5**: Standard MD5 encryption algorithm implementation
- **Platform**: Cross-platform directory, file, and system interface wrappers
- **Thread**: Basic thread encapsulation supporting start/stop, synchronization, and management
- **Timer**: General-purpose timer component
- **Utility**: Collection of common utility functions
- **Aspect**: AOP (Aspect-Oriented Programming) support for logging aspects, performance monitoring aspects

### 2.2 Network Module

Adapts to mainstream I/O models, supports protocol communication and shared memory interaction, optimized for low-latency financial scenarios:
- Unified I/O abstraction interface, masking platform differences
- Multiplexing models: `Select` (general), `Epoll` (Linux), `IOCP` (Windows)
- Protocol support: Step protocol, XTP financial protocol
- **Shm**: Shared memory communication for high-speed inter-process data exchange

### 2.3 Serialization Module

Data encoding/decoding, format parsing, and character encoding conversion:
- **JSON**: JSON parsing and serialization based on JsonCpp
- **Base64**: Base64 encoding/decoding utility
- **CSV**: Lightweight CSV file parser
- **Encode**: Character encoding conversion (GBK / UTF-8 / Unicode)

### 2.4 Template Library (TemplateLib)

High-performance data structures and common business components:
- Buffers: Generic Buffer, ring buffer `RingBuffer`, shared memory buffer `ShmBuffer`
- Database (DB) operation wrapper
- In-memory cache `MemCache`
- Object pool `ObjectPool` to reduce frequent memory allocation overhead
- Thread-safe container `ThreadSafeContainer`

### 2.5 Utility Scripts

Built-in Python scripts for automation tasks such as code parsing, model generation, and batch processing.

## 3. Project Directory Structure

```
PersonalLib/
├── include/                    # Header files (public interface)
│   ├── PersonalLib/Core/       # Core module headers
│   ├── PersonalLib/Network/    # Network module headers
│   ├── PersonalLib/Serialization/   # Serialization module headers
│   └── PersonalLib/TemplateLib/     # Template library headers
├── src/                        # Source code
│   ├── Core/                   # Core module implementations
│   ├── Network/                # Network module implementations
│   └── Serialization/          # Serialization module implementations
├── test/                       # Tests (client/server/unit tests)
│   ├── TestClient/             # Network client tests
│   ├── TestServer/             # Network server tests
│   └── TestCore/               # Core component unit tests
├── model/                      # Data model definition files
├── submodules/                 # Submodule dependencies (CMakeCommon)
├── CMakeLists.txt              # CMake main build configuration
├── CMakeSettings.json          # VS CMake configuration
├── *.py                        # Python automation scripts
├── UpdateSubmodule.bat/sh      # Submodule update scripts
├── .gitmodules                 # Git submodule configuration
├── .gitignore                  # Git ignore rules
└── LICENSE                     # Open source license
```

## 4. Environment Dependencies

### Prerequisites
- C++ compiler supporting **C++20 or later** (GCC, Clang, MSVC)
- Build tool: **CMake 3.10+**
- Script runtime: **Python 3.6+** (only for code generation scripts, not a runtime dependency)
- Platform: Linux, Windows

### Submodule Dependencies
The project depends on the `CMakeCommon` submodule. After cloning, you need to synchronize and pull the submodule.

## 5. Quick Build & Compilation

### 5.1 Clone Repository (with Submodules)
```bash
git clone --recursive https://gitee.com/xunmeng200/PersonalLib.git
cd PersonalLib
```

### 5.2 Update Submodules (if not cloned recursively)
```bash
# Linux / Mac
sh UpdateSubmodule.sh

# Windows
UpdateSubmodule.bat
```

### 5.3 CMake Build (General Process)
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

After compilation, library files and test programs will be output to the `build` directory.

## 6. Basic Usage Examples

### 6.1 High-Performance Logging

```cpp
#include "PersonalLib/Core/Logger/Logger.h"

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
#include "PersonalLib/Serialization/json/json.h"
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
#include "PersonalLib/Network/Protocol/Protocol.h"

int main()
{
    // Initialize protocol: Step protocol + Client mode + Epoll model
    Protocol protocol(ProtocolTypeType::Step, ServerTypeType::Client,
                      IOModelType::Epoll, 5000, new PackageFactory());

    // Register message callback
    protocol.Subscribe(new MyProtocolSubscriber());
    // Connect to server address
    protocol.RegisterFront("127.0.0.1:9000");
    // Start the network service
    protocol.Start();

    return 0;
}
```

## 7. Test Programs

The project includes a full set of test cases in the `test/` directory:

- **TestServer**: Network server test program
- **TestClient**: Network client test program
- **TestCore**: Core component (logger, thread, utility) unit tests

After compilation, run the corresponding executables directly to verify functionality.

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

- **Cross-platform differences**: Epoll is only supported on Linux, IOCP only on Windows. The code has been adapted accordingly.
- **Financial protocols**: Built-in wrappers for standard financial protocols such as XTP, ready to connect to corresponding market/trading interfaces.
- **Extensibility**: Custom protocols, data structures, and business components can be added based on the existing modules.
