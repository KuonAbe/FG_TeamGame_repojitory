#include "Title.h"

Title::Title()
{
	//�^�C�g�����[�h�p
	title_Tex = LoadGraph("title_Tex.png");
	//�摜�̃|�W�V�����p
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void Title::Init()
{
	title_Tex = LoadGraph("title_Tex.png");
	//�摜�̃|�W�V�����p
	tex_Pos_X = 0;
	tex_Pos_Y = 0;
}

void Title::Update()
{
	//�V�[���J�ڗp����
	keyInput.Update();
	if (keyInput.InputKeyTrigger(KEY_INPUT_SPACE))
	{
		scene_Manager->Change_Scene(scene_Manager->STAGE1);
	}
}

void Title::Draw()
{
	//�^�C�g���摜�\��
	DrawGraph(tex_Pos_X, tex_Pos_Y, title_Tex, TRUE);
}

void Title::Finish()
{

}

Title::~Title()
{
}
