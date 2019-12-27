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
	CPlayer player;
	player.Initialize();
}

int CMainGame::Update()
{
	
	


	return ALLIVE_OBJ;
}

void CMainGame::Render()
{


}

void CMainGame::Release()
{
}
