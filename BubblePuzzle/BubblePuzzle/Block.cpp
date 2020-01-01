#include "stdafx.h"
#include "Block.h"


CBlock::CBlock()
{
}

CBlock::CBlock(INFO _playerinfo, INFO _taiminfo)
{
	SetPos(_playerinfo.fPosX, _playerinfo.fPosY);
	DefalutInit();
}


CBlock::~CBlock()
{

}

void CBlock::Initialize()
{
	m_fSpeed = 5.0f;

}

int CBlock::Update()
{
	if (Isdead() == DEAD_OBJ)
		return DEAD_OBJ;


	return ALLIVE_OBJ;
}

void CBlock::Render(HDC _hdc)
{
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBlock::Release()
{
}

void CBlock::Move()
{
	m_tInfo.fPosX += m_tAimInfo.fPosX;
	m_tInfo.fPosY += m_tAimInfo.fPosY;
}

