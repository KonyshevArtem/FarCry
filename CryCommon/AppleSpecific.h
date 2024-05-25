#ifndef _CRY_COMMON_APPLE_SPECIFIC_HDR_
#define _CRY_COMMON_APPLE_SPECIFIC_HDR_

#ifdef __cplusplus
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <mach/mach_time.h>
#include <mach-o/dyld.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include "splitpath.h"
#include "makepath.h"
#else
#include <stdint.h>
#endif
#include <pthread.h>

#include "UnixSpecific.h"

#define _finite             finite
#define _strlwr             strlwr
#define _fstat64            fstat64
#define Sleep               usleep
#define memicmp             strncasecmp
#define SetCurrentDirectory chdir

#define INFINITE INT32_MAX

typedef uint64          DWORD_PTR;
typedef intptr_t        INT_PTR,    *PINT_PTR;
typedef uintptr_t       UINT_PTR,   *PUINT_PTR;

typedef void*       HINSTANCE;
typedef void*       LPDIRECTINPUT8;
typedef void*       LPDIRECTINPUTDEVICE8;
typedef UINT_PTR 	WPARAM;
typedef int         CRITICAL_SECTION; // TODO apple synchronization
typedef void*       HINTERNET; // TODO apple
typedef void*       THREAD_HANDLE; // TODO apple
typedef void*       EVENT_HANDLE; // TODO apple
typedef const char* LPCSTR;
typedef void*       RECT;

typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME,*PFILETIME,*LPFILETIME;


#ifdef __cplusplus

#define GetModuleFileName(module, path, size) GetExecutablePath(path, size)
void GetExecutablePath(char*& path, uint32_t size);

DWORD GetCurrentDirectory(size_t size, char* path);

char* ltoa(int number, char *buffer, int base);

char* itoa(int number, char *buffer, int base);

char* strlwr(char* str);

char* strupr(char* str);

void OutputDebugString(const char* str);

bool MakeSureDirectoryPathExists(const char* path);

void DebugBreak();

int WSAGetLastError();

struct _finddata64i32_t {
    unsigned attrib;
    int64_t time_create;
    int64_t time_access;
    int64_t time_write;
    unsigned long size;
    char name[260];
};

struct __finddata64_t {
    unsigned attrib;
    int64_t time_create;
    int64_t time_access;
    int64_t time_write;
    int64_t size;
    char name[260];
};

// TODO apple
#define _finddata_t     _finddata64i32_t
#define _finddata64_t   __finddata64_t
#define _finddatai64_t  __finddata64_t
#define _A_SUBDIR       0

intptr_t _findfirst64(const char* filespec, struct _finddata64_t* fileinfo);

intptr_t _findnext64(intptr_t handle, struct _finddata64_t* fileinfo);

void _findclose(intptr_t handle);

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

void GetLocalTime(SYSTEMTIME* outTime);

void InitializeCriticalSection(CRITICAL_SECTION* criticalSection);

void DeleteCriticalSection(CRITICAL_SECTION* criticalSection);

void EnterCriticalSection(CRITICAL_SECTION* criticalSection);

void LeaveCriticalSection(CRITICAL_SECTION* criticalSection);

unsigned int GetTickCount();

int64_t Int32x32To64(int32_t a, int32_t b);

char* _fullpath(char* buffer, const char* relativePath, size_t bufferSize);

DWORD GetFileAttributes(const char* fileName);

int _mkdir(const char* dirPath);

void DeleteFile(const char* filepath);

void RemoveDirectory(const char* dirPath);

bool QueryPerformanceFrequency(LARGE_INTEGER* outFrequency);

bool QueryPerformanceCounter(LARGE_INTEGER* outPerformanceCount);

DWORD GetCurrentThreadId();

EVENT_HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, bool bInitialState, const char* lpName);

void CloseHandle(HANDLE handle);

void CloseHandle(EVENT_HANDLE handle);

void SetEvent(EVENT_HANDLE handle);

void ResetEvent(EVENT_HANDLE handle);

void WaitForSingleObject(EVENT_HANDLE handle, int milliseconds);

void WaitForSingleObjectEx(EVENT_HANDLE handle, unsigned int milliseconds, bool b);

void SleepEx(unsigned int microseconds, bool b);

bool GetDiskFreeSpace(const char* lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);

DWORD timeGetTime();

#endif

// TODO apple
#define INVALID_FILE_ATTRIBUTES     0
#define FILE_ATTRIBUTE_DIRECTORY    0

#endif //_CRY_COMMON_APPLE_SPECIFIC_HDR_
