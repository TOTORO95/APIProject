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
private:

};





#define __ABSTRACTFACTORY_H__
#endif // !__ABSTRACTFACTORY_H__
