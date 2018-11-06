#include "Message.h"

MessageType Message::getType() const
{
	return type;
}

const MessageData* Message::getData() const
{
	return &data;
}

MessageData* Message::getData()
{
	return &data;
}
