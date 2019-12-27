#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
}

int CPlayer::Update()
{
	if (m_bDead == DEAD_OBJ)
		return DEAD_OBJ;
	UpdateRect();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		
	}



	return ALLIVE_OBJ;
}
void CPlayer::Render(HDC _hdc)
{
	Ellipse(_hdc, 0, 0, 50, 50);


}


void CPlayer::Release()
{
}

