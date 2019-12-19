#pragma once
#include "GameObject.h"
class CMonster :
	public CGameObject
{
public:
	CMonster();
	~CMonster();

	// CGameObject을(를) 통해 상속됨
	virtual int Update() override;
	virtual void Initialize() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;


};

