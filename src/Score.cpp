#pragma once
#include "Score.h"

Score::Score()
{
	m_sprite.setTexture(Textures::instance().get_Textures(GOAL_CELEBRATION));
	m_sprite.setPosition(Vector2f(0, 100));
}

bool Score::draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
	m_sprite.move(1, 0);
	if (m_sprite.getPosition().x >= 450) { 
		m_sprite.setPosition(Vector2f(0, 100));
		return true;
	}
	return false;
}