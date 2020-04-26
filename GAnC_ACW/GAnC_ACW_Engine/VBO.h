#pragma once
#include "Vertex.h"
#include <vector>
class Renderer;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create
	(Renderer* renderer, std::vector<Vertex> vertices, std::vector<int> indices) = 0;

	virtual void Draw(Renderer* renderer) = 0;
};