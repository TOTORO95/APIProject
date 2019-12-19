#pragma once

class CGameObject;
//추상 팩토리 패턴!!

template <typename T>
class AbstractFactory
{
public:
	static CGameObject* CreateObject()
	{
		CGameObject* temp = new T;
		temp->Initialize();
		return temp;
	}
	//static CGameObject* CreateObject()
	//{
	//	CGameObject* temp = new T;
	//	temp->Initialize();
	//	return temp;
	//}

private:

};
