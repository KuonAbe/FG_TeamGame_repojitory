#pragma once
#include<DxLib.h>
#include"Base_Scene.h"
#include"Scene_manager.h"
#include"Input.h"

class Clear :public Base_Scene
{
private:
	//画像ロード用
	int Clear_Tex;
	//画像ポジション用
	int tex_Pos_X;
	int tex_Pos_Y;
public:
	Clear();
	~Clear();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Finish() override;

	Input keyInput;
	Scene_Manager* scene_Manager;
};

