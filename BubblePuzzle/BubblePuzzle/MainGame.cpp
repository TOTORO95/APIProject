#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{

	GetClientRect(g_hWnd, &m_WinRect);
	
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
	m_hdc = GetDC(g_hWnd);	
	m_pPlayer->SetPos(m_WinRect.right*0.5f, m_WinRect.bottom*0.95f);

}

int CMainGame::Update()
{
	if (m_pPlayer->Isdead())
		return DEAD_OBJ;

	m_pPlayer->Update();
	return ALLIVE_OBJ;

}

void CMainGame::Render()
{
	Rectangle(m_hdc, m_WinRect.left, m_WinRect.top, m_WinRect.right,m_WinRect.bottom);
	m_pPlayer->Render(m_hdc);

}

void CMainGame::Release()
{
	m_pPlayer->Release();
	delete m_pPlayer;
	m_pPlayer = nullptr;


}

