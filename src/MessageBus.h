#pragma once
#include <deque>
#include <vector>
#include <string>
#include <functional>

namespace Engine
{
	namespace Messages
	{
		struct Message {
			std::string msg;
			void* data;
		};

		class MessageBus {
		public:
			MessageBus() {}
			~MessageBus() {};

			void update(float dt);

			void sendMessage(std::string msgString, void* data=nullptr);
			void sendImmediateMessage(std::string msgString, void* data=nullptr);
			void registerCallback(std::function<void(Message)>* func);

		private:
			std::deque<Message> m_dMessage;
			std::vector<std::function<void(Message)>> m_vCallback;
		};
	}
}


