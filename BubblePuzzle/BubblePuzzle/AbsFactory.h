#pragma once
#ifndef __ABSFACTORY_H__
class CGameObject;

template <typename T>
class AbsFactory
{
public:
	static CGameObject*  CreateObj(RECT _winrect)
	{
		CGameObject* temp = new T();
		temp->Initialize();
		temp->SetPos(_winrect.right*0.5f, _winrect.bottom*0.95f);

		return temp;
	};

	static CGameObject*  CreateObj(INFO _playerinfo,INFO _taiminfo)
	{
		CGameObject* temp = new T();
		temp->SetPos(_playerinfo.fPosX, _playerinfo.fPosY);
		temp->DefalutInit();
		return temp;
	};


};


#define __ABSFACTORY_H__
#endif // !__ABSFACTORY_H__
