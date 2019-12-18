#pragma once
#include "GameObject.h"

class Bullet : public CGameObject
{
public:
	Bullet();
	~Bullet();

	virtual void Initialize() override;
	void Initialize(float _x, float _y);
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
	void CheckCollide(CGameObject* _pcgo);
private:
	// CGameObject을(를) 통해 상속됨
	virtual void Release() override;
};

