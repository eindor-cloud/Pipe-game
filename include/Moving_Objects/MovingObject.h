#pragma once
#include "Object.h"
#include "../include/All_animation/Animation.h"
#include "../include/All_animation/Resources.h"

class Chicken;
class MovingObject : public Object
{
public:
	MovingObject(Vector2f loc = { 0,0 }, b2World* m_world = nullptr, const AnimationData& data = Resources::instance().animationData(Resources::Ball));
	
	virtual void update(sf::Time delta) {};
	virtual void move_back();
	virtual void step_to_dir();
	virtual float double_jump() { return toVector(m_dir).y * 2;};

protected:
	Animation m_animation;
	float m_speed = 1.0f;
};

