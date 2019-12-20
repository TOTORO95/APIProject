#pragma once
class CMainGame
{
public:
	CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Render();
	~CMainGame();

private:
	list<CGameObject*> m_pGameList[OBJECT_END];
	HDC m_hdc;
	
};

