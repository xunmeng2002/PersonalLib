# PersonalLib

PersonalLib is a C++-based general-purpose foundational library primarily designed for building financial applications such as trading systems and risk management systems. The library provides comprehensive modules for network communication, protocol handling, serialization, logging, and more.

## Project Structure

```
PersonalLib/
├── include/                  # Header files directory
│   ├── PersonalLib/Core/     # Core foundational modules
│   ├── PersonalLib/Network/  # Network communication modules
│   ├── PersonalLib/Serialization/  # Serialization modules
│   └── PersonalLib/TemplateLib/     # Template library
├── src/                      # Source code directory
│   ├── Core/                 # Core module implementations
│   ├── Network/              # Network module implementations
│   └── Serialization/         # Serialization implementations
├── test/                     # Test programs
├── model/                    # Data model definitions
├── CMakeLists.txt            # CMake build configuration
└── *.py                      # Python utility scripts
```

## Features

### Core Module (Core)

- **Logger**: High-performance logging system supporting multiple log levels, file rotation, and asynchronous writing
- **MD5**: MD5 encryption algorithm implementation
- **Platform**: Cross-platform foundational functions, including directory operations
- **Thread**: Basic thread encapsulation supporting start, stop, and synchronization
- **Timer**: Timer functionality
- **Utility**: General-purpose utility functions
- **Aspect**: AOP (Aspect-Oriented Programming) support (e.g., logging aspect, performance aspect)

### Network Module (Network)

- **IO**: Unified I/O interface supporting multiple network models:
  - TcpSelect: select-based I/O model
  - TcpEpoll: epoll-based I/O model (Linux)
  - TcpIocp: IOCP-based I/O model (Windows)
- **Protocol**: Support for multiple protocols:
  - Step Protocol
  - XTP Protocol
- **Shm**: Shared memory communication support

### Serialization Module (Serialization)

- **Base64**: Base64 encoding and decoding
- **CSV**: CSV parser
- **JSON**: JSON parsing and generation (based on JsonCpp)
- **Encode**: Character encoding conversion (GBK/UTF-8/Unicode)

### Template Library (TemplateLib)

- **Buffer**: Buffer management
- **RingBuffer**: Circular buffer
- **ShmBuffer**: Shared memory buffer
- **DB**: Database operation encapsulation
- **MemCache**: In-memory cache
- **ObjectPool**: Object pool
- **ThreadSafeContainer**: Thread-safe containers

## Build Instructions

### Environment Requirements

- C++ compiler (supporting C++14 or higher)
- CMake 3.10+
- Python 3.6+ (used for code generation scripts)

### Build Steps

```bash
# Create build directory
mkdir build && cd build

# Configure project
cmake ..

# Compile
cmake --build . --config Release
```

## Usage Examples

### Logging System

```cpp
#include "PersonalLib/Core/Logger/Logger.h"

int main() {
    Logger::GetInstance().Init("TestApp");
    Logger::GetInstance().SetLogLevel(LogLevel::Info);
    
    LOG_INFO("Application started");
    return 0;
}
```

### Network Communication

```cpp
#include "PersonalLib/Network/Protocol/Protocol.h"

// Create protocol object
Protocol protocol(ProtocolTypeType::Step, ServerTypeType::Client, 
                 IOModelType::Epoll, 5000, new PackageFactory());

// Set callback
protocol.Subscribe(new MyProtocolSubscriber());

// Connect to server
protocol.RegisterFront("127.0.0.1:9000");
protocol.Start();
```

### JSON Processing

```cpp
#include "PersonalLib/Serialization/json/json.h"

Json::Value root;
root["name"] = "test";
root["value"] = 123;

Json::StreamWriterBuilder builder;
std::string jsonStr = Json::writeString(builder, root);
```

## Test Programs

The project includes comprehensive client and server test programs:

- `test/TestClient/`: Client tests
- `test/TestServer/`: Server tests
- `test/TestCore/`: Core module tests

## License

This project is intended solely for personal learning and research purposes.

## Notes

- This library is a personal project; evaluate risks before using in production environments
- Some modules may require platform-specific adaptations