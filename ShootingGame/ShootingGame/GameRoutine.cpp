#include "stdafx.h"
#include "GameRoutine.h"
#include "Player.h"
#include "Monster.h"
void CGameRoutine::Initialize()
{
	srand((unsigned int)time(NULL));
	m_HDC = GetDC(g_hWnd);
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	//auto vMonstersItr = m_pMonsters.begin();
	//if ( m_pMonsters.empty())
	//{
	//
	//	for (int i = 0; i < 4; i++)
	//	{ 
	//		float x = rand() % 1198;
	//		float y = rand() % 350;
	//		CMonster *temp = new CMonster;
	//		temp->Initialize();
	//		temp->SetPos(x, y);
	//		m_pMonsters.push_back(temp);
	//	}
	//}
	float x = rand() % 1198;
	float y = rand() % 350;
	m_pMonster = new CMonster;
	m_pMonster->Initialize();
	m_pMonster->SetPos(x, y);

}

void CGameRoutine::Update()
{
	CPlayer *temp = dynamic_cast<CPlayer*>(m_pPlayer);

	//auto mon = m_pMonsters.begin();
	//for (mon; mon != m_pMonsters.end();)
	//{
	//	if ((*mon) == nullptr)
	//	{
	//		mon=m_pMonsters.erase(mon);
	//		continue;
	//	}
	//	(*mon)->Update();
	//	mon++;
	//}
	if (m_pMonster != nullptr && m_pMonster->GetDead())
	{
		delete m_pMonster;
		m_pMonster = nullptr;
	}
	if (m_pMonster != nullptr)
	{
		m_pMonster->Update();
		temp->SetTarget(m_pMonster);
	}
	m_pPlayer->Update();
	
}

void CGameRoutine::Render()
{
	Rectangle(m_HDC, 0, 0, 1248, 1024);
	//for (auto& mon : m_pMonsters)
	//{
	//	if(mon==nullptr)
	//		continue;

	//	mon->Render(m_HDC);

	//}
	if(m_pMonster!= nullptr)
		m_pMonster->Render(m_HDC);
	m_pPlayer->Render(m_HDC);
}

void CGameRoutine::Release()
{
}

CGameRoutine::CGameRoutine()
{
}


CGameRoutine::~CGameRoutine()
{
}

