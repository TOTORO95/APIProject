#pragma once
#include "GameObject.h"
class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Release() override;
	virtual void Render(HDC _hdc) override;
	
public:
	void SetTarget(CGameObject* _target);

private:
	void KeyInput();



};

