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

	bool GetIsLeft() { return m_bIsLeft; };
	bool GetIsRight() { return m_bIsRight; };
	bool GetIsTop() { return m_bIsTop; };
	bool GetIsBottom() { return m_bIsBottom; };

	void SetIsLeft	(bool _check)	{ m_bIsLeft		=_check; };
	void SetIsRight	(bool _check)	{ m_bIsRight	=_check; };
	void SetIsTop	(bool _check)	{ m_bIsTop		=_check; };
	void SetIsBottom(bool _check)	{ m_bIsBottom	=_check; };


protected:
	bool m_bISDead;
	void UpdateRect();
	Info m_tInfo;
	RECT m_tRect;
	float m_fSpeed;

	bool m_bIsLeft;
	bool m_bIsTop;
	bool m_bIsRight;
	bool m_bIsBottom;


};

