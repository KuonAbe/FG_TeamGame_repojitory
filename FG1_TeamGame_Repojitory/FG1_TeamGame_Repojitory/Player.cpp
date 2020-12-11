#include "Player.h"

Player::Player()
{
}

void Player::Init(int player_Pos_X, int player_Pos_Y)
{
	//
	//プレイヤー用初期化
	this->player_Pos_X = player_Pos_X;
	this->player_Pos_Y = player_Pos_Y;
	velocity_X = 0;//移動量無し
	velocity_Y = 0;//移動量重力分
	isPlayer_Dead = false;//死んでいない
	Player_L = true;//初期は右向き
	player_Draw_Direction = WAIT_L;//初期は待機
	//HPBar用変数
	HPbar_Cr = GetColor(255, 0, 0);//HPbarの色
	HPbar_PosX = player_Pos_X - 32;
	HPbar_PosY = player_Pos_Y - 26;
	HPbar_Size_X = 112;
	HPbar_Size_Y = 16;
	HPgage_Count = 0;
	//プレイヤーテクスチャロード
	player_Left_Tex = LoadGraph("Dracula_L.png");//待機左向き
	player_Right_Tex = LoadGraph("Dracula_R.png");//待機右向き
	player_Jump_L_Tex = LoadGraph("Dracula_Jump_L.png");//ジャンプ左向き
	player_Jump_R_Tex = LoadGraph("Dracula_Jump_R.png");//ジャンプ右向き	
	player_Attack_L_Tex = LoadGraph("Dracula_Attack_L.png");//攻撃左向き
	player_Attack_R_Tex = LoadGraph("Dracula_Attack_R.png");//攻撃右向き
	player_Run_L_Tex = LoadGraph("Dracula_Run_L.png");//左向き
	player_Run_R_Tex = LoadGraph("Dracula_Run_R.png");//右向き
	player_HPbar_Tex = LoadGraph("HPbar_frame.png");
	player_HP_icon_Tex = LoadGraph("Blood_icon.png");

	enemy_bool = false;
}

void Player::Update(int enemy_Pos_X, int enemy_Pos_Y)
{
	this->playerClass_enemy_Pos_X = enemy_Pos_X;
	this->playerClass_enemy_Pos_Y = enemy_Pos_Y;
	DrawFormatString(1000, 300, (255, 255, 255), "enemy_Pos_X:%d", playerClass_enemy_Pos_X);
	DrawFormatString(1000, 315, (255, 255, 255), "enemy_Pos_Y:%d", playerClass_enemy_Pos_Y);

	//プレイヤーの移動量
	velocity_X = 0;
	velocity_Y = 3;


	player_Draw_Direction = WAIT_L;

	//プレイヤーの行動処理
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		//キーのAを押したら
		velocity_X = -10;
		Player_L = true;
		player_Draw_Direction = RUN_L;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		//キーのDを押したら
		velocity_X = 10;
		player_Draw_Direction = RUN_R;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		if (Player_L)
		{
			player_Draw_Direction = JUMP_L;
		}
		else
		{
			player_Draw_Direction = JUMP_R;
		}

	}

	if (player_Pos_Y >= SCREEN_HEIGHT - 378)
	{
		velocity_Y = 0;
	}
	HPbar_PosX = player_Pos_X - 32;
	HPbar_PosY = player_Pos_Y - 26;
	player_Pos_X = player_Pos_X + velocity_X;
	player_Pos_Y = player_Pos_Y + velocity_Y;

	//プレイヤーの攻撃処理


	//プレイヤーの死亡処理
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
	//プレイヤーのゲージ処理
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
	DrawGraph(//HPbarのフレーム
		HPbar_PosX,
		HPbar_PosY,
		player_HPbar_Tex,
		TRUE);
	DrawGraph(//HPのアイコン
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

	//プレイヤーのアニメーション
	switch (player_Draw_Direction)
	{
	case Player_Draw_Direction::WAIT_R:
		DrawExtendGraph(//プレイヤー右向き
			player_Pos_X,
			player_Pos_Y,
			player_Pos_X + 97,
			player_Pos_Y + 193,
			player_Right_Tex,
			TRUE);
		break;

	case Player_Draw_Direction::WAIT_L:
		DrawExtendGraph(//プレイヤー左向き
			player_Pos_X,
			player_Pos_Y,
			player_Pos_X + 97,
			player_Pos_Y + 193,
			player_Left_Tex,
			TRUE);
		break;
	case Player_Draw_Direction::ATTACK_L:
		//ATTACKアニメーション
		DrawExtendGraph(//プレイヤー左向き
			player_Pos_X,
			player_Pos_Y,
			player_Pos_X + 97,
			player_Pos_Y + 193,
			player_Left_Tex,
			TRUE);
		break;
	case Player_Draw_Direction::TIMESKIP:
		//TimeSkipアニメーション
		break;
	case Player_Draw_Direction::DEAD:
		//Deadアニメーション

		break;
	}
}

void Player::Finish()
{

}

Player::~Player()
{
}
