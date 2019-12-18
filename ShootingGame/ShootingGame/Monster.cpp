#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tPos.fCX = 100;
	m_tPos.fCY = 100;
	m_fSpeed = 5.f;
	m_bDead = false;
}

int CMonster::Update()
{
	Move();
	UpdateRect();

	return 0;
}

void CMonster::Render(HDC _hdc)
{
	UpdateRect();	
	Ellipse(_hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);

}

void CMonster::Release()
{
	m_bDead = true;
}

void CMonster::Move()
{
	if ((m_tPos.fX -= m_fSpeed) <= 50)
		m_fSpeed = -5.f;
	else if ((m_tPos.fX -= m_fSpeed) > 1188)
		m_fSpeed = 5.0f;
}
