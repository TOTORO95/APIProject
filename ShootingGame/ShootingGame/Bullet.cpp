#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Initialize()
{

}

void Bullet::Initialize(float _x, float _y)
{
	SetPos(_x, _y- 65);
	m_tPos.fCX = 30;
	m_tPos.fCY = 30;
	m_fSpeed = 5.f;
}

int Bullet::Update()
{
	UpdateRect();
	m_tPos.fY -= m_fSpeed;

	//CheckCollide();
	return 0;
}

void Bullet::Render(HDC _hdc)
{

	Ellipse(_hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
}

void Bullet::CheckCollide(CGameObject * _pcgo)
{
	float fTPDistance = pow(abs(_pcgo->GetInfo().fX - GetInfo().fX), 2) +
		pow(abs(_pcgo->GetInfo().fY - GetInfo().fY), 2);

	if (fTPDistance <= (GetInfo().fCX + GetInfo().fCY))
	{
        	_pcgo->Release();
		Release();
	}
}

void Bullet::Release()
{
}
