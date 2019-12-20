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
	m_tRect.left =	m_tInfo.fPosX - (m_tInfo.fSizeX*0.5);
	m_tRect.right=	m_tInfo.fPosX + (m_tInfo.fSizeX*0.5);
	m_tRect.top=	m_tInfo.fPosY - (m_tInfo.fSizeY*0.5);
	m_tRect.bottom= m_tInfo.fPosY + (m_tInfo.fSizeY*0.5);

}

