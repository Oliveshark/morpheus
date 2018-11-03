#pragma once

#include <ECS.h>
#include "Update.h"

template<typename T>
class Component : public ECS::Component<Update, T>
{
};
