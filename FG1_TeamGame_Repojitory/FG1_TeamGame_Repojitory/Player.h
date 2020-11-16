#pragma once
#include<DxLib.h>
#define PLAYER_SIZE 64
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

class Player
{
private:
	bool isPlayer_Dead;//死んでいるかどうか

	//プレイヤーテクスチャ用変数
	int player_Left_Tex;//プレイヤー左向き
	int player_Right_Tex;//プレイヤー右向き
	//プレイヤーのHPBar用変数
	int player_HPbar_Tex;//プレイヤーのHPテクスチャ
	int player_HP_icon_Tex;//HPアイコンのテクスチャ
	int HPbar_PosX;//HPBarのXPos
	int HPbar_PosY;//HPBarのYPos
	int HPbar_Size_X;//HPBarのサイズ
	int HPbar_Size_Y;//HPBarのサイズ
	int HPbar_Cr;//HPBarの色
	int HPgage_Count;

	//エネミーの情報受けとり
	bool enemy_bool;

	//プレイヤーアニメーション用
	enum Player_Draw_Direction {
		RIGHT,
		LEFT,
		ATTACK,
		TIMESKIP,
		DEAD,
	};
	Player_Draw_Direction player_Draw_Direction;

public:
	//プレイヤー用変数
	int player_Pos_X;
	int player_Pos_Y;
	int velocity_X;//プレイヤー移動量
	int velocity_Y;//プレイヤー移動量
	Player();
	~Player();

	void Init(int player_Pos_X, int player_Pos_Y);
	void Update();
	bool Player_isDead();//プレイヤーの生死状態を返す
	void Player_recovery(bool enemy_bool);
	void Player_HP();
	void Draw();
	void Finish();

	void SetPlayer_Pos_X(int player_Pos_X);
	void SetPlayer_Pos_Y(int player_Pos_Y);
	int GetPlayer_Pos_X() { return player_Pos_X; }
	int GetPlayer_Pos_Y() { return player_Pos_Y; }
	int GetPlayer_HP() { return HPbar_Size_X; }

};

