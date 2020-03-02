#pragma once
#include "Vector3.h"
#include "IComponent.h"

class TransformComponent : public IComponent
{
public:

	//TransformComponent();
	//TransformComponent(Vector3 pos);
	//TransformComponent(Vector3 pos, Vector3 rot);
	TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale);
	virtual ~TransformComponent();

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	// Inherited via IComponent
	virtual ComponentTypes ComponentType() override;

private:

};