#pragma once
#include "GameObject.h"
class CBullet :public CGameObject
{
public:
	CBullet();
	~CBullet();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Relese() override;
	void SetSpeed(float _fspeed) { m_fSpeed = _fspeed; };
};

