#pragma once

#include <ECS.h>
#include "Update.h"

class Component : public ECS::Component<Update, std::string>
{
};
