#pragma once
#include "Board.h"

class Score
{
public:
	Score();
	void Run(sf::RenderTarget& target);
	bool draw(sf::RenderTarget& target);

private:
	Sprite m_sprite;
};