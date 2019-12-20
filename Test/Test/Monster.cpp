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
	m_bIsDead = false;
	SetSize(80, 80);
	float fPosX = rand() % (WincX) + m_tInfo.fSizeX*0.5;
	float fPosY = rand() % WincY + m_tInfo.fSizeY*0.5;
	SetPos(fPosX,fPosY);
	m_fSpeed = 3.0f;
	cout << "Monster X=" << fPosX << " Y=" << fPosY << endl;
}

int CMonster::Update()
{
	if (IsDead())
		return DEAD_OBJ;


	return Alive_OBJ;
}

void CMonster::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Relese()
{
}
