#include "Scene.hpp"

Scene::Scene()
	: isInitialized(false)
{}

Scene::~Scene()
{ destroy(); }

void Scene::init()
{
	if(!isInitialized)
	{
		onInit();
		isInitialized = true;
	}
}

void Scene::destroy()
{
	if(isInitialized)
	{
		onDestroy();
		isInitialized = false;
	}
}
