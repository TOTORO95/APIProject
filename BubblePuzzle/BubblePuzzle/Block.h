#pragma once
#include "GameObject.h"
class CBlock :public CGameObject
{

public:
	CBlock();
	CBlock(INFO _playerinfo);
	CBlock(INFO _playerinfo,INFO _taiminfo);
	~CBlock();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

public:
	void Move();
	void SetColor(HDC _hdc, MyRGB _color);
	bool GetIsSet() { return m_bIsSet; };
	void SetIsSet(bool _bool) { m_bIsSet = _bool; };


private:
	BLOCK_TYPE m_iColor;
	bool m_bIsSet;

};

