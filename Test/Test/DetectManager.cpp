#include "stdafx.h"
#include "DetectManager.h"
#include "GameObject.h"
#include "Monster.h"




//TODO: 현재 총알이 오브젝트 전체를 떄리는중 새로만들기
void CDetectManager::DetectEnemy(GameList _destlist, GameList _srclist)
{
	for (auto& destObj : _destlist)
	{
		for (auto& srcObj : _srclist)
		{
			if (DetectPatten1(destObj, srcObj))
			{
				dynamic_cast<CMonster*>(srcObj)->ShootBullet();

			}
		}
	}
}

bool CDetectManager::DetectPatten1(CGameObject * _destobj, CGameObject *_srcobj)
{
	//길이가 반지름의합보다 크면 충돌X  작으면O
	float fSumX = _destobj->GetInfo().fSizeX*0.7f + _srcobj->GetInfo().fSizeX*0.7f;

	float fdistX = fabs(_destobj->GetInfo().fPosX - _srcobj->GetInfo().fPosX);
	if (fdistX <= fSumX )
		return true;
	
	return false;
}

