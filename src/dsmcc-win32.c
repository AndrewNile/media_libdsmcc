#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>  /* MAX_PATH */

char* dsmcc_strndup(const char * src, size_t size) {
  size_t len = strnlen(src, size);
  len = len < size ? len : size;
  char * dst = malloc(len + 1);
  if (!dst)
    return NULL;
  memcpy(dst, src, len);
  dst[len] = '\0';
  return dst;
}

char* dsmcc_wintempdir(void)
{
	/* Get the Windows TEMP folder */
	
	char* tmpPath;
	char* tmpFolder = getenv("TEMP");

	if(tmpFolder == NULL)
	{
		/* Better than nothing */
		tmpFolder = (char*)malloc(strlen("temp") + 1);
		strcpy(tmpFolder, "temp");
	}

	/* Ensure it doesn't exceed limits */
	tmpPath = (char*)malloc(strlen(tmpFolder) + 1);
	snprintf(tmpPath, MAX_PATH - 1, "%s", tmpFolder);
	
	free(tmpFolder);
	return tmpPath;
}
