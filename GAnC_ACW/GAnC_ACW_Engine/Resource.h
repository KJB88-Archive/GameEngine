#pragma once
#include <string>
enum ResourceType
{
	SHADER,
	MESH,
	TEXTURE,
	BGM,
	AUDIOCLIP
};

class Resource
{
public:

	Resource(int id, std::string name, ResourceType type)
		: m_id(id), m_name(name), m_type(type) {};
	virtual ~Resource() {};

	int GetID() const { return m_id; }
	ResourceType GetType() const { return m_type; }

private:

	int m_id;
	std::string m_name;
	ResourceType m_type;
};