#ifndef DSMCC_WIN32_H
#define DSMCC_WIN32_H

/* timeradd and timersub 
   courtesy of Geoffrey Noer's public domain time.h code */

#ifndef timeradd
#define timeradd(a, b, result) \
	do { \
		(result)->tv_sec = (a)->tv_sec + (b)->tv_sec; \
		(result)->tv_usec = (a)->tv_usec + (b)->tv_usec; \
		if ((result)->tv_usec >= 1000000L) { \
			++(result)->tv_sec; \
			(result)->tv_usec -= 1000000L; \
		} \
	} while (0)
#endif

#ifndef timersub
#define timersub(a, b, result) \
	do { \
		(result)->tv_sec = (a)->tv_sec - (b)->tv_sec; \
		(result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
		if ((result)->tv_usec < 0) { \
			--(result)->tv_sec; \
			(result)->tv_usec += 1000000L; \
		} \
	} while (0)
#endif

#ifndef strndup
#define strndup dsmcc_strndup
#endif

char* dsmcc_strndup(const char * src, size_t size);
char* dsmcc_wintempdir(void);

#endif
