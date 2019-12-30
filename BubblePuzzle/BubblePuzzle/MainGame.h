#pragma once
class CPlayer;
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
	CPlayer *m_pPlayer;
	HDC m_hdc;
	RECT m_WinRect;
};

