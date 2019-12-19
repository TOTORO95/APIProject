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
	m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fSizeX * 0.5f);
	m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fSizeX * 0.5f);
	m_tRect.top = LONG(m_tInfo.fY - m_tInfo.fSizeY * 0.5f);
	m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fSizeY * 0.5f);
}
