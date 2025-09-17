#include <iostream>
#include <memory>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TTransportUtils.h>
#include "login_constants.h"
#include "MD5.h"
#include "Decode.h"
#include "SocketInit.h"
#include "IOThread.h"
#include "IOFactory.h"
#include "TcpSelectClient.h"
#include "ThriftClient.h"
#include "Logger.h"

using namespace apache::thrift;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;

using namespace std;

int main(int argc, const char* argv[])
{
	Logger::GetInstance().Init(argv[0]);
	Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
	Logger::GetInstance().Start();

	std::string tcpAddress = "tcp://124.70.214.214:6333";
	auto ioBase = IOFactory::CreateIO(ServerTypeType::Client, tcpAddress.c_str(), 100);
	IOThread* ioThread = new IOThread("ThriftClient");
	ioThread->SetIO(ioBase);

	ThriftClient thriftClient(ioBase);

	if (!ioBase->Init())
	{
		printf("IOBase Init Failed.\n");
		return -1;
	}
	ioThread->Start();
	this_thread::sleep_for(chrono::seconds(50));
	
	ioThread->Stop();
	ioThread->Join();
	
	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
	return 0;
}
