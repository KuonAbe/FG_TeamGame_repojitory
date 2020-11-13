#include "Clear.h"

Clear::Clear()
{
	//�摜���[�h
	Clear_Tex = LoadGraph("Clear.png");
	//�摜�̃|�W�V�����p
	tex_Pos_X = 0;
	tex_Pos_Y = 0;

}

void Clear::Init()
{
}

void Clear::Update()
{
	//�V�[���J�ڏ���
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_RETURN))
	{
		scene_Manager->Change_Scene(scene_Manager->TITLE);
	}
}

void Clear::Draw()
{
	//�N���A�摜�\��
	DrawGraph(tex_Pos_X, tex_Pos_Y, Clear_Tex, TRUE);
}


void Clear::Finish()
{

}

Clear::~Clear()
{

}
