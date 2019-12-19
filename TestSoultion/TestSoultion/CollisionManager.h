#pragma once
class CGameObject;
class CCollisionManager
{
//TODO: Creating CollsionManager
public:
	static void CollisionRect(list<CGameObject*> _destlist, list<CGameObject*> _srclist);
	static void CollsionSphere(list<CGameObject*> _destlist, list<CGameObject*> _srclist);
	CCollisionManager();
	~CCollisionManager();
private:
	static bool IntersectSphere(CGameObject* _destItem, CGameObject* _srcItem);
};

