#ifndef __RW4API_H__
#define __RW4API_H__
//#define TARGET_PROCESS_NAME L"DNF.exe"
#define TARGET_PROCESS_NAME L"YoudaoDict.exe"
#define DEVICE_SHOST_NAME L"RW4"
#define DEVICE_NAME (L"\\Device\\" DEVICE_SHOST_NAME)
#define SYMBOLIC_LINK_SHORT_NAME L"RW4"
#define SYMBOLIC_LINK_NAME (L"\\DosDevices\\" SYMBOLIC_LINK_SHORT_NAME)


#define KCTL_CODE(x) CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800 + x, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define READ_VIRTUAL_MEMORY KCTL_CODE(1)
#define WRITE_VIRTUAL_MEMORY KCTL_CODE(2)
#define GET_PROCESS_ID KCTL_CODE(3)
#define GET_PROCESS_BASE_ADDRESS KCTL_CODE(4)


typedef struct _READ_VIRTUAL_MEMORY_STRUCT
{
	ULONG Address;
	PVOID Response;
	SIZE_T Size;
}READ_VIRTUAL_MEMORY_STRUCT, *PREAD_VIRTUAL_MEMORY_STRUCT;

typedef struct _WRITE_VIRTUAL_MEMORY_STRUCT
{
	ULONG Address;
	PVOID Value;
	SIZE_T Size;
}WRITE_VIRTUAL_MEMORY_STRUCT, *PWRITE_VIRTUAL_MEMORY_STRUCT;

#endif // !__RW4API_H__





