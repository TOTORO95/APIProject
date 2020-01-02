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
	SetTargetINFO(GetInfo());
	m_fAngle = 180;
	SetBlock(nullptr);
	SetObjType(PLAYER);


}

int CPlayer::Update()
{
	if (m_bDead == DEAD_OBJ)
		return DEAD_OBJ;
	SetRadian(m_fAngle / 180 * PI);
	m_tAimInfo.fPosX = GetInfo().fPosX + cosf(GetRadian()) * 100;
	m_tAimInfo.fPosY = GetInfo().fPosY + sinf(GetRadian()) * 100;
	InputKey();
	if ((dynamic_cast<CBlock*>(m_pBlock))->GetIsSet())
	{
		//m_pBlock = nullptr;
	}
	return ALLIVE_OBJ;
}
void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(_hdc, GetInfo().fPosX, GetInfo().fPosY, nullptr);
	LineTo(_hdc, m_tAimInfo.fPosX, m_tAimInfo.fPosY);

}


void CPlayer::Release()
{
}

void CPlayer::InputKey()
{
	// 0x0000: 키가 눌려있지 않음.
	// 0x0001: 이전에 눌렸었음.
	// 0x8000: 현재 눌렸지만 이전엔 안눌렸음.
	// 0x8001: 현재도 이전에도 눌렸음.

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fAngle -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fPosX += (m_tAimInfo.fPosX - GetInfo().fPosX) / 100;
		m_tInfo.fPosY += (m_tAimInfo.fPosY - GetInfo().fPosY) / 100;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fAngle += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fPosX -= (m_tAimInfo.fPosX - GetInfo().fPosX) / 100;
		m_tInfo.fPosY -= (m_tAimInfo.fPosY - GetInfo().fPosY) / 100;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (m_pBlock != nullptr && !m_pBlock->GetTarget())
		{
			m_pBlock->SetRadian(m_fRadian);
			m_pBlock->SetTarget(true);
		}
	}

}

