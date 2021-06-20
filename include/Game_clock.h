#pragma once
#include <SFML/Graphics.hpp>
#include "../include/All_animation/Textures.h"
using namespace std;
using namespace sf;

class Game_clock
{
public:
	Game_clock();
	bool update_time();
	void draw(sf::RenderTarget& target) const;
	void start_clock() { m_clock.restart(); m_counter = seconds(0.f);}
	void pause() { m_clock2.restart(); }
	void start() { m_counter += m_clock2.getElapsedTime(); }
private:
	Time m_counter = seconds(0.f);
	Text m_text;
	Clock m_clock = Clock(), m_clock2 = Clock();
};