#include "stdafx.h"
#include "Block.h"


CBlock::CBlock()
{
}


CBlock::CBlock(INFO _playerinfo, INFO _taiminfo)
{
	SetPos(_playerinfo.fPosX, _playerinfo.fPosY);

}

CBlock::~CBlock()
{

}

void CBlock::Initialize()
{
	m_fSpeed = 5.0f;
	m_iColor = BLOCK_TYPE( rand() % END_BLOCK);
	cout << m_iColor<< endl;
	memset(&m_tAimInfo, 0, sizeof(m_tInfo));
	m_bTarget = false;

}

int CBlock::Update()
{
	if (Isdead() == DEAD_OBJ)
		return DEAD_OBJ;
	Move();
	UpdateRect();


	return ALLIVE_OBJ;
}

void CBlock::Render(HDC _hdc)
{
	MyRGB tempCol;
	switch (m_iColor)
	{
	case RED:
		tempCol = { 255,0,0 };
		SetColor(_hdc, tempCol);
		break;
	case BLUE:
		tempCol = { 0,0,255 };
		SetColor(_hdc, tempCol);

		break;
	case YELLOW:
		tempCol = { 100,100,0 };
		SetColor(_hdc, tempCol);

		break;
	case WHILE:
		tempCol = { 255,255,255 };
		SetColor(_hdc, tempCol);
		break;
	case END_BLOCK:
		break;
	default:
		break;
	}

	
	

}


void CBlock::Release()
{
}

void CBlock::Move()
{
	if (m_bTarget)
	{
		if (m_tInfo.fPosX < 0 + m_tInfo.fCX*0.5|| m_tInfo.fPosX > 800 - m_tInfo.fCX*0.5)
		{
			m_fAngle = m_fRadian *180 / PI;

			cout << GetRadian() << endl;
			m_fAngle = 180 - m_fAngle;
			SetRadian(m_fAngle / 180 * PI);
			
		}
		cout <<"천장 높이"<< m_tWinRect.top<<endl;
		if (m_tInfo.fPosY <= m_tWinRect.top+m_tInfo.fCY*0.5)
			m_bTarget = false;
		m_tAimInfo.fPosX = GetInfo().fPosX + cosf(GetRadian()) * 100;
		m_tAimInfo.fPosY = GetInfo().fPosY + sinf(GetRadian()) * 100;
		cout << GetRadian() << endl;
		m_tInfo.fPosX += (m_tAimInfo.fPosX - GetInfo().fPosX)/50;
		m_tInfo.fPosY += (m_tAimInfo.fPosY - GetInfo().fPosY)/50;
	}
}

void CBlock::SetColor(HDC _hdc,MyRGB _color )
{
	Brush = CreateSolidBrush(RGB(_color.R, _color.G, _color.B));
	oBrush = (HBRUSH)SelectObject(_hdc, Brush);
	Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(_hdc, oBrush);

}

