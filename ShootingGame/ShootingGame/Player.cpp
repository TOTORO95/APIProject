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
	m_tPos.fCX = 100;
	m_tPos.fCY = 100;

	m_fSpeed = 5.f;
	
}

int CPlayer::Update()
{
	KeyInput();
	
	
	return ;
}

//void CPlayer::SetTarget(vector<CGameObject*> _monsters)
//{
//	m_pTargets=_monsters;
//}

void CPlayer::SetTarget(CGameObject * _target)
{
	m_pTarget = _target;
}

void CPlayer::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);

	for (auto &bullet : m_Bullets)
		bullet->Render(_hdc);
}


void CPlayer::KeyInput()
{
	// 0x0000: Ű�� �������� ����.
	// 0x0001: ������ ���Ⱦ���.
	// 0x8000: ���� �������� ������ �ȴ�����.
	// 0x8001: ���絵 �������� ������.

	if (GetAsyncKeyState(VK_LEFT)	& 0x8000)
		m_tPos.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT)	& 0x8000)
		m_tPos.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP)		& 0x8000)
		m_tPos.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN)	& 0x8000)
		m_tPos.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE)	& 0x8000)
	{
		
	}


}

void CPlayer::Release()
{
}
