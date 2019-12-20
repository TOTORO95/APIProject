#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	cout << "»èÁ¦" << endl;
}

void CBullet::Initialize()
{
	m_fSpeed = 10.0f;
	SetSize(10, 30);
}

int CBullet::Update()
{
	if (IsDead() == DEAD_OBJ)
		return DEAD_OBJ;
	if (m_tInfo.fPosY <= -10 || m_tInfo.fSizeY>=850)
	{
		m_bIsDead = DEAD_OBJ;
		return DEAD_OBJ;
	}

	m_tInfo.fPosY -= m_fSpeed;
	return Alive_OBJ;
}

void CBullet::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Relese()
{
}
