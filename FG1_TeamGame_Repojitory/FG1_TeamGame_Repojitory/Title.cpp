#include "Title.h"

Title::Title()
{
	//タイトルロード用
	title_Tex = LoadGraph("title_Tex.png");
	//画像のポジション用
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void Title::Init()
{
	title_Tex = LoadGraph("title_Tex.png");
	//画像のポジション用
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void Title::Update()
{
	//シーン遷移用処理
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_SPACE))
	{
		scene_Manager->Change_Scene(scene_Manager->STAGE1);
	}
}

void Title::Draw()
{
	//タイトル画像表示
	DrawGraph(tex_Pos_X, tex_Pos_Y, title_Tex, TRUE);
}

void Title::Finish()
{

}

Title::~Title()
{
}
