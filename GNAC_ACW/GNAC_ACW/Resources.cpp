#include "Resources.h"
#include "Graphics.h"

Resources::Resources()
	: Manager("Resources")
{

}

Resources::~Resources() 
{

}

Mesh* Resources::CreateMesh(std::string fileName)
{
	// Load mesh in from file
	// Create mesh
	//Mesh* mesh = new Mesh(0, "Square");
	//Graphics::CreateVBO(); // TODO
	// Get Graphics to create VBO
	// Check if valid
	// Return to caller
	return NULL;
}

bool Resources::GetMesh(std::string assetName, Mesh& outMesh)
{
	// Loop through assets
	// Compare names
	// If valid, assign to outMesh, return true
	// If invalid, return false
	return false;
}

bool Resources::GetMesh(const int id, Mesh& outMesh)
{
	// Loop through assets
	// Compare ids
	// If valid, assign to outMesh, return true
	// If invalid, return false

	return false;
}


