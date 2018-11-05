#pragma once

#include "../struct/Vector2.h"

enum MessageType
{
	MSG_POSITION_UPDATE,
	MSG_DEFAULT
};

union MessageData
{
	Vector2<int> position;
};

class Message
{
	private:
		const MessageType type;
		MessageData data{};

	public:
		Message(MessageType t) : type(t) { };

		MessageType getType() const;

		MessageData* getData();
};
