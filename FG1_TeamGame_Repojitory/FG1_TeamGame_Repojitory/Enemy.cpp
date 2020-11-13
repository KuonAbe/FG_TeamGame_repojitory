#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::Init(int enemy_Pos_X, int enemy_Pos_Y)
{
	this->enemy_pos_X = enemy_Pos_X;
	this->enemy_pos_Y = enemy_Pos_Y;
	isEnemy_Dead = false;
	Direction = false;
	enemy_Draw_Direction = RIGHT;
	enemy_Right_Tex = LoadGraph("Village_Human.png");
	enemy_Left_Tex = LoadGraph("Village_Human.png");
}

void Enemy::Update(int player_Pos_X)
{
	this->enemyClass_player_Pos_X = player_Pos_X;
	if (enemy_pos_X >= enemyClass_player_Pos_X)
	{
		enemy_pos_X -= 5;
		enemy_Draw_Direction = LEFT;
	}
	if (enemy_pos_X <= enemyClass_player_Pos_X)
	{
		enemy_pos_X += 5;
		enemy_Draw_Direction = RIGHT;
	}

	if (enemy_pos_X <= player_Pos_X)
	{
		isEnemy_Dead = true;
	}
}

bool Enemy::Enemy_isDead()
{
	if (isEnemy_Dead == true)
	{
		return true;
	}
}

void Enemy::Draw()
{
	if (isEnemy_Dead == false)
	{
		switch (enemy_Draw_Direction)
		{
		case Enemy_Draw_Direction::RIGHT:
			DrawGraph(enemy_pos_X,
				enemy_pos_Y - 64,
				enemy_Right_Tex,
				TRUE);
			break;
		case Enemy_Draw_Direction::LEFT:
			DrawGraph(enemy_pos_X,
				enemy_pos_Y - 64,
				enemy_Left_Tex,
				TRUE);
			break;
		}
	}
}

void Enemy::Finish()
{

}

Enemy::~Enemy()
{

}

