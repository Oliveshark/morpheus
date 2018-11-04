#include "Entity.h"

static EntityID
generateId()
{
	static EntityID nextId = 1;
	return nextId++;
}

Entity::Entity() : id(generateId())
{
	static EntityID nextId = 1;
	id = nextId++;
}

EntityID Entity::getId() const
{
	return id;
}
