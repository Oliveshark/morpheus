#include <algorithm>
#include "Stage.h"

Stage::~Stage()
{
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		delete it->second;
	}
	entities.clear();
}

void Stage::addEntity(Entity *e)
{
	if (entities[e->getId()])
		delete entities[e->getId()];
	entities[e->getId()] = e;
}

void Stage::update(const Update& update)
{
	std::for_each(entities.begin(), entities.end(),
				  [&update](const std::pair<EntityID, Entity*>& pair) {
					  pair.second->update(update);
				  });
}
