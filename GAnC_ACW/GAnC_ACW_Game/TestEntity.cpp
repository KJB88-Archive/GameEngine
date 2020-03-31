#include "TestEntity.h"
#include "Logger.h"

TestEntity::TestEntity(int id, std::string name)
	: Entity(id, name)
{
	// SQUARE BEGIN
	TransformComponent* transf = new TransformComponent(this);
	transf->position = Vector3(0.0f, 0.0f, 0.0f);
	AddComponent(transf);

	RenderComponent* render = new RenderComponent(this);
	AddComponent(render); // TODO

	Logger::LogToConsole("ENTITY: Entity with name " + name);
}

TestEntity::~TestEntity()
{

}