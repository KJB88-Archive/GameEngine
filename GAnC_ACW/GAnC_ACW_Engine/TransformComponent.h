#pragma once
#include "Vector3.h"
#include "Component.h"

class TransformComponent 
	: public Component
{
public:

	//TransformComponent();
	//TransformComponent(Vector3 pos);
	//TransformComponent(Vector3 pos, Vector3 rot);
	TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale, Entity* entity);
	virtual ~TransformComponent();

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

private:

};