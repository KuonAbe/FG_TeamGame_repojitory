#include "GameOver.h"

GameOver::GameOver()
{
	//画像ロード
	GameOver_Tex = LoadGraph("GameOver.png");
	//画像のポジション用
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void GameOver::Init()
{
}

void GameOver::Update()
{
	//シーン遷移処理
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_RETURN))
	{
		scene_Manager->Change_Scene(scene_Manager->TITLE);
	}

}

void GameOver::Draw()
{
	//ゲームオーバー画像表示
	DrawGraph(tex_Pos_X, tex_Pos_Y, GameOver_Tex, TRUE);
}

void GameOver::Finish()
{

}

GameOver::~GameOver()
{
}
