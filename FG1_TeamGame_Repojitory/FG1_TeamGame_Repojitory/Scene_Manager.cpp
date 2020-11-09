#include "Scene_Manager.h"
#include"Title.h"
#include"Stage1.h"
#include"Clear.h"
#include"GameOver.h"

Base_Scene* Scene_Manager::m_pScene_1 = nullptr;

void Scene_Manager::Change_Scene(Scene scene)
{
	Scene_Manager* scene_Manager;
	if (m_pScene_1 != nullptr)
	{
		delete m_pScene_1;
	}

	switch (scene)
	{
	case Scene_Manager::TITLE:
		m_pScene_1 = new Title();
		break;
	case Scene_Manager::STAGE1:
		m_pScene_1 = new Stage1();
		break;
	case Scene_Manager::CLEAR:
		m_pScene_1 = new Clear();
		break;
	case Scene_Manager::GAMEOVER:
		m_pScene_1 = new GameOver();
		break;
	default:
		break;
	}
}

void Scene_Manager::Init()
{
	m_pScene_1->Init();
}

void Scene_Manager::Update()
{
	m_pScene_1->Update();
}

void Scene_Manager::Draw()
{
	m_pScene_1->Draw();
}

void Scene_Manager::Finish()
{
	m_pScene_1->Finish();
}