#pragma once
#include "Vector3.h"

class TransformComponent
{
public:

	TransformComponent();
	TransformComponent(Vector3 pos);
	TransformComponent(Vector3 pos, Vector3 rot);
	TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale);
	~TransformComponent();

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void SetParent(TransformComponent* newParent);
	TransformComponent* GetParent();

private:

	TransformComponent* parent;
};