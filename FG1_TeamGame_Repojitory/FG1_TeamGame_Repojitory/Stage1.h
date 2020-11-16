#pragma once
#include<DxLib.h>
#include"Base_Scene.h"
#include"Scene_Manager.h"
#include"Stage1_ground.h"
#include"Player.h"
#include"Enemy.h"
#include"Stage1_DayTime.h"

class Stage1 :public Base_Scene
{
private:
	//�v���C���[�p�ϐ�
	int player_Pos_X;
	int player_Pos_Y;

	//�G�l�~�[�p�ϐ�
	int enemy_Pos_X;//�G�l�~�[�̃|�W�V�������͗p
	int enemy_Pos_Y;//�G�l�~�[�̃|�W�V�������͗p


	//���p

	//��p


public:
	Stage1();
	~Stage1();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Finish()override;

	//�}�b�v�`�b�v
	Stage1_ground stage1_Ground;
	Stage1_DayTime stage1_DayTime;
	//�v���C���[
	Player player;

	//�G�l�~�[
	Enemy enemy_01;
	Enemy enemy_02;
	
	Enemy enemys[2];
	//enemys = new Enemy[2];

	Scene_Manager* scene_Manager;
};

