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
	SetPos(50, 50);
	SetSize(50, 50);
	m_fSpeed = 5.0f;
	m_bDead = false;
	SetTargetINFO(m_tInfo);

	m_fAngle = -90;
}

int CPlayer::Update()
{
	if (m_bDead == DEAD_OBJ)
		return DEAD_OBJ;
	m_fRadian = m_fAngle/180 * PI;
	m_fX = cosf(m_fRadian);
	m_fY = sinf(m_fRadian);
	m_tAimInfo.fPosX = m_tInfo.fPosX + cosf(m_fRadian) * 100;
	m_tAimInfo.fPosY = m_tInfo.fPosY + sinf(m_fRadian) * 100;

	InputKey();

	//cout << "X=" << m_tInfo.fPosX << " Y=" << m_tInfo.fPosY << endl;

	return ALLIVE_OBJ;
}
void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(_hdc, m_tInfo.fPosX, m_tInfo.fPosY, nullptr);
	LineTo(_hdc, m_tAimInfo.fPosX, m_tAimInfo.fPosY);
}


void CPlayer::Release()
{
}

void CPlayer::InputKey()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fAngle-= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fPosX +=m_fX ;
		m_tInfo.fPosY += m_fY;
		//m_tInfo.fPosY -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fAngle += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fPosX -= m_fX;
		m_tInfo.fPosY -= m_fY;

	}
}

