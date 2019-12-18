#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;
	void UpdateRect();
	void SetPos(float _x,float _y);
protected:
	Info m_tPos;
	RECT m_Rect;
};

