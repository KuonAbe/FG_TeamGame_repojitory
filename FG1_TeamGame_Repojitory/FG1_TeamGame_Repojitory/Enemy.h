#pragma once
#include<DxLib.h>
#define PLAYER_SIZE 64

class Enemy
{
private:
	bool isEnemy_Dead;
	bool Direction;
	int enemy_Left_Tex;//�G�l�~�[������
	int enemy_Right_Tex;//�G�l�~�[�E�ނ�

	enum Enemy_Draw_Direction {
		RIGHT,
		LEFT,
	};
	Enemy_Draw_Direction enemy_Draw_Direction;

public:

	//�v���C���[�����p
	int enemyClass_player_Pos_X;//�v���C���[�̈ʒu���p
	int player_Pos_Y;
	//�G�l�~�[�p�ϐ�
	int enemy_pos_X;
	int enemy_pos_Y;
	int velocity_X;//�G�l�~�[�ړ���
	int velocity_Y;//�G�l�~�[�ړ���

	Enemy();
	~Enemy();

	void Init(int enemy_pos_X, int enemy_Pos_Y);
	void Update(int player_Pos_X);
	bool Enemy_isDead();
	void Draw();
	void Finish();
};

