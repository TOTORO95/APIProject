#pragma once
class CDetectManager
{
public:
	static void DetectEnemy(GameList _destlist, GameList _srclist);

private:
	static bool DetectPatten1(CGameObject* _destobj, CGameObject *_srcobj);


};

