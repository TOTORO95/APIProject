#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC _hdc)=0;
	virtual void Release() = 0;
	void UpdateRect();
	void CalcAngle(INFO _info);

protected:
	int m_iDef;
	INFO m_tInfo;
	INFO m_tAimInfo;
	bool m_bDead;
	RECT m_tRect;
	float m_fSpeed;

};

