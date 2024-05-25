#if defined(APPLE)

#include "AppleSpecific.h"

#ifdef __cplusplus

void GetExecutablePath(char*& path, uint32_t size)
{
    if (_NSGetExecutablePath(path, &size))
    {
        delete[] path;
        path = new char[size];
        _NSGetExecutablePath(path, &size);
    }
}

DWORD GetCurrentDirectory(size_t size, char* path)
{
    char* result = getcwd(path, size);
    return result ? strlen(path) : 0;
}

char* ltoa(int number, char *buffer, int base)
{
    std::sprintf(buffer, "%d", number);
    return buffer;
}

char* itoa(int number, char *buffer, int base)
{
    std::sprintf(buffer, "%d", number);
    return buffer;
}

char* strlwr(char* str)
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

char* strupr(char* str)
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

void OutputDebugString(const char* str)
{
    // TODO: apple
}

bool MakeSureDirectoryPathExists(const char* path)
{
    // TODO: apple
    return false;
}

void DebugBreak()
{
    // TODO: apple
}

int WSAGetLastError()
{
    // TODO apple
    return 0;
}

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

void GetLocalTime(SYSTEMTIME* outTime)
{
    // TODO apple
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
    realpath(relativePath, buffer);
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

#endif