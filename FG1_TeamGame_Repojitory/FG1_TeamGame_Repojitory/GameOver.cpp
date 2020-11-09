#include "GameOver.h"

GameOver::GameOver()
{
	//�摜���[�h
	GameOver_Tex = LoadGraph("GameOver.png");
	//�摜�̃|�W�V�����p
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void GameOver::Init()
{
}

void GameOver::Update()
{
	//�V�[���J�ڏ���
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_RETURN))
	{
		scene_Manager->Change_Scene(scene_Manager->TITLE);
	}

}

void GameOver::Draw()
{
	//�Q�[���I�[�o�[�摜�\��
	DrawGraph(tex_Pos_X, tex_Pos_Y, GameOver_Tex, TRUE);
}

void GameOver::Finish()
{

}

GameOver::~GameOver()
{
}
