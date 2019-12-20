#pragma once
class CGameObject;
class CCollisionManager
{


public:
	static void CollisionRect(list<CGameObject*> &_destlist, list<CGameObject*>&_srclist);
	static void CollisionSphere(list<CGameObject*> &_destlist, list<CGameObject*> &_srclist);
	CCollisionManager();
	~CCollisionManager();
private:
	static bool IntersectSphere(CGameObject* &_destItem, CGameObject* &_srcItem);


};

