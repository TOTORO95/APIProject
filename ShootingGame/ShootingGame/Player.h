#pragma once
#include "GameObject.h"
class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;

private:
	virtual void Release() override;
	float m_fSpeed;

	// CGameObject��(��) ���� ��ӵ�
};

