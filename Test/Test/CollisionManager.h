#pragma once
class CCollisionManager
{

public:
	static void CollisionObstacle(GameList _destlist, GameList _srclist);
	static void CollisionBulToObj(GameList _destlist, GameList _srclist);
	
private:
	static bool IntersectRectObs(CGameObject* _destobj, CGameObject *_srcobj,float& _freboundx, float& _freboundy);
	static bool IntersectRectBulToObj(CGameObject* _destobj, CGameObject *_srcobj, float& _freboundx, float& _freboundy);


};

