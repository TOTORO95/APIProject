#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual int Update()=0;
	virtual void Initialize() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;
	const Info GetInfo()const { return m_tInfo; };
	const RECT GetRect()const { return m_tRect; };
	void SetPos(float _x, float _y) { m_tInfo.fX = _x, m_tInfo.fY = _y; };
	void ISDead() { m_bISDead = true; };
protected:
	bool m_bISDead;
	void UpdateRect();
	Info m_tInfo;
	RECT m_tRect;
	float m_fSpeed;

};

