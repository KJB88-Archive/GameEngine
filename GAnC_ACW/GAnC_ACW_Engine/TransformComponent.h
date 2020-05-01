#pragma once
#include "Vector3.h"
#include "BaseComponent.h"

class TransformComponent 
	: public BaseComponent
{
public:

	TransformComponent(Entity* owner);
	virtual ~TransformComponent();

	Vector3 position;
	Vector3 futurePosition;

	Vector3 rotation;
	//Vector3 futureRotation;

	Vector3 scale;

private:

};