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
	m_Rect.left =	LONG(m_tPos.fX - m_tPos.fCX * 0.5f);
	m_Rect.top	=	LONG(m_tPos.fY - m_tPos.fCY * 0.5f);
	m_Rect.right=	LONG(m_tPos.fX + m_tPos.fCX * 0.5f);
	m_Rect.bottom=	LONG(m_tPos.fY + m_tPos.fCY * 0.5f);
	
}

void CGameObject::SetPos(float _x,float _y)
{
	m_tPos.fX = _x;
	m_tPos.fY = _y;
}
