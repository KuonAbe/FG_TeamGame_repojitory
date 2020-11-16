#pragma once
#include<DxLib.h>
#include"Base_Scene.h"
#include"Scene_Manager.h"
#include"Stage1_ground.h"
#include"Player.h"
#include"Enemy.h"
#include"Stage1_DayTime.h"

class Stage1 :public Base_Scene
{
private:
	//プレイヤー用変数
	int player_Pos_X;
	int player_Pos_Y;

	//エネミー用変数
	int enemy_Pos_X;//エネミーのポジション入力用
	int enemy_Pos_Y;//エネミーのポジション入力用


	//昼用

	//夜用


public:
	Stage1();
	~Stage1();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Finish()override;

	//マップチップ
	Stage1_ground stage1_Ground;
	Stage1_DayTime stage1_DayTime;
	//プレイヤー
	Player player;

	//エネミー
	Enemy enemy_01;
	Enemy enemy_02;
	
	Enemy enemys[2];
	//enemys = new Enemy[2];

	Scene_Manager* scene_Manager;
};

