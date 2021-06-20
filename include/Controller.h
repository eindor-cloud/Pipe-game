#pragma once
#include "Game_clock.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Score.h"
class Controller
{
public:
	Controller();
	void Run();
	
private:
	void makeMenu();
	void new_game_or_exit();
	void draw();
	void update_object();
	void handle_events();
	Sprite m_bg, m_pause, m_music;
	bool m_isPlaying = true;
	unique_ptr<Board> m_board;
	RenderWindow m_window;
	Clock m_clock = Clock();
	Game_clock m_game_clock;
	Score m_score;
	Sound m_goal_sound;
};