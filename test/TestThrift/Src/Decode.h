#pragma once
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TZlibTransport.h>
#include <thrift/protocol/TCompactProtocol.h>

struct OpMsgHeader
{
    int32_t type{ 0 };
    int32_t peerAddress{ 0 };
    int32_t bodyLen{ 0 };
};


struct OpEncoder
{
    static std::string encode(int32_t type, int32_t peerAddr)
    {
        std::string s(sizeof(OpMsgHeader), '\0');
        OpMsgHeader h{ type, peerAddr, 0 };

        std::memcpy(s.data(), &h, sizeof(h));

        return s;
    }

    template<typename MsgType>
    static std::string encode(int32_t type, int32_t peerAddr, const MsgType& msg)
    {
        using namespace apache::thrift::transport;
        using namespace apache::thrift::protocol;

        auto memBuffer = std::make_shared<TMemoryBuffer>();
        auto zlibTransport = std::make_shared<TZlibTransport>(memBuffer);
        auto pCompactProto = std::make_shared<TCompactProtocol>(zlibTransport);
        msg.write(pCompactProto.get());
        zlibTransport->flush();

        uint8_t* buffer = nullptr;
        uint32_t sz = 0;
        memBuffer->getBuffer(&buffer, &sz);

        std::string s(sizeof(OpMsgHeader) + sz, '\0');
        OpMsgHeader h{ type, peerAddr, (int32_t)sz };

        std::memcpy(s.data(), &h, sizeof(h));
        std::memcpy(s.data() + sizeof(h), buffer, sz);

        return s;
    }
};
struct OpDecoder
{
    using TCompactProtocol = apache::thrift::protocol::TCompactProtocol;

    template<typename MsgType>
    using ExtraOp = std::function<void(MsgType& msg, const std::shared_ptr<TCompactProtocol>&)>;

    template<typename MsgType>
    static void decode(const char* buf, int32_t bufSize, MsgType& msg, ExtraOp<MsgType> op = { })
    {
        using namespace apache::thrift::protocol;
        using namespace apache::thrift::transport;

        auto memBuffer = std::make_shared<TMemoryBuffer>((uint8_t*)buf, bufSize);
        auto zlibTransport = std::make_shared<TZlibTransport>(memBuffer);
        auto pompactProto = std::make_shared<TCompactProtocol>(zlibTransport);

        msg.read(pompactProto.get());

        if (op)
        {
            op(msg, pompactProto);
        }
    }
};
