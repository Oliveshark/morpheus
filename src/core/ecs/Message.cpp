#include "Message.h"

MessageType Message::getType() const
{
	return type;
}

MessageData* Message::getData()
{
	return &data;
}
