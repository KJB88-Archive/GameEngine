#pragma once
#pragma once

class Vector4
{

public:

	// Constr / destr
	// Creates a Vector3 with zeroed xyzw values
	Vector4();

	// Creates a vector3 with the given xyzw values
	Vector4(float x, float y, float z, float w);

	// Creates a vector3 with the same xyzw component as the given vector3
	Vector4(const Vector4&);
	~Vector4();

	float x;
	float y;
	float z;
	float w;

private:
};

