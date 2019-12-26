#pragma once
#ifndef __ABSTRACTFACTORY_H__
class CGameObject;

template <typename T>
class AbsFactory
{
public:
	static CGameObject* Create()
	{
		CGameObject * temp = new T;
		temp->Initialize();
		return temp;
	}
	static CGameObject* Create(float _x,float _y)
	{
		CGameObject * temp = new T;
		temp->Initialize();
		temp->SetPos(_x, _y);
		return temp;
	}
	
private:

};





#define __ABSTRACTFACTORY_H__
#endif // !__ABSTRACTFACTORY_H__
