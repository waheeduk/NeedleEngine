#pragma once

#include <cmath>

namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;

	inline bool Zero(float val, float effectiveZero = 0.001f)
	{
		if (fabs(val) <= effectiveZero)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}