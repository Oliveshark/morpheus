#pragma once

#include <ECS.h>
#include "Update.h"
#include "Message.h"

typedef uint32_t EntityID;

class Entity : public ECS::Entity<Update, Message>
{
	private:
		EntityID id;

	public:
		Entity();
		EntityID getId() const;
};
