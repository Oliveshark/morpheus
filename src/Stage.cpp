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
