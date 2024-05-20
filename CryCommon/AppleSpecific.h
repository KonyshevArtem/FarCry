#ifndef _CRY_COMMON_APPLE_SPECIFIC_HDR_
#define _CRY_COMMON_APPLE_SPECIFIC_HDR_

#ifdef __cplusplus
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <mach/mach_time.h>
#include <sys/stat.h>
#include <unistd.h>
#else
#include <stdint.h>
#endif
#include <pthread.h>

#include "UnixSpecific.h"

#define _finite         finite
#define _strlwr         strlwr
#define _fstat64        fstat64
#define Sleep           usleep
#define memicmp         strncasecmp

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

typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME,*PFILETIME,*LPFILETIME;


#ifdef __cplusplus

inline char* ltoa(int number, char *buffer, int base)
{
    std::sprintf(buffer, "%d", number);
    return buffer;
}

inline char* itoa(int number, char *buffer, int base)
{
    std::sprintf(buffer, "%d", number);
    return buffer;
}

inline void _makepath(char* buffer, const char* drive, const char* directory, const char* filename, const char* extension)
{
    if (drive == nullptr)
        std::sprintf(buffer, "%s/%s.%s", directory, filename, extension);
    else
        std::sprintf(buffer, "%s/%s/%s.%s", drive, directory, filename, extension);
}

inline char* strlwr(char* str)
{
    while (*str != '\0')
    {
        char c = *str;
        if (isalpha(c))
            *str = tolower(c);
        ++str;
    }
    return str;
}

inline char* strupr(char* str)
{
    while (*str != '\0')
    {
        char c = *str;
        if (isalpha(c))
            *str = toupper(c);
        ++str;
    }
    return str;
}

inline void OutputDebugString(const char* str)
{
    // TODO: apple
}

inline bool MakeSureDirectoryPathExists(const char* path)
{
    // TODO: apple
    return false;
}

inline void DebugBreak()
{
    // TODO: apple
}

inline int WSAGetLastError()
{
    return 0;
}

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

intptr_t _findfirst64(const char* filespec, struct _finddata64_t* fileinfo)
{
    // TODO apple
    return -1L;
}

intptr_t _findnext64(intptr_t handle, struct _finddata64_t* fileinfo)
{
    // TODO apple
    return -1L;
}

void _findclose(intptr_t handle)
{
    // TODO apple
}

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

inline void GetLocalTime(SYSTEMTIME* outTime)
{
    // TODO apple
}

inline DWORD GetCurrentDirectory(size_t bufferSize, char* buffer)
{
    // TODO apple
    return 0;
}

void InitializeCriticalSection(CRITICAL_SECTION* criticalSection)
{
    // TODO apple
}

void DeleteCriticalSection(CRITICAL_SECTION* criticalSection)
{
    // TODO apple
}

void EnterCriticalSection(CRITICAL_SECTION* criticalSection)
{
    // TODO apple
}

void LeaveCriticalSection(CRITICAL_SECTION* criticalSection)
{
    // TODO apple
}

unsigned int GetTickCount()
{
    // TODO apple
    return mach_absolute_time();
}

int64_t Int32x32To64(int32_t a, int32_t b)
{
    return static_cast<int64_t>(a * b);
}

char* _fullpath(char* buffer, const char* relativePath, size_t bufferSize)
{
    // TODO apple
    return buffer;
}

DWORD GetFileAttributes(const char* fileName)
{
    // TODO apple
    return 0;
}

int _mkdir(const char* dirPath)
{
    // TODO apple
    return mkdir(dirPath, 0777);
}

void DeleteFile(const char* filepath)
{
    // TODO apple
}

void RemoveDirectory(const char* dirPath)
{
    // TODO apple
}

bool QueryPerformanceFrequency(LARGE_INTEGER* outFrequency)
{
    // TODO apple
    outFrequency = 0;
    return true;
}

bool QueryPerformanceCounter(LARGE_INTEGER* outPerformanceCount)
{
    // TODO apple
    outPerformanceCount = 0;
    return 0;
}

DWORD GetCurrentThreadId()
{
    // TODO apple
    return 0;
}

EVENT_HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, bool bInitialState, const char* lpName)
{
    // TODO apple
    return nullptr;
}

void CloseHandle(HANDLE handle)
{
    // TODO apple
}

void CloseHandle(EVENT_HANDLE handle)
{
    // TODO apple
}

void SetEvent(EVENT_HANDLE handle)
{
    // TODO apple
}

void ResetEvent(EVENT_HANDLE handle)
{
    // TODO apple
}

void WaitForSingleObject(EVENT_HANDLE handle, int milliseconds)
{
    // TODO apple
}

void WaitForSingleObjectEx(EVENT_HANDLE handle, unsigned int milliseconds, bool b)
{
    // TODO apple
}

void SleepEx(unsigned int microseconds, bool b)
{
    // TODO apple
    Sleep(microseconds);
}

bool GetDiskFreeSpace(const char* lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
{
    // TODO apple
    lpSectorsPerCluster = 0;
    lpBytesPerSector = 0;
    lpNumberOfFreeClusters = 0;
    lpTotalNumberOfClusters = 0;
}

DWORD timeGetTime()
{
    // TODO apple
    return 0;
}

#endif

// TODO apple
#define INVALID_FILE_ATTRIBUTES     0
#define FILE_ATTRIBUTE_DIRECTORY    0

#endif //_CRY_COMMON_APPLE_SPECIFIC_HDR_
