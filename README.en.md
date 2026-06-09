# PersonalLib

PersonalLib is a C++-based personal general-purpose library providing core components for building high-performance network applications and trading systems. The library supports multiple network models and communication protocols, making it suitable for scenarios such as financial trading and risk management.

## Features

### Core Modules (Core)

- **Logger** - High-performance logging system supporting multiple log levels and file rotation
- **Thread** - Basic thread encapsulation with support for thread startup, shutdown, and timeout control
- **Timer** - Timer component supporting periodic event triggering
- **Utility** - General-purpose utility functions
- **MD5** - MD5 encryption implementation
- **Platform** - Platform-specific operations (e.g., directory management)
- **Aspect** - Aspect-oriented programming support (logging, performance monitoring)

### Network Modules (Network)

- **TCP** - TCP communication
  - TcpEpoll - High-performance model based on Epoll (Linux)
  - TcpIocp - Asynchronous model based on IOCP (Windows)
  - TcpSelect - Model based on Select
- **Shm** - Shared memory communication
- **Protocol** - Communication protocols
  - Step Protocol
  - XTP Protocol
- **IO** - IO event handling and thread encapsulation

### Serialization Modules (Serialization)

- **Base64** - Base64 encoding and decoding
- **CSV** - CSV parsing
- **JSON** - JSON processing
- **Encode** - Character encoding conversion (GBK/UTF-8)

### Template Library (TemplateLib)

- **Buffer** - Buffer management
- **DB** - Database operations
- **MemCache** - In-memory caching
- **ObjectPool** - Object pool
- **ThreadSafeContainer** - Thread-safe containers

## Project Structure

```
PersonalLib/
├── include/          # Header files
│   └── PersonalLib/
│       ├── Core/        # Core modules
│       ├── Network/     # Network modules
│       ├── Serialization/  # Serialization modules
│       └── TemplateLib/ # Template library
├── src/              # Source files
│   └── PersonalLib/
├── test/             # Test code
└── model/            # Data model definitions
```

## Build Requirements

- C++14 or higher
- CMake 3.10+
- Supports Linux (Epoll) or Windows (IOCP)

## Quick Start

```cpp
#include <PersonalLib/Network/Network.h>
#include <PersonalLib/Core/Logger/Logger.h>

int main() {
    // Initialize logger
    Logger::GetInstance().Init("TestApp");
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Debug);
    
    // Create TCP server
    TcpEpollServer server("127.0.0.1:9000", 5000);
    if (server.Init()) {
        server.Start();
    }
    
    return 0;
}
```

## License

MIT License