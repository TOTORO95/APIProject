#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	SetPos(300, 200);
	SetSize(100, 100);
	m_fSpeed = 5.0f;
	m_bIsDead = false;
	m_pBulletList = nullptr;
	InitHP(100);
	
}

int CPlayer::Update()
{
	if (IsDead())
		return DEAD_OBJ;
	
	InputKey();

	return Alive_OBJ;
}

void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	RenderHP(_hdc);
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
}

void CPlayer::Relese()
{

}

void CPlayer::InputKey()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_tInfo.fPosX -= m_fSpeed;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fPosY -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fPosX += m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fPosY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		cout << "shoot" << endl;
		m_pBulletList->push_back(AbsFactory<CBullet>::Create(m_tInfo.fPosX, m_tInfo.fPosY));
	
	}
}
