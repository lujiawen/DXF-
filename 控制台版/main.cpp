// 控制台版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

HANDLE hDriver;
int main()
{
	//driversss.Init();
	hDriver = GetDriverHandle();
	DWORD value = RVM<DWORD>(0x0552522C);
	utils::myprintf("value %d",CYAN, value);
	WVM<DWORD>(0x0552522C,100);
	system("pause");
}


