#pragma once
#include<iostream>
class Collision
{
private:
	int ground_Block_Pos_X;
	int ground_Block_Pos_Y;
	int player_Pos_X;
	int player_Pos_Y;
	int enemy_Pos_X;
	int enemy_Pos_Y;

public:
	bool Block_Collision_Up(
		int ground_Block_PosX,
		int ground_Block_PosY,
		int player_PosX,
		int player_PosY);

	bool Enemy_Collision(
		int enemy_PosX,
		int enemy_PosY,
		int player_PosX,
		int player_PosY);
};

