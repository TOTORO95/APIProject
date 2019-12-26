#pragma once
#ifndef __FUNTION_H__

template <typename T>
void SafeDelete(T _t)
{
	if (_t)
	{
		delete _t;
		_t = nullptr;
	}
}

#define __FUNTION_H__
#endif // !__FUNTION_H__
