#pragma once

#include <map>
#include "Entity.h"

class Stage
{
	private:
		std::map<EntityID, Entity*> entities;

		Stage(const Stage& stage) {
			(void) stage;
		};

		Stage& operator=(const Stage& stage) {
			(void) stage;
			return *this;
		};

	public:
		~Stage();

		void addEntity(Entity*);

		void removeEntity(EntityID);
};
