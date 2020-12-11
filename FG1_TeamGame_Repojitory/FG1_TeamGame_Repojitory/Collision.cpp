#include "Collision.h"

bool Collision::Block_Collision_Up(
	int ground_Block_PosX,
	int ground_Block_PosY,
	int player_PosX,
	int player_PosY)
{
	this->ground_Block_Pos_X = ground_Block_PosX;
	this->ground_Block_Pos_Y = ground_Block_PosY;
	this->player_Pos_X = player_PosX;
	this->player_Pos_Y = player_PosY;

	if (player_Pos_X >= ground_Block_Pos_X &&
		player_Pos_X <= ground_Block_Pos_X + 64 &&
		player_Pos_Y <= ground_Block_Pos_Y &&
		player_Pos_Y >= ground_Block_Pos_Y - 64)
	{
		return true;
	}
}

bool Collision::Enemy_Collision(
	int enemy_PosX,
	int enemy_PosY,
	int player_PosX,
	int player_PosY)
{
	this->enemy_Pos_X = enemy_PosX;
	this->enemy_Pos_Y = enemy_PosY;
	this->player_Pos_X = player_PosX;
	this->player_Pos_Y = player_PosY;

	if (player_Pos_X + 10 >= enemy_Pos_X &&
		player_Pos_X <= enemy_Pos_X + 138 &&
		player_Pos_Y <= enemy_Pos_Y &&
		player_Pos_Y >= enemy_Pos_Y - 200)
	{
		return true;
	}
}

bool Collision::Player_Attack_Direction_Right(
	int player_PosX,
	int player_PosY,
	int enemy_PosX,
	int enemy_PosY)
{
	this->player_Pos_X = player_PosX;
	this->player_Pos_Y = player_PosY;
	this->enemy_Pos_X = enemy_PosX;
	this->enemy_Pos_Y = enemy_PosY;

	if (player_Pos_X + 139 >= enemy_Pos_X &&
		player_Pos_X + 278 <= enemy_Pos_X &&
		player_Pos_Y <= enemy_Pos_Y &&
		player_Pos_Y >= enemy_Pos_Y-200)
	{
		return true;
	}
}

bool Collision::Player_Attack_Direction_Left(
	int player_PosX,
	int player_PosY,
	int enemy_PosX,
	int enemy_PosY)
{
	this->player_Pos_X = player_PosX;
	this->player_Pos_Y = player_PosY;
	this->enemy_Pos_X = enemy_PosX;
	this->enemy_Pos_Y = enemy_PosY;

	if (player_Pos_X >= enemy_Pos_X &&
		player_Pos_X -139 <= enemy_Pos_X &&
		player_Pos_Y <= enemy_Pos_Y &&
		player_Pos_Y >= enemy_Pos_Y-200)
	{
		return true;
	}
}
