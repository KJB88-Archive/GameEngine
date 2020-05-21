#pragma once
class Vector3
{

public:

	// Constr / destr
	// Creates a Vector3 with zeroed xyz values
	Vector3();

	// Creates a vector3 with the given xyz values
	Vector3(float x, float y, float z);

	// Creates a vector3 with the same xyz component as the given vector3
	Vector3(const Vector3& other);

	~Vector3();

	float x;
	float y;
	float z;

	// Static properties
	static const Vector3 zero;
	static const Vector3 left;
	static const Vector3 right;
	static const Vector3 down;
	static const Vector3 up;
	static const Vector3 back;
	static const Vector3 forward;

	void normalized();
	float Magnitude() const;

	static Vector3 Normalize(const Vector3 value);
	static float Dot(const Vector3& first, const Vector3& second);
	static Vector3 Cross(const Vector3& first, const Vector3& second);

	// Operators
	Vector3& operator=(const Vector3& other)
	{
		if (this == &other) return *this;

		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	Vector3& operator+(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vector3& operator+(const float val)
	{
		x += val;
		y += val;
		z += val;

		return *this;
	}

	Vector3& operator-(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vector3& operator-(const float val)
	{
		x -= val;
		y -= val;
		z -= val;

		return *this;
	}

	Vector3& operator*(const float val)
	{
		x *= val;
		y *= val;
		z *= val;

		return *this;
	}

	Vector3& operator*(const double val)
	{
		x *= val;
		y *= val;
		z *= val;

		return *this;
	}

	//Vector3& operator*(const Vector3& other)
	//{
	//	x *= other.x;
	//	y *= other.y;
	//	z *= other.z;

	//	return *this;
	//}

	Vector3& operator/(const float val)
	{
		x /= val;
		y /= val;
		z /= val;

		return *this;
	}

	bool operator==(const Vector3& other)
	{
		if (x == other.x &&
			y == other.y &&
			z == other.z)
		{
			return true;
		}

		return false;
	}

	bool operator!=(const Vector3& other)
	{
		if (x != other.x || y != other.y || z != other.z)
		{
			return true;
		}

		return false;
	}
};