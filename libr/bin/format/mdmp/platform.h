#ifdef MDMP_PLATFORM

typedef struct MDMP_PLATFORM(_MINIDUMP_THREAD_CALLBACK, ARCH)
{
	ULONG ThreadId;
	HANDLE ThreadHandle;
	MDMP_PLATFORM(CONTEXT_TYPE, ARCH) Context;
	ULONG SizeOfContext;
	ULONG64 StackBase;
	ULONG64 StackEnd;
}
MDMP_PLATFORM(MINIDUMP_THREAD_CALLBACK, ARCH), MDMP_PLATFORM(*PMINIDUMP_THREAD_CALLBACK, ARCH);


typedef struct MDMP_PLATFORM(_MINIDUMP_THREAD_EX_CALLBACK, ARCH)
{
	ULONG ThreadId;
	HANDLE ThreadHandle;
	MDMP_PLATFORM(CONTEXT_TYPE, ARCH) Context;
	ULONG SizeOfContext;
	ULONG64 StackBase;
	ULONG64 StackEnd;
	ULONG64 BackingStoreBase;
	ULONG64 BackingStoreEnd;
}
MDMP_PLATFORM(MINIDUMP_THREAD_EX_CALLBACK, ARCH), MDMP_PLATFORM(*PMINIDUMP_THREAD_EX_CALLBACK, ARCH);


typedef struct MDMP_PLATFORM(_MINIDUMP_CALLBACK_INPUT, ARCH)
{
	ULONG ProcessId;
	HANDLE ProcessHandle;
	ULONG CallbackType;
	union {
		HRESULT Status;
		MDMP_PLATFORM(MINIDUMP_THREAD_CALLBACK, ARCH) Thread;
		MDMP_PLATFORM(MINIDUMP_THREAD_EX_CALLBACK, ARCH) ThreadEx;
		MINIDUMP_MODULE_CALLBACK Module;
		MINIDUMP_INCLUDE_THREAD_CALLBACK IncludeThread;
		MINIDUMP_INCLUDE_MODULE_CALLBACK IncludeModule;
		MINIDUMP_IO_CALLBACK Io;
		MINIDUMP_READ_MEMORY_FAILURE_CALLBACK ReadMemoryFailure;
		ULONG SecondaryFlags;
		MINIDUMP_VM_QUERY_CALLBACK VmQuery;
		MINIDUMP_VM_PRE_READ_CALLBACK VmPreRead;
		MINIDUMP_VM_POST_READ_CALLBACK VmPostRead;
	};
}
MDMP_PLATFORM(MINIDUMP_CALLBACK_INPUT, ARCH), MDMP_PLATFORM(*PMINIDUMP_CALLBACK_INPUT, ARCH);


#endif