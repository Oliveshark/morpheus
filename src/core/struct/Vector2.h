#pragma once

#include <iostream>

template<typename T>
class Vector2
{
	public:
		T x, y;

		Vector2() : x(0), y(0) { };

		Vector2(T dx, T dy) : x(dx), y(dy) { };

		friend std::ostream& operator<<(std::ostream& out, const Vector2<T>& vec) {
			out << vec.x << "x" << vec.y;
			return out;
		};
};
