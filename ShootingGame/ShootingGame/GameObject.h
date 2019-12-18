#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;
	void UpdateRect();
	void SetPos(float _x,float _y);
	bool GetDead() { return m_bDead; };

	Info GetInfo() { return m_tPos; };
	RECT GetRect() { return m_Rect; };
protected:
	Info m_tPos;
	RECT m_Rect;
	float m_fSpeed;
	bool m_bDead;
};

