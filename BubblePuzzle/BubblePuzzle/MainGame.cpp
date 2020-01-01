#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Block.h"
CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{

	GetClientRect(g_hWnd, &m_WinRect);
	m_hdc = GetDC(g_hWnd);	
	m_pObjList[PLAYER].push_back(AbsFactory<CPlayer>::CreateObj(m_WinRect));

	//SetPos(m_WinRect.right*0.5f, m_WinRect.bottom*0.95f);


	//m_pPlayer = new CPlayer;
	//m_pPlayer->Initialize();
	//m_pPlayer->SetPos(m_WinRect.right*0.5f, m_WinRect.bottom*0.95f);



}

int CMainGame::Update()
{
	for (int i = 0;i<END_OBJTYPE;i++)
	{
		auto itr_Begin = m_pObjList[i].begin();
		auto itr_End = m_pObjList[i].end();
		for (itr_Begin; itr_Begin != itr_End;)
		{
			if ((**itr_Begin).GetObjType() == PLAYER && (**itr_Begin).Isdead()== DEAD_OBJ)
				return DEAD_OBJ;
			
			(**itr_Begin).Update();
			itr_Begin++;

		}
	}



	//m_pPlayer->Update();
	return ALLIVE_OBJ;

}

void CMainGame::Render()
{
	Rectangle(m_hdc, m_WinRect.left, m_WinRect.top, m_WinRect.right,m_WinRect.bottom);
	for (int i = 0; i < END_OBJTYPE; i++)
	{
		auto itr_Begin = m_pObjList[i].begin();
		auto itr_End = m_pObjList[i].end();
		for (itr_Begin; itr_Begin != itr_End;)
		{
			(**itr_Begin).Render(m_hdc);
			itr_Begin++;
		}
	}
	//m_pPlayer->Render(m_hdc);
	//m_pObjList[PLAYER].
}

void CMainGame::Release()
{
	for (int i = 0; i < END_OBJTYPE; i++)
	{
		auto itr_Begin = m_pObjList[i].begin();
		auto itr_End = m_pObjList[i].end();
		for (itr_Begin; itr_Begin != itr_End;)
		{
			(**itr_Begin).Release();
			delete m_pPlayer;
			m_pPlayer = nullptr;

			itr_Begin++;
		}
	}



}

