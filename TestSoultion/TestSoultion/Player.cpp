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
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 250.f;
	m_tInfo.fSizeX = 100.f;
	m_tInfo.fSizeY = 100.f;
	m_fSpeed = 5.0f;
	m_bIsLeft = false;
	m_bIsRight = false;
	m_bIsTop = false;
	m_bIsBottom = false;
}

int CPlayer::Update()
{
	KeyInput();

	return ALIVE_OBJ;
}

void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
}

void CPlayer::Release()
{
}

void CPlayer::KeyInput()
{
	// 0x0000: 키가 눌려있지 않음.
	// 0x0001: 이전에 눌렸었음.
	// 0x8000: 현재 눌렸지만 이전엔 안눌렸음.
	// 0x8001: 현재도 이전에도 눌렸음.
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) &&!m_bIsLeft)
		m_tInfo.fX -= m_fSpeed;
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)&& !m_bIsRight)
		m_tInfo.fX += m_fSpeed;
	if ((GetAsyncKeyState(VK_UP) & 0x8000)	&&!m_bIsTop)
		m_tInfo.fY -= m_fSpeed;
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)&&!m_bIsBottom)
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{

	}

}
