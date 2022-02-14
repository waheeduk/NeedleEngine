#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vec2
{
public:
	float x;
	float y;
	Vec2(float x, float y);
	Vec2(int x, int y);
	Vec2() {
		x = 0;
		y = 0;
	}

	Vec2 operator+(const Vec2& rhs);
	bool operator==(const Vec2& rhs);
	Vec2 operator*(const Vec2& rhs);
	//TO DO:
	// += -= *= /= / != NORMALISE
	Vec2& scale(float scale);
	Vec2& add(float val);

	float distance(const Vec2& rhs);

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

	void print();
};

#endif
