#pragma once
#include "ThreadBase.h"
#include "IOBase.h"
#include "TopicDecoder.h"
#include "Buffer.h"
#include "login_constants.h"
#include "unit_constants.h"
#include "common_constants.h"
#include "topic_constants.h"
#include "strategy_constants.h"
#include "liveparam_constants.h"
#include "account_constants.h"
#include <cstring>
#include <map>
#include <iostream>


class ThriftClient : public IOSubscriber
{
public:
	ThriftClient(IOBase* io);
	~ThriftClient();


	virtual void OnConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnRecv(SessionIDType sessionID, Buffer<BuffSize>* buffer) override;

	void ReqLogin();
	void QryUnit(const SessionIDType& sessionID, const std::string& hostname);
	void QryAccount(const SessionIDType& sessionID, const std::string& unitname);
	void QryAndSubscribeUnitTopic(const SessionIDType& sessionID, const std::string& unitname);
protected:
	void OnRspLogin(const SessionIDType& sessionID, const LoginResponse& rsp);
	void OnRspQryUnit(const SessionIDType& sessionID, const ListUnitsResponse& rsp);
	void OnRspQryAccount(const SessionIDType& sessionID, const ListAccountResponse& rsp);
	void OnRspQryAndSubscribeUnitTopic(const SessionIDType& sessionID, const SubscribeUnitResponse& rsp);
	
	void OnRtnTopicNofity(const SessionIDType& sessionID, const TopicNotify& topic, std::shared_ptr<apache::thrift::protocol::TCompactProtocol> proto);

private:
	IOBase* m_IO;
	SessionIDType m_LoginSessionID;
	std::map<std::string, GroceryInfo> m_AddressServices;
	std::map<SessionIDType, GroceryInfo> m_SessionServices;

	std::map<SessionIDType, TopicDecoder*> m_SessionDecoders;

	std::string m_UserID;
	std::string m_Password;
	Buffer<BuffSize * 10> m_Buffer;
};

