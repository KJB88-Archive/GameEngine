#define _USE_MATH_DEFINES
#include "Vector3.h"
#include <cmath>
#include "MathsHelper.h"
const Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::left = Vector3(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::right = Vector3(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::down = Vector3(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::up = Vector3(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::back = Vector3(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::forward = Vector3(0.0f, 0.0f, 1.0f);

Vector3::Vector3()
	:x(0.0f), y(0.0f), z(0.0f)
{

}

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{

}

Vector3::Vector3(const Vector3& vector)
	: x(vector.x), y(vector.y), z(vector.z)
{

}

Vector3::~Vector3()
{

}

void Vector3::normalized()
{
	float mag = this->Magnitude();
	x = x / mag;
	y = y / mag;
	z = z / mag;
}

float Vector3::Magnitude() const
{
	return dist(x, y, z);
}

Vector3 Vector3::Normalize(const Vector3 value)
{
	float mag = value.Magnitude();

	Vector3 newVec;

	newVec.x = value.x / mag;
	newVec.y = value.y / mag;
	newVec.z = value.z / mag;

	return value;
}

float Vector3::Dot(const Vector3& first, const Vector3& second)
{
	return first.x * second.x +
		first.y * second.y +
		first.z * second.z;
}

Vector3 Vector3::Cross(const Vector3& first, const Vector3& second)
{
	float newX = first.y * second.z - first.z * second.y;
	float newY = first.z * second.x - first.x * second.z;
	float newZ = first.x * second.y - first.y * second.x;

	return Vector3(newX, newY, newZ);
}