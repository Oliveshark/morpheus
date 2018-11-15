#pragma once

#include <cstdlib>

class IdGenerator
{
	private:
		size_t nextId = 1;

	public:
		size_t next();
};
