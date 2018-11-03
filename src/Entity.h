#pragma once

#include <ECS.h>
#include "Update.h"

template<typename T>
class Entity : public ECS::Entity<Update, T>
{
};
