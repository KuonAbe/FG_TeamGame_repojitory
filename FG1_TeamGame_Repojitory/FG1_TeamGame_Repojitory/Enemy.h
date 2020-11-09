#pragma once
#include<DxLib.h>
#define PLAYER_SIZE 64

class Enemy
{
private:
	bool isEnemy_Dead;
	bool Direction;
	int enemy_Left_Tex;//エネミー左向き
	int enemy_Right_Tex;//エネミー右むき

	enum Enemy_Draw_Direction {
		RIGHT,
		LEFT,
	};
	Enemy_Draw_Direction enemy_Draw_Direction;

public:

	//プレイヤー情報受取用
	int enemyClass_player_Pos_X;//プレイヤーの位置受取用
	int player_Pos_Y;
	//エネミー用変数
	int enemy_pos_X;
	int enemy_pos_Y;
	int velocity_X;//エネミー移動量
	int velocity_Y;//エネミー移動量

	Enemy();
	~Enemy();

	void Init(int enemy_pos_X, int enemy_Pos_Y);
	void Update(int player_Pos_X);
	bool Enemy_isDead();
	void Draw();
	void Finish();
};

