#include "stdafx.h"
#include "Monster.h"
#include "Bullet.h"

CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	cout << "Á×À½" << endl;
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
	InitHP(100);

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
	RenderHP(_hdc);
}

void CMonster::Relese()
{
}

void CMonster::ShootBullet()
{
	CGameObject* temp = new CBullet;
	temp->Initialize();
	temp->SetPos(m_tInfo.fPosX, m_tInfo.fPosY+m_tInfo.fSizeY*0.8);
	dynamic_cast<CBullet*>(temp)->SetSpeed(-10);
	m_pBulletList->push_back(temp);
	
}

