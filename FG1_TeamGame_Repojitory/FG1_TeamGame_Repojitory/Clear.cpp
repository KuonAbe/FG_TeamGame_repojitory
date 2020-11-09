#include "Clear.h"

Clear::Clear()
{
	//画像ロード
	Clear_Tex = LoadGraph("Clear.png");
	//画像のポジション用
	tex_Pos_X = 0;
	tex_Pos_Y = 0;

}

void Clear::Init()
{
}

void Clear::Update()
{
	//シーン遷移処理
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_RETURN))
	{
		scene_Manager->Change_Scene(scene_Manager->TITLE);
	}
}

void Clear::Draw()
{
	//クリア画像表示
	DrawGraph(tex_Pos_X, tex_Pos_Y, Clear_Tex, TRUE);
}


void Clear::Finish()
{

}

Clear::~Clear()
{

}
