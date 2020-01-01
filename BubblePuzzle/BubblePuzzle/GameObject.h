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

	RECT GetWinRect() const { return m_tWinRect; }
	void SetWinRect(RECT val) { m_tWinRect = val; }
public:
	void DefalutInit();
	void UpdateRect();
	void CalcAngle(INFO _info);
	bool Isdead();

public:
	INFO GetInfo() const { return m_tInfo; }
	void SetInfo(INFO val) { m_tInfo = val; }
	void SetPos(float _x,float _y );
	void SetSize(float _cx, float _cy);
	void SetDead(bool val) { m_bDead = val; }
	INFO GetTargetINFO() const { return m_tAimInfo; }
	void SetTargetINFO(INFO val) { m_tAimInfo = val; }
	Object_type GetObjType() const { return m_ObjectType; }
	void SetObjType(Object_type val) { m_ObjectType = val; }

	float GetRadian() const { return m_fRadian; }
	void SetRadian(float val) { m_fRadian = val; }
	bool GetTarget() const { return m_bTarget; }
	void SetTarget(bool val) { m_bTarget = val; }

protected:
	Object_type m_ObjectType;
	RECT m_tWinRect;
	INFO m_tInfo;
	INFO m_tAimInfo;
	RECT m_tRect;
	HBRUSH Brush, oBrush;
	bool m_bDead;
	float m_fSpeed;
	float m_fAngle;
	float m_fRadian;
	bool m_bTarget;

};

