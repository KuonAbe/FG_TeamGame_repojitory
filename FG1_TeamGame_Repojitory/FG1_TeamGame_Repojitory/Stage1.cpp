#include "Stage1.h"

Stage1::Stage1()
{
	//プレイヤーの生成
	player_Pos_X = 60;
	player_Pos_Y = 705;
	player.Init(player_Pos_X, player_Pos_Y);

	//エネミーの生成
	enemy_Pos_X = 1000;
	enemy_Pos_Y = 705;
	enemy_01.Init(enemy_Pos_X, enemy_Pos_Y);
	enemy_Pos_X = 1500;
	enemy_Pos_Y = 705;
	enemy_02.Init(enemy_Pos_X, enemy_Pos_Y);
	stage1_DayTime.Init();
	stage1_Ground.Init();
}

void Stage1::Init()
{

}

void Stage1::Update()
{
	player.Update();
	enemy_01.Update(player.GetPlayer_Pos_X(),player.GetPlayer_Pos_Y());
	enemy_02.Update(player.GetPlayer_Pos_X(),player.GetPlayer_Pos_Y());
	stage1_DayTime.Update();
	stage1_Ground.Update();
	if (player.Player_isDead() == true)
	{
		//scene_Manager->Change_Scene(scene_Manager->GAMEOVER);
	}
	if (enemy_01.Enemy_isDead() == true &&
		enemy_02.Enemy_isDead() == true)
	{
		//scene_Manager->Change_Scene(scene_Manager->CLEAR);
	}
}

void Stage1::Draw()
{
	stage1_DayTime.Draw();
	stage1_Ground.Draw();
	player.Draw();
	enemy_01.Draw();
	enemy_02.Draw();
}

void Stage1::Finish()
{
	player.Finish();
	enemy_01.Finish();
	enemy_02.Finish();
	stage1_DayTime.Finish();
	stage1_Ground.Finish();
}

Stage1::~Stage1()
{
}
