#pragma once
#include<DxLib.h>
#include<string>
#include"Base_Scene.h"
#include"Scene_Manager.h"
#include"Input.h"

class Title :public Base_Scene
{
private:
	int title_Tex;
	//画像ポジション用
	int tex_Pos_X;
	int tex_Pos_Y;

public:
	Title();
	~Title();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Finish()override;

	Input keyInput;
	Scene_Manager* scene_Manager;
};

