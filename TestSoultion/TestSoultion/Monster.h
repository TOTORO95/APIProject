#pragma once
#include "GameObject.h"
class CMonster :
	public CGameObject
{
public:
	CMonster();
	~CMonster();

	// CGameObject��(��) ���� ��ӵ�
	virtual int Update() override;
	virtual void Initialize() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;


};

