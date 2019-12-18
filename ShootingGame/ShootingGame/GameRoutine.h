#pragma once
#ifndef __GAMEROUTINE_H__
class CGameObject;
class CGameRoutine
{
private:
	CGameObject* m_pPlayer;

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

