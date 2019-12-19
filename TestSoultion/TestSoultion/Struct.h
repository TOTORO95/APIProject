#pragma once
#ifndef __STRUCT_H__
typedef struct Info
{
	float fX, fY;
	float fSizeX, fSizeY;

}Info;

typedef struct CollInfo
{
	bool bIsLeft;
	bool bIsTop;
	bool bIsRight;
	bool bIsBottom;
}CollInfo;

#define __STRUCT_H__
#endif // !__STRUCT_H__
