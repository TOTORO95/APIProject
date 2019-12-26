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
	
	for (auto &monster : m_pGameList[MONSTER])//수정준비
	{
		dynamic_cast<CMonster*>(monster)->SetBulletList(m_pGameList[BULLET]);
	}

	dynamic_cast<CPlayer*>(m_pGameList[PLAYER].front())->SetBulletList(m_pGameList[BULLET]);
	
}

void CMainGame::Update()
{
	for (int i = 0; i < OBJECT_END; i++)
	{
		auto itrBegin = m_pGameList[i].begin();
		//auto itrEnd= m_pGameList[i].end();

		for (;itrBegin!=m_pGameList[i].end();)
		{
			(*itrBegin)->Update();
			if ((*itrBegin)->IsDead() == DEAD_OBJ)
			{
				SafeDelete((*itrBegin));
				itrBegin = m_pGameList[i].erase(itrBegin);
			}
			else
				itrBegin++;
		}
	}
	

	CCollisionManager::CollisionObstacle(m_pGameList[PLAYER], m_pGameList[MONSTER]);
	CCollisionManager::CollisionBulToObj(m_pGameList[BULLET], m_pGameList[MONSTER]);
	CCollisionManager::CollisionBulToObj(m_pGameList[BULLET], m_pGameList[PLAYER]);

	CDetectManager::DetectEnemy(m_pGameList[PLAYER], m_pGameList[MONSTER]);
}

void CMainGame::Release()
{
}

void CMainGame::Render()
{
	Rectangle(m_hdc, 0, 0, 800, 600);
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
