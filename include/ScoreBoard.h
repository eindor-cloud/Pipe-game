#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class ScoreBoard
{
public:
	ScoreBoard(float loc = 0.f,bool player_number=false);
	void add();
	void draw(sf::RenderTarget& target) const;
	const int return_score ()const{ return m_score; }
private:
	Text m_text;
	int m_score=0,m_player_number=1;
};
