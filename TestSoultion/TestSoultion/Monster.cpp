#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{

}


CMonster::~CMonster()
{
}

int CMonster::Update()
{
	
	return 0;
}

void CMonster::Initialize()
{
	float fRX = rand() % 700+50;
	float fRY = rand() % 600+50;
	m_tInfo.fSizeX = 100;
	m_tInfo.fSizeY = 100;

	SetPos(fRX, fRY);
}

void CMonster::Render(HDC _hdc)
{
	UpdateRect();
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}
