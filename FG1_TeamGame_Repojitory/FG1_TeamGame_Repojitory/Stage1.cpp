#include "Stage1.h"

Stage1::Stage1()
{

	//プレイヤーの生成
	player_Pos_X = 100;
	player_Pos_Y = 705;
	player.Init(player_Pos_X, player_Pos_Y);
	enemys[0] = Enemy(1000, 705);
	enemys[1] = Enemy(1500, 705);
	for (int i = 0; i < 2; i++)
	{
		enemys[i].Init();
	}

	stage1_DayTime.Init();
	stage1_Ground.Init();
}

void Stage1::Init()
{

}

void Stage1::Update()
{

	for (int i = 0; i < 2; i++)
	{
		player.Update(enemys[i].enemy_pos_X,enemys[i].enemy_pos_Y);
		player.Player_HP(enemys[i].Enemy_isAttack());
		enemys[i].Update(player.GetPlayer_Pos_X(), player.GetPlayer_Pos_Y());
	}
	stage1_DayTime.Update();
	stage1_Ground.Update();

	//プレイヤーが死んだら
	if (player.Player_isDead() == true)
	{
		//ゲームオーバーシーンに切り替わる
		//scene_Manager->Change_Scene(scene_Manager->GAMEOVER);
	}
	
	for (int i = 0; i < 2; i++)
	{
		//敵が全部死んだら		
		if (enemys[0].Enemy_isDead() == true&&
			enemys[1].Enemy_isDead()==true)
		{
			//クリアシーンに切り替わる
			//scene_Manager->Change_Scene(scene_Manager->CLEAR);
		}
	}
	//
}

void Stage1::Draw()
{
	stage1_DayTime.Draw();
	stage1_Ground.Draw();
	player.Draw();

	for (int i = 0; i < 2; i++)
	{
		enemys[i].Draw();
	}
}

void Stage1::Finish()
{
	player.Finish();
	stage1_DayTime.Finish();
	stage1_Ground.Finish();
}

Stage1::~Stage1()
{
}
