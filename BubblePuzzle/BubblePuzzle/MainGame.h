#pragma once
class CGameObject;
class CMainGame
{

public:
	CMainGame();
	~CMainGame();
public:
	void Initialize();
	int Update();
	void Render();
	void Release();
private:
	CGameObject* m_pPlayer;
	list<CGameObject*> m_pObjList[END_OBJTYPE];
	HDC m_hdc;
	RECT m_WinRect;
};

