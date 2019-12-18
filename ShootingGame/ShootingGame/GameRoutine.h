#pragma once
#ifndef __GAMEROUTINE_H__
class CGameObject;
class CGameRoutine
{
private:
	CGameObject* m_pPlayer;
	CGameObject* m_pMonster;
	//vector<CGameObject*> m_pMonsters;
	HDC m_HDC;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	CGameRoutine();
	~CGameRoutine();
};



#define __GAMEROUTINE_H__
#endif // !__GAMEROUTINE_H__

