#include "Vector3.h"

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
