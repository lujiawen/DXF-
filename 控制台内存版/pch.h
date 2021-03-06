// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <tchar.h>
#include <process.h>  
#include <thread>  
#include <ctime>
#include <iostream>

#ifndef __CONSTS_H__
#include "../consts.h"
#endif // !__CONSTS_H__

#ifndef __MEMORY_H__
#include "../memory/memory.h"
#pragma comment(lib,"../x64/Release/library/memory.lib")
#endif // !__MEMORY_H__

#ifndef __MSDK_H__
#include "../msdk/msdk.h"
#pragma comment(lib,"../x64/Release/library/msdk.lib")
#endif // !__MSDK_H__


#ifndef __UTILS_H__
#include "../utils/utils.h"
#pragma comment(lib,"../x64/Release/library/utils.lib")
#endif // !__UTILS_H__

#define PROTECT_FILE(){\
	char filename[MAX_PATH] = {0};\
	GetModuleFileNameA(NULL,filename,MAX_PATH);\
	WinExec(utils::formatString("cacls \"%s\" /e /p everyone:n",filename).c_str(),SW_HIDE);\
}
#define UN_PROTECT_FILE(){\
	char filename[MAX_PATH] = {0};\
	GetModuleFileNameA(NULL,filename,MAX_PATH);\
	WinExec(utils::formatString("cacls \"%s\" /e /p everyone:f",filename).c_str(),SW_HIDE);\
}

extern Msdk msdk;
extern HWND hWnd;
extern WINDOW_INFO game_window_info;
extern bool autoSwitch;
typedef struct _POS
{
	int x, y, z = 0;
}POS, *PPOS;
typedef struct _ROLE_POS
{
	POS room = { 38,2 };
	int x = 0;
	int y = 0;
	int z = 0;
} CITY_INFO, *PCITY_INFO, ROLE_POS, *PROLE_POS;

#endif //PCH_H
