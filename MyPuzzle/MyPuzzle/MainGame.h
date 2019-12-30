#pragma once

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
	

	HDC m_hdc;

};

