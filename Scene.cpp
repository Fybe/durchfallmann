#include "Scene.hpp"

Scene::Scene()
	: done(false)
{}

Scene::~Scene()
{}

void Scene::setDone()
{ done = true; }

bool Scene::isDone() const
{ return done; }

