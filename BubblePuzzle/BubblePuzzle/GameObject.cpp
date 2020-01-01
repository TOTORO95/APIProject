#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
{

}


CGameObject::~CGameObject()
{

}
void CGameObject::UpdateRect()
{
	m_tRect.left = GetInfo().fPosX - GetInfo().fCX*0.5f;
	m_tRect.right = GetInfo().fPosX + GetInfo().fCX*0.5f;
	m_tRect.top= GetInfo().fPosY - GetInfo().fCY*0.5f;
	m_tRect.bottom = GetInfo().fPosY + GetInfo().fCY*0.5f;
}

void CGameObject::CalcAngle(INFO _info)
{

	m_tAimInfo.fPosX = cosf(_info.fPosX - GetInfo().fPosX);
	m_tAimInfo.fPosY = sinf(_info.fPosY - GetInfo().fPosY);


}

bool CGameObject::Isdead()
{
	return m_bDead;
}

void CGameObject::DefalutInit()
{
	m_bDead = false;
	m_tInfo.fCX = 50;
	m_tInfo.fCY = 50;
	m_fSpeed = 5.f;
	memset(&m_tAimInfo, 0, sizeof(INFO));
	m_bTarget = false;
}

void CGameObject::SetPos(float _x, float _y)
{
	m_tInfo.fPosX = _x;
	m_tInfo.fPosY = _y;
}

void CGameObject::SetSize(float _cx, float _cy)
{
	m_tInfo.fCX = _cx;
	m_tInfo.fCY = _cy;

}
