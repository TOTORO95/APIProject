#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tPos.fX = 400;
	m_tPos.fY = 400;
	m_tPos.fCY = 100;
	m_tPos.fCY = 100;

	m_fSpeed = 5;
	
}

void CPlayer::Update()
{

}

void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void CPlayer::Release()
{
}
