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

	//int vectlX, vectlY;
	//if (std::abs(player_PosX - ground_Block_PosX) < 64 / 2 + 64 / 2 &&
	//	std::abs(player_PosY + 64 - ground_Block_PosY) < 64 / 2 + 64 / 2)
	//{
	//	vectlX = player_PosX - ground_Block_PosX;
	//	vectlY = player_PosY +64 - ground_Block_PosY;
	//	if (std::abs(vectlX) < std::abs(vectlY))
	//	{
	//		if (vectlY < 0)
	//		{
	//			//ã‚©‚ç‚Ì“–‚½‚è”»’è
	//			return true;
	//		}
	//	}
	//}

	//int vectlX, vectlY;
	//if (std::abs(player_Pos_X - ground_Block_Pos_X) < 64 / 2 + 64 / 2 &&
	//	std::abs(player_Pos_Y + 64 - ground_Block_Pos_Y) < 64 / 2 + 64 / 2)
	//{
	//	vectlX = player_Pos_X - ground_Block_Pos_X;
	//	vectlY = player_Pos_Y + 64 - ground_Block_Pos_Y;
	//	if (std::abs(vectlX) < std::abs(vectlY))
	//	{
	//		if (vectlY < 0)
	//		{

	//		}
	//		else
	//		{
	//			return true;
	//		}
	//	}
	//}

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

	if (player_Pos_X+138 >= enemy_Pos_X && 
		player_Pos_X <= enemy_Pos_X + 138 &&
		player_Pos_Y+192 <= enemy_Pos_Y &&
		player_Pos_Y >= enemy_Pos_Y+192)
	{
		return true;
	}
}