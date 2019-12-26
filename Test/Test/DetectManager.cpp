#include "stdafx.h"
#include "DetectManager.h"
#include "GameObject.h"
#include "Monster.h"




//TODO: ���� �Ѿ��� ������Ʈ ��ü�� �������� ���θ����
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
	//���̰� ���������պ��� ũ�� �浹X  ������O
	float fSumX = _destobj->GetInfo().fSizeX*0.7f + _srcobj->GetInfo().fSizeX*0.7f;

	float fdistX = fabs(_destobj->GetInfo().fPosX - _srcobj->GetInfo().fPosX);
	if (fdistX <= fSumX )
		return true;
	
	return false;
}

