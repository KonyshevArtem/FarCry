#ifndef _CRY_COMMON_APPLE_SPECIFIC_HDR_
#define _CRY_COMMON_APPLE_SPECIFIC_HDR_

#include <cstdint>
#include <pthread.h>
#include <cstdio>
#include <cctype>


#define __forceinline   inline
#define _inline         inline
#define _finite         finite
#define _snprintf       snprintf
#define _isnan          isnan
#define stricmp         strcasecmp
#define _stricmp        strcasecmp
#define strnicmp        strncasecmp
#define _vsnprintf      vsnprintf

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

typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned int    DWORD;
typedef uint64          DWORD_PTR;
typedef void*			LPVOID;

typedef int     HRESULT;
typedef void*   HWND;

typedef intptr_t        INT_PTR,    *PINT_PTR;
typedef uintptr_t       UINT_PTR,   *PUINT_PTR;
typedef unsigned long   ULONG_PTR,  *PULONG_PTR;


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

inline void ltoa(int number, char *buffer, int base)
{
    std::sprintf(buffer, "%d", number);
}

inline void _makepath(char* buffer, const char* drive, const char* directory, const char* filename, const char* extension)
{
    if (drive == nullptr)
        std::sprintf(buffer, "%s/%s.%s", directory, filename, extension);
    else
        std::sprintf(buffer, "%s/%s/%s.%s", drive, directory, filename, extension);
}

inline void strlwr(char* str)
{
    while (*str != '\0')
    {
        char c = *str;
        if (isalpha(c))
            *str = tolower(c);
        ++str;
    }
}

inline void OutputDebugString(const char* str)
{
    // TODO: apple
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

#define _finddata_t     _finddata64i32_t
#define _finddatai64_t  __finddata64_t

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


#endif //_CRY_COMMON_APPLE_SPECIFIC_HDR_
