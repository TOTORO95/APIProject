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
	auto bullet = m_Bullets.begin();
	for (bullet;bullet!=m_Bullets.end();)
	{
		if ((*bullet) == nullptr)
		{
			bullet = m_Bullets.erase(bullet);
			continue;
		}

		(*bullet)->Update();
		if ( (*bullet)->GetInfo().fY<= 5)
		{
			bullet = m_Bullets.erase(bullet);
			continue;
		}
		if(m_pTarget!=nullptr)
			(*bullet)->CheckCollide(m_pTarget);
		//for (auto &monster : m_pTargets)
		//{
		//	(*bullet)->CheckCollide(monster);
		//	if ((*bullet) == nullptr)
		//	{
		//		bullet = m_Bullets.erase(bullet);
		//		break;
		//	}

		//}
		

		bullet++;
	
	}
	
	return 0;
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
	// 0x0000: 키가 눌려있지 않음.
	// 0x0001: 이전에 눌렸었음.
	// 0x8000: 현재 눌렸지만 이전엔 안눌렸음.
	// 0x8001: 현재도 이전에도 눌렸음.

	if (GetAsyncKeyState(VK_LEFT)	& 0x8000)
		m_tPos.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT)	& 0x8000)
		m_tPos.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP)		& 0x8000)
		m_tPos.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN)	& 0x8000)
		m_tPos.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Bullet * temp = new Bullet;
		temp->Initialize(m_tPos.fX, m_tPos.fY);
		m_Bullets.push_back(temp);
		
	}

}

void CPlayer::Release()
{
}
