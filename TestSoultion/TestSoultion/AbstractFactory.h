#pragma once

class CGameObject;
//�߻� ���丮 ����!!

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
