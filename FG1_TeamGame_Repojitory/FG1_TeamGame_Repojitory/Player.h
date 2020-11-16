#pragma once
#include<DxLib.h>
#define PLAYER_SIZE 64
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

class Player
{
private:
	bool isPlayer_Dead;//����ł��邩�ǂ���

	//�v���C���[�e�N�X�`���p�ϐ�
	int player_Left_Tex;//�v���C���[������
	int player_Right_Tex;//�v���C���[�E����
	//�v���C���[��HPBar�p�ϐ�
	int player_HPbar_Tex;//�v���C���[��HP�e�N�X�`��
	int player_HP_icon_Tex;//HP�A�C�R���̃e�N�X�`��
	int HPbar_PosX;//HPBar��XPos
	int HPbar_PosY;//HPBar��YPos
	int HPbar_Size_X;//HPBar�̃T�C�Y
	int HPbar_Size_Y;//HPBar�̃T�C�Y
	int HPbar_Cr;//HPBar�̐F
	int HPgage_Count;

	//�G�l�~�[�̏��󂯂Ƃ�
	bool enemy_bool;

	//�v���C���[�A�j���[�V�����p
	enum Player_Draw_Direction {
		RIGHT,
		LEFT,
		ATTACK,
		TIMESKIP,
		DEAD,
	};
	Player_Draw_Direction player_Draw_Direction;

public:
	//�v���C���[�p�ϐ�
	int player_Pos_X;
	int player_Pos_Y;
	int velocity_X;//�v���C���[�ړ���
	int velocity_Y;//�v���C���[�ړ���
	Player();
	~Player();

	void Init(int player_Pos_X, int player_Pos_Y);
	void Update();
	bool Player_isDead();//�v���C���[�̐�����Ԃ�Ԃ�
	void Player_recovery(bool enemy_bool);
	void Player_HP();
	void Draw();
	void Finish();

	void SetPlayer_Pos_X(int player_Pos_X);
	void SetPlayer_Pos_Y(int player_Pos_Y);
	int GetPlayer_Pos_X() { return player_Pos_X; }
	int GetPlayer_Pos_Y() { return player_Pos_Y; }
	int GetPlayer_HP() { return HPbar_Size_X; }

};

