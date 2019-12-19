#pragma once
#ifndef __GAMEROUTINE_H__

class CGameObject;
class CGameRoutine
{
public:
	CGameRoutine();
	~CGameRoutine();
	void Initialize();
	int Update();
	void Render();
	void Release();
private:
	//CGameObject* m_pPlayer;
	//list<CGameObject*> m_pMonsterList;
	HDC m_hWnd;
	list<CGameObject*> m_objectList[OBJECT_END];
};

#define __GAMEROUTINE_H__
#endif // !__GAMEROUTINE_H__
