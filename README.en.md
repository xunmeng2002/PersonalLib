# PersonalLib

PersonalLib is a high-performance generic library based on C++ that provides core foundational components, network communication, serialization, and template libraries. It is designed for building financial software such as distributed trading systems and risk control systems, supporting both Windows and Linux platforms.

## Project Structure

```
PersonalLib/
├── include/PersonalLib/          # Header files directory
│   ├── Core/                     # Core foundational module
│   │   ├── Aspect/               # Aspect-Oriented Programming (AOP)
│   │   ├── Logger/               # Logging system
│   │   ├── MD5/                  # MD5 encryption
│   │   ├── Platform/             # Platform-related utilities
│   │   ├── Thread/               # Thread base classes
│   │   ├── Timer/                # Timer
│   │   └── Utility/              # General utility functions
│   ├── Network/                  # Network communication module
│   │   ├── IO/                   # I/O management
│   │   ├── Protocol/             # Protocol handling
│   │   ├── Shm/                  # Shared memory
│   │   └── Tcp/                  # TCP networking (multi-mode)
│   ├── Serialization/            # Serialization module
│   │   ├── Base64/               # Base64 encoding/decoding
│   │   ├── Csv/                  # CSV parsing
│   │   ├── Encode/               # Character encoding conversion
│   │   └── json/                 # JSON processing
│   ├── TemplateLib/              # Template library
│   │   ├── Buffer/               # Buffer management
│   │   ├── ConfigStructs/        # Configuration structs
│   │   ├── Constant/             # Constant definitions
│   │   ├── DB/                   # Database operations
│   │   ├── MemCache/             # Memory cache
│   │   ├── ObjectPool/           # Object pool
│   │   └── ThreadSafeContainer/  # Thread-safe containers
│   └── Types.h                   # Type definitions
├── src/PersonalLib/              # Source code directory
├── test/                         # Test code
├── model/                        # Data model definitions
└── *.py                          # Build script tools
```

## Core Features

### 1. Core Module

- **Logger**: High-performance asynchronous logging system supporting multiple log levels, file rotation, and thread safety.
- **MD5**: Implementation of the MD5 encryption algorithm.
- **Platform**: Cross-platform directory operations and path handling.
- **Thread**: Thread base class encapsulating thread creation, management, and destruction.
- **Timer**: Timer functionality supporting periodic task scheduling.
- **Utility**: Common utility functions (time handling, type conversion, etc.).
- **Aspect**: Aspect-Oriented Programming support for logging and performance monitoring.

### 2. Network Module

Supports multiple I/O models:

- **Select**: I/O model based on select.
- **Epoll**: High-performance epoll model on Linux.
- **IOCp**: Windows IOCP (I/O Completion Port) model.

Network protocol support:

- **Protocol**: Generic protocol handling framework.
- **Step**: Step protocol (industry-standard financial protocol).
- **XTP**: XTP protocol.

Shared memory:

- **Shm**: Shared memory communication mechanism.
- **Sem**: Semaphore synchronization.

### 3. Serialization Module

- **Base64**: Base64 encoding/decoding.
- **Csv**: CSV file parser.
- **Encode**: Character encoding conversion (GBK/UTF-8/Unicode).
- **Json**: JSON parsing and generation.

### 4. TemplateLib Module

- **Buffer**: Circular buffer, shared buffer.
- **ObjectPool**: Object pool to reduce memory allocation overhead.
- **ThreadSafeContainer**: Thread-safe containers (lock-free queue, thread-safe list).
- **MemCache**: Memory cache template.

## Compilation Requirements

- C++14 or higher compiler
- CMake 3.10 or higher
- Windows: Visual Studio 2015 or higher, or MinGW
- Linux: GCC 5.0 or higher

## Quick Start

### Build

```bash
mkdir build
cd build
cmake ..
make
```

### Usage Example

```cpp
#include "PersonalLib/Core/Core.h"
#include "PersonalLib/Network/Network.h"
#include "PersonalLib/Serialization/Serialization.h"

int main() {
    // Use the logging system
    Logger::GetInstance().Init("TestApp");
    LOG_INFO("Application started");
    
    // Use time utilities
    auto now = TimeUtility::GetTime();
    std::string dateTime = TimeUtility::GetLocalDateTime();
    
    // Use JSON
    Json::Value root;
    root["name"] = "test";
    root["value"] = 123;
    std::string jsonStr = root.toStyledString();
    
    return 0;
}
```

## Module Dependencies

```
Core
├── Logger (depends on Thread)
├── Thread
├── Timer
├── Utility
└── Aspect (depends on Logger)

Network
├── Core
├── Protocol (depends on IO)
├── Tcp (depends on Core, IO)
└── Shm (depends on Core, IO)

Serialization
└── Core

TemplateLib
├── Core
└── Buffer
```

## License

MIT License

## Contributors

This is a personal development library. Issues and Pull Requests are welcome.