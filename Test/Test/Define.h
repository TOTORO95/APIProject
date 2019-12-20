#pragma once
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


#ifndef __DEFINE_H__

#define WincX 800
#define WincY 600

#define Alive_OBJ 0
#define DEAD_OBJ 1

#define NULL_CHECK(ptr) if(nullptr == (ptr)) return;
#define NULL_CHECK_RETURN(ptr, val) if(nullptr == (ptr)) return val;



#define __DEFINE_H__
#endif //__DEFINE_H__