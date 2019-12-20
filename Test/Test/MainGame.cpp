#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

CMainGame::CMainGame()
{
}

void CMainGame::Initialize()
{
	srand((unsigned int)time(nullptr));
	m_hdc = GetDC(g_hWnd);
	//CGameObject *temp = new CPlayer; 
	//temp->Initialize();
	//m_pGameList[PLAYER].push_back(temp);
	m_pGameList[PLAYER].push_back(AbsFactory<CPlayer>::Create());
	for (int i = 0; i < 3; i++)
		m_pGameList[MONSTER].push_back(AbsFactory<CMonster>::Create());
}

void CMainGame::Update()
{
	for (int i = 0; i < OBJECT_END; i++)
	{
		for (auto &object : m_pGameList[i])
		{
			object->Update();
		}
	}
}

void CMainGame::Release()
{
}

void CMainGame::Render()
{
	for (int i = 0; i < OBJECT_END; i++)
	{
		for (auto &object : m_pGameList[i])
		{
			object->Render(m_hdc);
		}
	}

}


CMainGame::~CMainGame()
{
}
