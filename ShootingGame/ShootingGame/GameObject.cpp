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
	m_Rect = { m_tPos.fX - m_tPos.fCX*0.5,
			m_tPos.fY - m_tPos.fCY*0.5,
			m_tPos.fX + m_tPos.fCX*0.5,
			m_tPos.fY - m_tPos.fCY*0.5
	};
}

void CGameObject::SetPos(float _x,float _y)
{
	m_tPos.fX = _x;
	m_tPos.fY = _y;
}
