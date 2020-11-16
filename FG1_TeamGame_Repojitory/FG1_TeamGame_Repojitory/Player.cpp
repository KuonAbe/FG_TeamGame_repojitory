#include "Player.h"

Player::Player()
{
}

void Player::Init(int player_Pos_X, int player_Pos_Y)
{

	//�v���C���[�p������
	this->player_Pos_X = player_Pos_X;
	this->player_Pos_Y = player_Pos_Y;
	velocity_X = 0;//�ړ��ʖ���
	velocity_Y = 0;//�ړ��ʏd�͕�
	isPlayer_Dead = false;//����ł��Ȃ�
	player_Draw_Direction = RIGHT;//�����͉E����
	//HPBar�p�ϐ�
	HPbar_Cr = GetColor(255, 0, 0);//HPbar�̐F
	HPbar_PosX = player_Pos_X - 32;
	HPbar_PosY = player_Pos_Y - 26;
	HPbar_Size_X = 112;
	HPbar_Size_Y = 16;
	HPgage_Count = 0;
	//�v���C���[�e�N�X�`�����[�h
	player_Left_Tex = LoadGraph("Dracula.png");//�v���C���[������
	player_Right_Tex = LoadGraph("Dracula.png");//�v���C���[�E����
	player_HPbar_Tex = LoadGraph("HPbar_frame.png");
	player_HP_icon_Tex = LoadGraph("Blood_icon.png");

	enemy_bool = false;
}

void Player::Update()
{
	//�v���C���[�̈ړ���
	velocity_X = 0;
	velocity_Y = 3;

	//�v���C���[�̍s������
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		//�L�[��A����������
		velocity_X = -10;
		player_Draw_Direction = RIGHT;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		//�L�[��D����������
		velocity_X = 10;
		player_Draw_Direction = LEFT;
	}
	if (player_Pos_Y >= SCREEN_HEIGHT - 378)
	{
		velocity_Y = 0;
	}
	HPbar_PosX = player_Pos_X - 32;
	HPbar_PosY = player_Pos_Y - 26;
	player_Pos_X = player_Pos_X + velocity_X;
	player_Pos_Y = player_Pos_Y + velocity_Y;

	//�v���C���[�̍U������


	//�v���C���[�̎��S����
	if (HPbar_Size_X < 0)
	{
		isPlayer_Dead = true;
	}
}

//void Player::Player_recovery(bool enemy_bool)
//{
//	this->enemy_bool = enemy_bool;
//}

void Player::Player_HP(bool enemy_isAttack)
{
	this->beAttacked = enemy_isAttack;
	//�v���C���[�̃Q�[�W����
	HPgage_Count += 1;
	if (HPgage_Count > 10)
	{
		HPbar_Size_X--;
		HPgage_Count = 0;
	}
	if (beAttacked == true)
	{
		HPbar_Size_X -= 10;
		beAttacked = false;
	}
}

bool Player::Player_isDead()
{
	if (isPlayer_Dead == true)
	{
		return true;
	}
}

void Player::SetPlayer_Pos_X(int player_Pos_X)
{
	this->player_Pos_X = player_Pos_X;
}

void Player::SetPlayer_Pos_Y(int player_Pos_Y)
{
	this->player_Pos_Y = player_Pos_Y;
}

void Player::Draw()
{
	DrawGraph(//HPbar�̃t���[��
		HPbar_PosX,
		HPbar_PosY,
		player_HPbar_Tex,
		TRUE);
	DrawGraph(//HP�̃A�C�R��
		player_Pos_X + 80,
		player_Pos_Y - 26,
		player_HP_icon_Tex,
		TRUE);
	DrawBox(
		HPbar_PosX,
		HPbar_PosY,
		HPbar_PosX + HPbar_Size_X,
		HPbar_PosY + HPbar_Size_Y,
		HPbar_Cr, TRUE);

	//�v���C���[�̃A�j���[�V����
	switch (player_Draw_Direction)
	{
	case Player_Draw_Direction::RIGHT:
		DrawExtendGraph(//�v���C���[�E����
			player_Pos_X,
			player_Pos_Y,
			player_Pos_X+97,
			player_Pos_Y+193,
			player_Right_Tex,
			TRUE);
		break;

	case Player_Draw_Direction::LEFT:
		DrawExtendGraph(//�v���C���[������
			player_Pos_X,
			player_Pos_Y,
			player_Pos_X + 97,
			player_Pos_Y + 193,
			player_Left_Tex,
			TRUE);
		break;
	case Player_Draw_Direction::ATTACK:
		//ATTACK�A�j���[�V����
		break;
	case Player_Draw_Direction::TIMESKIP:
		//TimeSkip�A�j���[�V����
		break;
	case Player_Draw_Direction::DEAD:
		//Dead�A�j���[�V����

		break;
	}
}

void Player::Finish()
{

}

Player::~Player()
{
}
