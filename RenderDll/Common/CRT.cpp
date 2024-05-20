#if defined(LINUX) || defined(APPLE)
	#include "platform.h"
#else
	#include "Windows.h"
#endif

void CRTFreeData(void *pData)
{
  free(pData);
}

void CRTDeleteArray(void *pData)
{
  delete [] pData;
}