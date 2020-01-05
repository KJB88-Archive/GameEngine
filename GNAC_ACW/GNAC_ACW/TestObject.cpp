#include "TestObject.h"

TestObject::TestObject()
	: GameObject()
{
}

TestObject::TestObject(const std::string& name)
	: GameObject(name)
{
	AddComponent(new Component("Test"));
}

TestObject::TestObject(const TestObject& other)
	: GameObject(other)
{

}

TestObject::~TestObject()
{

}

void TestObject::Initialize()
{

}

void TestObject::Update()
{

}

void TestObject::Render()
{

}