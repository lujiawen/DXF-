#pragma once
#include <ntdef.h>
#include <ntifs.h>
#include <ntddk.h>
#include "rw2api.h"

#ifndef dprintf
#define dprintf(Format, ...) DbgPrint("RW2: " Format "\n", __VA_ARGS__)
#endif // !dprintf

extern HANDLE TargetProcessId;
extern PVOID TargetProcessBaseAddress;

NTSTATUS NTAPI MmCopyVirtualMemory
(
	PEPROCESS SourceProcess,
	PVOID SourceAddress,
	PEPROCESS TargetProcess,
	PVOID TargetAddress,
	SIZE_T BufferSize,
	KPROCESSOR_MODE PreviousMode,
	PSIZE_T ReturnSize
);

NTSTATUS DispatchDeviceControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
);

VOID ReadVirtualMemory(
	PREAD_VIRTUAL_MEMORY_STRUCT rvms
);

VOID WriteVirtualMemory(
	PWRITE_VIRTUAL_MEMORY_STRUCT wvms
);