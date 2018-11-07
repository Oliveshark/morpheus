#pragma once

template<typename T>
class Dimension
{
	public:
		T w, h;

		Dimension(T dw, T dh) : w(dw), h(dh) { };
		Dimension() : Dimension(0, 0) { };
};
