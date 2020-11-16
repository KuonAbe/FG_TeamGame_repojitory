#pragma once
#include<DxLib.h>
#include"Time.h"
class Stage1_DayTime
{
private:
	//�A�Z�b�g�̃��[�h�p
	int Sun_Tex;
	int Moon_Tex;
	int night_Back_Tex;

	//���z�ƌ��̈ʒu
	int sun_Pos_X;
	int sun_Pos_Y;
	int moon_Pos_X;
	int moon_Pos_Y;
	//�ʒu�̎��Ԋ�
	enum StarPos {
		AM6,
		AM9,
		AM12,
		PM3,
		PM6,
		PM9,
		PM11,
		PM12,
		AM3,
		AM5,
	};
	StarPos starPos;

public:
	void Init();
	int Update();
	void Draw();
	void Finish();
	Time time;
};

