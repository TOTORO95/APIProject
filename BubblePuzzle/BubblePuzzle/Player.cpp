#include "stdafx.h"
#include "Player.h"
#include "Block.h"


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

	SetObjType(PLAYER);
	
	
}

int CPlayer::Update()
{
	if (m_bDead == DEAD_OBJ)
		return DEAD_OBJ;
	m_fRadian = m_fAngle/180 * PI;
	m_tAimInfo.fPosX = m_tInfo.fPosX +cosf(m_fRadian)* 100;
	m_tAimInfo.fPosY = m_tInfo.fPosY + sinf(m_fRadian)* 100;

	InputKey();


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
	// 0x0000: Ű�� �������� ����.
	// 0x0001: ������ ���Ⱦ���.
	// 0x8000: ���� �������� ������ �ȴ�����.
	// 0x8001: ���絵 �������� ������.

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fAngle-= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fPosX += (m_tAimInfo.fPosX - m_tInfo.fPosX) / 100;
		m_tInfo.fPosY += (m_tAimInfo.fPosY - m_tInfo.fPosY) / 100;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fAngle += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fPosX -= (m_tAimInfo.fPosX - m_tInfo.fPosX) / 100;
		m_tInfo.fPosY -= (m_tAimInfo.fPosY - m_tInfo.fPosY) / 100;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_pBlock = new CBlock(m_tInfo,m_tAimInfo);
		m_pBlock->Initialize();
		
	}
}

