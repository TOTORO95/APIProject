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

public:
	void DefalutInit();
	void UpdateRect();
	void CalcAngle(INFO _info);
	bool Isdead();

public:
	void SetPos(float _x,float _y );
	void SetSize(float _cx, float _cy);
	void SetDead(bool val) { m_bDead = val; }
	INFO GetTargetINFO() const { return m_tAimInfo; }
	void SetTargetINFO(INFO val) { m_tAimInfo = val; }
	Object_type GetObjType() const { return m_ObjectType; }
	void SetObjType(Object_type val) { m_ObjectType = val; }

protected:
	Object_type m_ObjectType;
	INFO m_tInfo;
	INFO m_tAimInfo;
	bool m_bDead;
	RECT m_tRect;
	float m_fSpeed;
	float m_fAngle;
	float m_fRadian;
};

