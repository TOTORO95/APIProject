#pragma once
#include "GameObject.h"
class CMonster :public CGameObject
{
public:
	CMonster();
	~CMonster();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
private:
	virtual void Release() override;
	void Move();


};

