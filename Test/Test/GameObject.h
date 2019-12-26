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

	void SetDead(bool _isdead) { m_bIsDead = _isdead; };
	bool IsDead() { return m_bIsDead; };
	void RenderHP(HDC _hdc);
	void SetPos(float _x, float _y) { m_tInfo.fPosX = _x, m_tInfo.fPosY = _y; };
	void SetSize(float _x, float _y) { m_tInfo.fSizeX = _x, m_tInfo.fSizeY = _y; };
	Info GetInfo() { return m_tInfo; };
	void SetHP(int _hp) { m_HP = _hp; };
	int GetHP() { return m_HP; };
	int GetMaxHP() { return m_MaxHP; };
	void SetMaxHp(int _hp) { m_MaxHP = _hp; };
	void Beattack(int _damage) { m_HP -= _damage; };
	void InitHP(int _hp) { m_MaxHP = _hp, m_HP = m_MaxHP; };
protected:
	int m_HP;
	int m_MaxHP;
	Info m_tInfo;
	RECT m_tRect;
	float m_fSpeed;
	bool m_bIsDead;
};

