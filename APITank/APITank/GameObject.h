#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
	virtual void Update() = 0;


	INFO GetInfo() const { return m_Info; }
	void SetInfo(INFO val) { m_Info = val; }
protected:
	INFO m_Info;
	INFO* m_pInfo;
};

