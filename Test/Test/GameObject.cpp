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

void CGameObject::RenderHP(HDC _hdc)
{
	//x,y ÁÂÇ¥  <m_tInfo.fSizeX> 
	Rectangle(_hdc, m_tRect.left, m_tInfo.fPosY + m_tInfo.fSizeY*0.5+20,
				m_tRect.right, m_tInfo.fPosY + m_tInfo.fSizeY*0.5 + 40);
	float fHpRatio = (float)m_HP / (float)m_MaxHP;
	if ( fHpRatio>=0.35f)
	{
		HBRUSH greenBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, greenBrush);
		//hp bar 
		Rectangle(_hdc, m_tRect.left,
			m_tInfo.fPosY + m_tInfo.fSizeY*0.5 + 20,
			(m_tRect.right - m_tRect.left)*fHpRatio + m_tRect.left,
			m_tInfo.fPosY + m_tInfo.fSizeY*0.5 + 40);
		SelectObject(_hdc, oldBrush);
		DeleteObject(greenBrush);
	}
	else
	{
		HBRUSH  redBrush= (HBRUSH)CreateSolidBrush(RGB(255,0 , 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, redBrush);
		//hp bar 
		Rectangle(_hdc, m_tRect.left,
			m_tInfo.fPosY + m_tInfo.fSizeY*0.5 + 20,
			(m_tRect.right - m_tRect.left)*fHpRatio + m_tRect.left,
			m_tInfo.fPosY + m_tInfo.fSizeY*0.5 + 40);
		SelectObject(_hdc, oldBrush);
		DeleteObject(redBrush);
	}
}

