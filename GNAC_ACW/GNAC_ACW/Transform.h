#pragma once
#include "Vector3.h"

class Transform
{
public:

	Transform();
	Transform(Vector3 pos);
	Transform(Vector3 pos, Vector3 rot);
	Transform(Vector3 pos, Vector3 rot, Vector3 scale);
	~Transform();

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void SetParent(Transform* newParent);
	Transform* GetParent();

private:

	Transform* parent;
};