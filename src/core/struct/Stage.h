#pragma once

#include <map>
#include "../ecs/Entity.h"
#include "../ecs/Update.h"

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
		Stage() { };

		~Stage();

		void addEntity(Entity*);

		void removeEntity(EntityID);

		void update(const Update&);
};
