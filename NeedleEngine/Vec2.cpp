#include "Vec2.hpp"

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin) {}

Vec2::Vec2(int xin, int yin)
	: x(static_cast<float>(xin)), y(static_cast<float>(yin)) {}

Vec2 Vec2::operator+(const Vec2& rhs) { return Vec2(x + rhs.x, y + rhs.y); }
bool Vec2::operator==(const Vec2& rhs) { return (x == rhs.x) && (y == rhs.y); }
Vec2 Vec2::operator*(const Vec2& rhs) { return Vec2(x * rhs.x, y * rhs.y); }
Vec2& Vec2::scale(float scale) { x *= scale; y *= scale; return *this; }
Vec2& Vec2::add(float val) { x += val; y += val; return *this; }

float Vec2::distance(const Vec2& rhs)
{
    float xsq = powf((rhs.x - x), 2);
    float ysq = powf((rhs.y - y), 2);
    float dist = sqrt(xsq + ysq);
    return dist;
}
std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
{
    return stream << vector.x << " " << vector.y << "\n";
}
void Vec2::print()
{
    std::cout << "(" << x << " , " << y << ")" << "\n";
}
