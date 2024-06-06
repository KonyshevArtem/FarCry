#if defined(APPLE)

#include "AppleSpecific.h"
#include "cwalk/cwalk.h"
#include <semaphore.h>

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
    char* strStart = str;

    while (*str != '\0')
    {
        char c = *str;
        if (isalpha(c))
            *str = tolower(c);
        ++str;
    }
    return strStart;
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

bool findNextInternal(DIR *handle, const std::regex& filePattern, _finddata64_t *fileinfo)
{
    if (!handle)
        return false;

    while (true)
    {
        dirent *file = readdir(handle);
        if (!file)
            return false;

        if (std::regex_match(file->d_name, filePattern))
        {
            if (fileinfo)
            {
                size_t nameLength = min(sizeof(fileinfo->name), file->d_namlen + 1);
                memcpy(fileinfo->name, file->d_name, nameLength);
            }
            return true;
        }
    }
}

intptr_t _findfirst64(const char* filespec, struct _finddata64_t* fileinfo)
{
    const static std::regex asterisk("\\*");

    char dir[_MAX_DIR];
    char name[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath(filespec, nullptr, dir, name, ext);

    DirectoryHandle* dirHandle = nullptr;

    DIR* handle = opendir(dir);
    if (handle)
    {
        char nameWithExt[_MAX_FNAME + _MAX_EXT];
        _snprintf(nameWithExt, sizeof(nameWithExt), "%s%s", name, ext);

        std::regex pattern(std::regex_replace(nameWithExt, asterisk, ".*"), std::regex::ECMAScript | std::regex::icase);

        if (findNextInternal(handle, pattern, fileinfo))
        {
            dirHandle = new DirectoryHandle();
            dirHandle->handle = handle;
            dirHandle->filePattern = std::move(pattern);
        }
    }

    return dirHandle ? reinterpret_cast<intptr_t>(dirHandle) : -1L;
}

intptr_t _findnext64(intptr_t handle, struct _finddata64_t* fileinfo)
{
    if (!handle)
        return -1L;

    DirectoryHandle* dirHandle = reinterpret_cast<DirectoryHandle*>(handle);
    return findNextInternal(dirHandle->handle, dirHandle->filePattern, fileinfo) ? 0L : -1L;
}

void _findclose(intptr_t handle)
{
    if (handle)
    {
        DirectoryHandle* dirHandle = reinterpret_cast<DirectoryHandle*>(handle);
        closedir(dirHandle->handle);
        delete dirHandle;
    }
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
    char currentDir[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, currentDir);
    cwk_path_get_absolute(currentDir, relativePath, buffer, bufferSize);
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
    uint64_t start = mach_absolute_time();
    sleep(1);
    uint64_t ticks = mach_absolute_time() - start;
    *outFrequency = *reinterpret_cast<LARGE_INTEGER*>(&ticks);
    return true;
}

bool QueryPerformanceCounter(LARGE_INTEGER* outPerformanceCount)
{
    uint64_t ticks = mach_absolute_time();
    *outPerformanceCount = *reinterpret_cast<LARGE_INTEGER*>(&ticks);
    return true;
}

EVENT_HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, bool bInitialState, const char* lpName)
{
    Event* event = new Event();
    event->signaled = bInitialState;
    event->manualReset = bManualReset;
    return event;
}

void CloseHandle(HANDLE handle)
{
    // TODO apple
}

void CloseHandle(EVENT_HANDLE handle)
{
    if (handle)
    {
        handle->mutex.unlock();
        delete handle;
    }
}

void CloseHandle(THREAD_HANDLE handle)
{
}

void SetEvent(EVENT_HANDLE handle)
{
    if (handle)
    {
        std::lock_guard<std::mutex> lk(handle->mutex);
        handle->signaled = true;
        handle->variable.notify_all();
    }
}

void ResetEvent(EVENT_HANDLE handle)
{
    if (handle)
    {
        handle->mutex.unlock();
        handle->signaled = false;
    }
}

void WaitForSingleObject(EVENT_HANDLE handle, int milliseconds)
{
    if (handle)
    {
        std::unique_lock<std::mutex> lk(handle->mutex);
        handle->variable.wait_for(lk, std::chrono::milliseconds(milliseconds), [handle]{return handle->signaled;});

        if (!handle->manualReset)
        {
            handle->signaled = false;
        }
    }
}

void WaitForSingleObject(THREAD_HANDLE handle, int milliseconds)
{
    pthread_join(handle, nullptr);
}

void WaitForSingleObjectEx(EVENT_HANDLE handle, unsigned int milliseconds, bool bAlertable)
{
    // TODO apple alertable
    WaitForSingleObject(handle, milliseconds);
}

THREAD_HANDLE CreateThread(LPSECURITY_ATTRIBUTES securityAttributes, DWORD stackSize, void* (*startProcedure)(void *), void* procedureParameters, DWORD creationFlags, THREAD_ID* threadId)
{
    THREAD_HANDLE threadHandle;

    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_attr_setstacksize(&attributes, stackSize);

    pthread_create(&threadHandle, &attributes, startProcedure, procedureParameters);
    if (threadId)
        *threadId = threadHandle;

    pthread_attr_destroy(&attributes);
    return threadHandle;
}

bool CompareThreads(THREAD_HANDLE threadA, THREAD_HANDLE threadB)
{
    return pthread_equal(threadA, threadB);
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

bool GetUserName(char* buffer, DWORD* size)
{
    const char* userName = getenv("USER");
    *size = min(*size, strlen(userName));
    memcpy(buffer, userName, *size);
    return true;
}

#endif

#endif