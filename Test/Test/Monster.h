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
	virtual void Relese() override;
	void SetBulletList(GameList& _bulletlist) { m_pBulletList = &_bulletlist; };
	void ShootBullet();

private:
	GameList * m_pBulletList;
};

