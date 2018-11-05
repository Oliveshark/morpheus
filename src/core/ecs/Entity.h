#pragma once

#include <ECS.h>
#include "Update.h"

typedef uint32_t EntityID;

class Entity : public ECS::Entity<Update, std::string>
{
	private:
		EntityID id;

	public:
		Entity();
		EntityID getId() const;
};
