#include "Stage1_ground.h"

Stage1_ground::Stage1_ground()
{

}

void Stage1_ground::Init()
{
	ground_Block1_Tex = LoadGraph("ground.png");
}

void Stage1_ground::Update()
{
	//�}�b�v�`�b�v�ǂݍ���
	for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			//�v���C���[�ƃu���b�N�̓����蔻��
			if (collision.Block_Collision_Up(
				w * BLOCK_SIZE,
				h * BLOCK_SIZE,
				player.GetPlayer_Pos_X(),
				player.GetPlayer_Pos_Y()) == true)
			{
				player.SetPlayer_Pos_Y(h * BLOCK_SIZE - 64);
				//player.SetPlayer_Pos_Y(100);896
			}
		}
	}

}

void Stage1_ground::Draw()
{
	//�}�b�v�`�b�v�ǂݍ���
	for (int w = 0; w < MAP_WIDTH; w++)
	{
		for (int h = 0; h < MAP_HEIGHT; h++)
		{
			//groundBlock�̓ǂݍ���
			if (Stage1_mapChip_Ground[h][w] == 01)
			{
				DrawGraph(
					w * BLOCK_SIZE,
					h * BLOCK_SIZE,
					ground_Block1_Tex,
					TRUE);
			}
		}
	}

}

void Stage1_ground::Finish()
{

}
Stage1_ground::~Stage1_ground()
{
}
