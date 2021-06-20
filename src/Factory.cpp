#pragma once
#include "Factory.h"
#include "Object.h"


std::unique_ptr<Object> Factory::create( char name, Vector2f loc, b2World* world, bool dir=false) {
	auto it = Factory::getMap().find(name);
	if (it == Factory::getMap().end())
		return nullptr;
	return it->second(loc,world,dir);
}

bool Factory::registerit(char name, pFnc f) {
	Factory::getMap().emplace(name, f);
	return true;
}