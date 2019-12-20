#include "stdafx.h"
#include "CollisionManager.h"
#include "GameObject.h"
void CCollisionManager::CollisionObstacle(GameList _destlist, GameList _srclist)
{
	float fReBoundX=0.f, fReBoundY= 0.f;
	for (auto& destObj : _destlist)
	{
		for (auto& srcObj : _srclist)
		{
			if (IntersectRectObs(destObj, srcObj, fReBoundX, fReBoundY))
			{
				float fPosX = destObj->GetInfo().fPosX;
				float fPosY = destObj->GetInfo().fPosY;
				if (fReBoundX > fReBoundY)//y만큼 이동
				{
					if (fPosY > srcObj->GetInfo().fPosY)
						destObj->SetPos(fPosX, fPosY + fReBoundY);
					else
						destObj->SetPos(fPosX, fPosY - fReBoundY);

				}
				else
				{
					if (fPosX > srcObj->GetInfo().fPosX)
						destObj->SetPos(fPosX+fReBoundX, fPosY);
					else
						destObj->SetPos(fPosX- fReBoundX, fPosY);

				}
				destObj->Beattack(1);
			}
		}
	}
}

void CCollisionManager::CollisionBulToObj(GameList _destlist, GameList _srclist)
{
	float fReBoundX = 0.f, fReBoundY = 0.f;
	for (auto& destObj : _destlist)
	{
		for (auto& srcObj : _srclist)
		{
			if (IntersectRectBulToObj(destObj, srcObj, fReBoundX, fReBoundY))
			{
				cout << "총알 충돌" << endl;
			}
		}
	}
}

bool CCollisionManager::IntersectRectObs(CGameObject * _destobj, CGameObject *_srcobj,float& _freboundx, float&_freboundy)
{
	//길이가 반지름의합보다 크면 충돌X  작으면O
	float fSumX = _destobj->GetInfo().fSizeX*0.5f + _srcobj->GetInfo().fSizeX*0.5f;
	float fSumY = _destobj->GetInfo().fSizeY*0.5f + _srcobj->GetInfo().fSizeY*0.5f;

	float fdistX = fabs(_destobj->GetInfo().fPosX - _srcobj->GetInfo().fPosX);
	float fdistY = fabs(_destobj->GetInfo().fPosY - _srcobj->GetInfo().fPosY);
	if ( fdistX <= fSumX && fdistY <=fSumY )
	{
		_freboundx = fSumX - fdistX;
		_freboundy = fSumY - fdistY;
		return true;
	}
	return false;
}

bool CCollisionManager::IntersectRectBulToObj(CGameObject * _destobj, CGameObject * _srcobj, float & _freboundx, float & _freboundy)
{
	float fSumX = _destobj->GetInfo().fSizeX*0.5f + _srcobj->GetInfo().fSizeX*0.5f;
	float fSumY = _destobj->GetInfo().fSizeY*0.5f + _srcobj->GetInfo().fSizeY*0.5f;
	float fdistX = fabs(_destobj->GetInfo().fPosX - _srcobj->GetInfo().fPosX);
	float fdistY = fabs(_destobj->GetInfo().fPosY - _srcobj->GetInfo().fPosY);

	if (fdistX <= fSumX && fdistY <= fSumY)
	{
		_destobj->SetDead(true);
		_srcobj->Beattack(1);
		cout << _srcobj->GetHP() / _srcobj->GetMaxHP() << endl;
		if (_srcobj->GetHP() <= 0)
			_srcobj->SetDead(true);


		return true;
	}
	return false;
}


