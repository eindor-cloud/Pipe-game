#pragma once
#include "Object.h"
#include <iostream>
#include "Collision.hpp"
#include "../include/Moving_Objects/Ball.h"

Object::Object(Vector2f loc)
{
	m_sprite.setPosition(loc);
    m_firstloc = loc;
}

//======================================================
/*function to check if mouse is on object */
bool Object::collide_with(const Object& other)
{
    return Collision::PixelPerfectTest(this->m_sprite, other.m_sprite);
}
//----------------------------------------------------------------------------
void Object::move_to_start()
{
    m_sprite.setPosition(m_firstloc);
    m_body->SetAwake(false);
    m_body->SetTransform(b2Vec2(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y),0);
    m_body->SetAwake(true);
    if (typeid(this) == typeid(Ball))
        m_body->ApplyForce(b2Vec2(0, 3500000), b2Vec2(m_sprite.getPosition().x, Board_Height - m_sprite.getPosition().y), true);

}