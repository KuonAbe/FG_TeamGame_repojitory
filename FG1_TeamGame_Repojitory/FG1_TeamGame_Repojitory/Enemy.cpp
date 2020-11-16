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
	enemy_Right_Tex = LoadGraph("Villager.png");
	enemy_Left_Tex = LoadGraph("Villager.png");
}

void Enemy::Update(int player_Pos_X, int player_Pos_Y)
{
	this->enemyClass_player_Pos_X = player_Pos_X;
	this->enemyClass_player_Pos_Y = player_Pos_Y;

	velocity_Y = 3;

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
	
	//if (enemy_pos_X <= player_Pos_X)
	//{
	//	isEnemy_Dead = true;
	//}

	//エネミーとプレイヤーの当たり判定
	if (collision.Enemy_Collision(
		enemy_pos_X, enemy_pos_Y,
		enemyClass_player_Pos_X, 
		enemyClass_player_Pos_Y) == true)
	{
		//エネミーがプレイヤーに当たったら
		
	}

	//プレイヤーの位置確認用
	DrawFormatString(1000, 400, (255, 255, 255), "player_Pos_X:%d",enemyClass_player_Pos_X);
	DrawFormatString(1000, 500, (255, 255, 255), "player_Pos_X:%d", enemyClass_player_Pos_Y);

	if (enemy_pos_Y >= SCREEN_HEIGHT - 378)
	{
		velocity_Y = 0;
	}

	enemy_pos_Y += velocity_Y;
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
			DrawExtendGraph(//エネミー右向き
				enemy_pos_X,
				enemy_pos_Y,
				enemy_pos_X + 139,
				enemy_pos_Y + 193,
				enemy_Right_Tex,
				TRUE);
			break;
		case Enemy_Draw_Direction::LEFT:
			DrawExtendGraph(//エネミー右向き
				enemy_pos_X,
				enemy_pos_Y,
				enemy_pos_X + 139,
				enemy_pos_Y + 193,
				enemy_Left_Tex,
				TRUE);
			break;
		case Enemy_Draw_Direction::ATTACK:
			//エネミーの攻撃アニメーション
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

