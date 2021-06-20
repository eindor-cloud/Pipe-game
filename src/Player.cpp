#pragma once
#include "../include/Moving_Objects/Players/Player.h"

Player::Player(Vector2f loc, b2World* m_world, bool first_player, const AnimationData& data)
    : MovingObject(Vector2f(loc.x, loc.y + Extra), m_world, data), m_foot(make_unique<Foot>(loc, m_world)), m_score(new ScoreBoard(loc.x,first_player))
{
     
	b2PolygonShape box;
	box.SetAsBox(m_sprite.getTextureRect().width/2, m_sprite.getTextureRect().height/2);
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = 0.3f;
	m_fixture = m_body->CreateFixture(&fixtureDef);

	m_startingY = m_body->GetPosition().y;

	if (first_player) make_keys<Keyboard::W, Keyboard::A, Keyboard::D, Keyboard::Space>();
    else { make_keys<Keyboard::Up, Keyboard::Left, Keyboard::Right, Keyboard::Enter>(); flip(); }
}
//========================================================================
void Player::update(sf::Time delta)
{
    m_foot.get()->update(Vector2f(m_sprite.getPosition().x + toVector(m_dir).x *2, m_sprite.getPosition().y + 30));
    
    if (Keyboard::isKeyPressed(m_kick))
    {
        kick();
    }
    if (m_dir == Direction::Stay) m_foot.get()->hide();
    if (jump_validation())
    {
        m_sprite.setPosition(m_body->GetPosition().x, Board_Height - m_body->GetPosition().y);
        update_picture(delta);
        return;
    }

    for (const auto& pair : m_keyToVectorMapping)
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            m_dir = pair.second;
            break;
        }
        m_dir = Direction::Stay;
    }

    update_picture(delta);
    step_to_dir();
    m_collide = false;
}
//========================================================================
void Player::update_picture(sf::Time delta)
{
    m_animation.direction(m_dir);
    m_animation.update(delta);
    if (m_dir == Direction::Left)
    {
        m_sprite.setScale(-1, 1);
        m_foot.get()->scale(false);
    }
    if (m_dir == Direction::Right)
    {
        m_sprite.setScale(1, 1);
        m_foot.get()->scale();
    }
}
//======================================================================
void Player::collide()
{
    m_collide = true;
}
//======================================================================

void Player::kick()
{
    m_foot.get()->show();
}
//======================================================================
bool Player::jump_validation()
{
    return (m_dir == Direction::Up && abs(m_startingY - m_body->GetPosition().y) > 3 && !m_collide);
}
//=========================================================================
void Player::add_score()
{

    m_score->add();
}