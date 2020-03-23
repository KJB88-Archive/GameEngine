#pragma once
#include "ISystem.h"

class PhysicsSystem
	: public ISystem
{

public:
	PhysicsSystem();
	virtual ~PhysicsSystem();

	virtual void ProcessEntities(std::vector<Entity*> entities) override;

private:

	const Component::ComponentTypes MASK =
		(Component::COMPONENT_TRANSFORM | Component::COMPONENT_PHYSICS);
};

