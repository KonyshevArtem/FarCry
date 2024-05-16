#ifndef _CRY_COMMON_APPLE_SPECIFIC_HDR_
#define _CRY_COMMON_APPLE_SPECIFIC_HDR_

#ifdef __cplusplus
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <mach/mach_time.h>
#else
#include <stdint.h>
#endif
#include <pthread.h>


#define __forceinline   inline
#define _inline         inline
#define _finite         finite
#define _snprintf       snprintf
#define _isnan          isnan
#define stricmp         strcasecmp
#define _stricmp        strcasecmp
#define strnicmp        strncasecmp
#define _vsnprintf      vsnprintf
#define _strlwr         strlwr
#define _wtof(str)      wcstod(str, 0)

#define TRUE    1
#define FALSE   0

#define SOCKET          int
#define INVALID_SOCKET  (-1)
#define SOCKET_ERROR    (-1)

// stdlib.h stuff
#define _MAX_DRIVE  3   // max. length of drive component
#define _MAX_DIR    256 // max. length of path component
#define _MAX_FNAME  256 // max. length of file name component
#define _MAX_EXT    256 // max. length of extension component

typedef signed char         int8;
typedef signed short        int16;
typedef signed long         int32;
typedef int64_t             int64;
typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned long		uint32;
typedef uint64_t	        uint64;
typedef float               f32;
typedef double              f64;
typedef signed char         s8;
typedef signed short        s16;
typedef signed long         s32;
typedef int64_t 			s64;
typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned long		u32;
typedef uint64_t    		u64;
typedef unsigned char		byte;

typedef int				BOOL;
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef int				LONG;
typedef unsigned int    DWORD;
typedef uint64          DWORD_PTR;
typedef void*			LPVOID;

typedef intptr_t        INT_PTR,    *PINT_PTR;
typedef uintptr_t       UINT_PTR,   *PUINT_PTR;
typedef long            LONG_PTR,   *PLONG_PTR, *PLONG;
typedef unsigned long   ULONG_PTR,  *PULONG_PTR;

typedef int         HRESULT;
typedef void*       HWND;
typedef void*       HINSTANCE;
typedef void*       LPDIRECTINPUT8;
typedef void*       LPDIRECTINPUTDEVICE8;
typedef UINT_PTR 	WPARAM;
typedef LONG_PTR 	LPARAM;
typedef LONG_PTR 	LRESULT;
typedef int         CRITICAL_SECTION; // TODO apple synchronization

typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME,*PFILETIME,*LPFILETIME;


#ifdef __cplusplus

inline int IsHeapValid()
{
    return true;
}

static pthread_mutex_t mutex_t;

template<typename T>
volatile T InterlockedIncrement(volatile T* pT)
{
    pthread_mutex_lock(&mutex_t);
    ++(*pT);
    pthread_mutex_unlock(&mutex_t);
    return *pT;
}

template<typename T>
volatile T InterlockedDecrement(volatile T* pT)
{
    pthread_mutex_lock(&mutex_t);
    --(*pT);
    pthread_mutex_unlock(&mutex_t);
    return *pT;
}

template<typename S, typename T>
inline const S& min(const S& rS, const T& rT)
{
    return (rS <= rT)? rS : rT;
}

template<typename S, typename T>
inline const S& max(const S& rS, const T& rT)
{
    return (rS >= rT)? rS : rT;
}

template<typename S, typename T>
inline const S& __min(const S& rS, const T& rT)
{
    return min(rS, rT);
}

template<typename S, typename T>
inline const S& __max(const S& rS, const T& rT)
{
    return max(rS, rT);
}

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

typedef struct in_addr_windows
{
    union
    {
        struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
        struct { unsigned short s_w1,s_w2; } S_un_w;
        unsigned int S_addr;
    } S_un;
}in_addr_windows;

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

inline void GetCurrentDirectory(size_t bufferSize, char* buffer)
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

#endif


#ifndef MAX_PATH
    #define MAX_PATH 256
#endif
#ifndef _MAX_PATH
    #define _MAX_PATH MAX_PATH
#endif

#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
            ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |       \
            ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))

#define FILE_ATTRIBUTE_NORMAL 0x00000080

#define WSAEINTR EINTR
#define WSAEBADF EBADF
#define WSAEACCES EACCES
#define WSAEFAULT EFAULT
#define WSAEACCES EACCES
#define WSAEFAULT EFAULT
#define WSAEINVAL EINVAL
#define WSAEMFILE EMFILE
#define WSAEWOULDBLOCK EAGAIN
#define WSAEINPROGRESS EINPROGRESS
#define WSAEALREADY EALREADY
#define WSAENOTSOCK ENOTSOCK
#define WSAEDESTADDRREQ EDESTADDRREQ
#define WSAEMSGSIZE EMSGSIZE
#define WSAEPROTOTYPE EPROTOTYPE
#define WSAENOPROTOOPT ENOPROTOOPT
#define WSAEPROTONOSUPPORT EPROTONOSUPPORT
#define WSAESOCKTNOSUPPORT ESOCKTNOSUPPORT
#define WSAEOPNOTSUPP EOPNOTSUPP
#define WSAEPFNOSUPPORT EPFNOSUPPORT
#define WSAEAFNOSUPPORT EAFNOSUPPORT
#define WSAEADDRINUSE EADDRINUSE
#define WSAEADDRNOTAVAIL EADDRNOTAVAIL
#define WSAENETDOWN ENETDOWN
#define WSAENETUNREACH ENETUNREACH
#define WSAENETRESET ENETRESET
#define WSAECONNABORTED ECONNABORTED
#define WSAECONNRESET ECONNRESET
#define WSAENOBUFS ENOBUFS
#define WSAEISCONN EISCONN
#define WSAENOTCONN ENOTCONN
#define WSAESHUTDOWN ESHUTDOWN
#define WSAETOOMANYREFS ETOOMANYREFS
#define WSAETIMEDOUT ETIMEDOUT
#define WSAECONNREFUSED ECONNREFUSED
#define WSAELOOP ELOOP
#define WSAENAMETOOLONG ENAMETOOLONG
#define WSAEHOSTDOWN EHOSTDOWN
#define WSAEHOSTUNREACH EHOSTUNREACH
#define WSAENOTEMPTY ENOTEMPTY
#define WSAEPROCLIM EPROCLIM
#define WSAEUSERS EUSERS
#define WSAEDQUOT EDQUOT
#define WSAESTALE ESTALE
#define WSAEREMOTE EREMOTE

#endif //_CRY_COMMON_APPLE_SPECIFIC_HDR_
