#pragma once
#include <vector>
#include "../include/Static_Objects/Goal.h"
#include "../include/Moving_Objects/Players/Player.h"
#include "macros.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include "CollisionHandling.h"
#include "Sounds_E.h"
using namespace std;
using namespace sf;
//Board class scan the file and build all the graphic objects

class ball;
class Chicken;
class Footballplayer;
class Nerd;
class Santa;
class Board
{
public:
	Board(char symbol1='f', char symbol2 = 'f',float g= -9.8f);
	~Board();
	bool set_Map();
	template <typename FwdIt, typename Fn>
	void for_each_pair(FwdIt begin, FwdIt end, Fn fn);
	void rebuild_Map();
	void build_map(char symbol1, char symbol2);
	void draw(RenderWindow& m_window);
	bool update_object(Clock& m_clock);
	void connect_player_to_goal(int goal,int player);
	int  return_score_leader();
private:
	int m_ball_place = 0;
	ifstream m_file;
	Vector2i m_size;
	vector<string> m_Board;
	unique_ptr<b2World> m_world;
	vector<unique_ptr<Object>> m_objects;
	
};

// STL-like algorithm to run over all pairs
template <typename FwdIt, typename Fn>
void Board::for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (auto second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}