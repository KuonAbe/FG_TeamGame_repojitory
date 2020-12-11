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

	//エネミーの攻撃用当たり判定
	bool Enemy_Collision(
		int enemy_PosX,
		int enemy_PosY,
		int player_PosX,
		int player_PosY);

	//プレイヤーの攻撃用当たり判定右向き
	bool Player_Attack_Direction_Right(
		int player_PosX,
		int player_PosY,
		int enemy_PosX,
		int enemy_PosY);

	//プレイヤーの攻撃用当たり判定左向き
	bool Player_Attack_Direction_Left(
		int player_PosX,
		int player_PosY,
		int enemy_PosX,
		int enemy_PosY);

};

