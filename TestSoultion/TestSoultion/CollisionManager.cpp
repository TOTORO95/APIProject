#include "stdafx.h"
#include "CollisionManager.h"
#include "GameObject.h"
#include "Player.h"
void CCollisionManager::CollisionRect(list<CGameObject*> _destlist, list<CGameObject*> _srclist)
{
	for (auto& destItem : _destlist)
	{
		float fDestLeft =	destItem->GetRect().left;
		float fDestRight =	destItem->GetRect().right;
		float fDestTop =	destItem->GetRect().top;
		float fDestBottom = destItem->GetRect().bottom;

		for (auto& srcItem : _srclist)
		{
			RECT colArea;
			float fSrcLeft =	srcItem->GetRect().left;
			float fSrcRight =	srcItem->GetRect().right;
			float fSrcTop =		srcItem->GetRect().top;
			float fSrcBottom =	srcItem->GetRect().bottom;
			destItem->SetIsLeft	(false);
			destItem->SetIsRight(false);
			destItem->SetIsTop	(false);
			destItem->SetIsBottom(false);

			bool bHorizonCol=false;
			bool bVerticalCol=false;

			//수평검사
			if ((fDestLeft<=fSrcRight)&&(fDestRight>=fSrcLeft))
			{
				colArea.left = (fDestLeft > fSrcLeft) ? fDestLeft : fSrcLeft;
				colArea.right= (fDestRight> fSrcRight) ? fSrcRight: fDestRight;
				bHorizonCol = true;
			}
			
			//수직검사
			if ((fDestTop<=fSrcBottom) &&(fDestBottom>=fSrcTop))
			{

				colArea.top = max(fDestTop, fSrcTop);
				colArea.bottom = min(fDestBottom,fSrcBottom);
				bVerticalCol = true;
			}
			
			if (bVerticalCol&&bHorizonCol)
			{
				if (fDestLeft >= fSrcLeft)
					destItem->SetIsLeft(true);
				else
					destItem->SetIsRight(true);

				if (fDestTop <= fSrcTop)
					destItem->SetIsBottom(true);
				else
					destItem->SetIsTop(true);

			}

		}
	}
}

void CCollisionManager::CollsionSphere(list<CGameObject*> _destlist, list<CGameObject*> _srclist)
{
	fo1r (auto& destItem : _destlist)
	{
		for (auto& srcItem : _srclist)
		{
			if (IntersectSphere(destItem, srcItem))
			{
				destItem->ISDead();
				srcItem->ISDead();

			}
		}
	}
}

CCollisionManager::CCollisionManager()
{

}


CCollisionManager::~CCollisionManager()
{
}

bool CCollisionManager::IntersectSphere(CGameObject * _destItem, CGameObject * _srcItem)
{
	float r1 = _destItem->GetInfo().fSizeX / 2;
	float r2 = _srcItem->GetInfo().fSizeX / 2;

	float w = _destItem->GetInfo().fX - _srcItem->GetInfo().fX;
	float h = _destItem->GetInfo().fY - _srcItem->GetInfo().fY;
	float d = sqrtf(w*w + h*h);
	return r1 + r2 >= d;

	
}

