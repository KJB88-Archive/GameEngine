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
	Vector3(const Vector3&);
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


	//// Operators
	//inline Vector3 operator=(const Vector3);
	//inline Vector3 operator+(const Vector3);
	//inline Vector3 operator-(const Vector3);
	//inline Vector3 operator*(const float);
	//inline Vector3 operator/(const float);
	//inline bool operator==(const Vector3);
	//inline bool operator!=(const Vector3);
	/*inline ostream& operator<<(ostream& o, const Vector4& vec)
	{
		o << "[" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "]" << endl;
		return o;
	}*/

private:
};

