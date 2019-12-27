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
	m_tRect.left = m_tInfo.fPosX - m_tInfo.fCX;
	m_tRect.right = m_tInfo.fPosX + m_tInfo.fCX;
	m_tRect.top= m_tInfo.fPosY - m_tInfo.fCY;
	m_tRect.bottom = m_tInfo.fPosY + m_tInfo.fCY;
}

void CGameObject::CalcAngle(INFO _info)
{
	m_tAimInfo.fPosX = cosf(_info.fPosX - m_tInfo.fPosX);
	m_tAimInfo.fPosY = sinf(_info.fPosY - m_tInfo.fPosY);
}
