#pragma once
#include "../include/Moving_Objects/MovingObject.h"
#include <memory>
#include "../include/Moving_Objects/Players/Player.h"
class Ball : public MovingObject
{
public:
    Ball(Vector2f loc = { 0, 0 }, b2World* m_world=nullptr);
    //void direction(sf::Keyboard::Key key);
    void draw(sf::RenderTarget& target) { target.draw(m_sprite); }
    void update(Time delta);
    void move( Object& player);
    void kick_me(bool dir);
    bool scored() { return m_scored;  }
    void score() { m_scored = true; m_sprite.move(toVector(m_dir).x * 2, 0);}
    void unscore() { m_scored = false; }

private:
    bool m_scored = false;
    static bool m_registerit;
};