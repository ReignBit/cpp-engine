
#include "MessageBus.h"

using namespace Engine::Messages;

void MessageBus::sendMessage(std::string msgString, void* data)
{
	Message msg;
	msg.msg = msgString;
	if (data)
	{
		msg.data = data;
	}
	m_dMessage.push_back(msg);
}

void MessageBus::sendImmediateMessage(std::string msgString, void* data)
{
	Message msg;
	msg.msg = msgString;
	if (data)
	{
		msg.data = data;
	}
	m_dMessage.push_front(msg);
}

void MessageBus::registerCallback(std::function<void(Message)>* func)
{
	m_vCallback.push_back(std::bind(*func, std::placeholders::_1));
}

void MessageBus::update(float dt)
{
	if (m_dMessage.size() > 0)
	{
		for (std::function<void(Message)> func : m_vCallback)
		{
			func(m_dMessage.front());
			m_dMessage.pop_front();
		}
	}
}