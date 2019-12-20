#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Relese() = 0;
	void UpdateRect();
	bool IsDead() { return m_bIsDead; };
	void SetPos(float _x, float _y) { m_tInfo.fPosX = _x, m_tInfo.fPosY = _y; };
	void SetSize(float _x, float _y) { m_tInfo.fSizeX = _x, m_tInfo.fSizeY = _y; };
protected:
	Info m_tInfo;
	RECT m_tRect;
	float m_fSpeed;
	bool m_bIsDead;
};

