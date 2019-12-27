#pragma once
#include "GameObject.h"
class CPlayer : public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	//void SetTarget(vector<CGameObject*> _monsters);
	void SetTarget(CGameObject* _target);
	virtual void Render(HDC _hdc) override;
private:
	void KeyInput();
	virtual void Release() override;
	float m_fSpeed;
	list<Bullet*> m_Bullets;
	//vector<CGameObject*> m_pTargets;
	CGameObject* m_pTarget;
	// CGameObject을(를) 통해 상속됨
};

