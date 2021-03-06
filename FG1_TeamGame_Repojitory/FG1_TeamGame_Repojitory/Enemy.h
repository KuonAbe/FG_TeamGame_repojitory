#pragma once
#include<DxLib.h>
#define Enemy_SIZE 64
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#include"Collision.h"
#include"Stage1_DayTime.h"

class Enemy
{
private:
	bool isEnemy_Dead;
	bool Direction;
	int enemy_Left_Tex;//エネミー左向き
	int enemy_Right_Tex;//エネミー右むき

	enum Enemy_Draw_Direction {
		RIGHT,//右向き
		LEFT,//左向き
		ATTACK,//攻撃
	};
	Enemy_Draw_Direction enemy_Draw_Direction;

public:

	//プレイヤー情報受取用
	int enemyClass_player_Pos_X;//プレイヤーの位置受取用
	int enemyClass_player_Pos_Y;//プレイヤーの位置受取用
	int player_Pos_Y;

	//エネミー用変数
	int enemy_pos_X;
	int enemy_pos_Y;
	int velocity_X;//エネミー移動量
	int velocity_Y;//エネミー移動量

	int enemy_Attack_Count;//エネミー多段ヒット防止用

	Enemy();
	Enemy(int enemy_Pos_X, int enemy_Pos_Y);
	~Enemy();

	void Init();
	void Update(int player_Pos_X, int player_Pos_Y);
	bool Enemy_isAttack();
	bool Enemy_isDead();
	void Draw();
	void Finish();

	Collision collision;
	Stage1_DayTime stage1_DayTime;
};
