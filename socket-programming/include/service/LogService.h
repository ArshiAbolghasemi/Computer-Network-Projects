#ifndef _LOG_SERVICE_H_
#define _LOG_SERVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define ERROR_TYPE "ERROR"
#define INFO_TYPE "INFO"
#define WARNING_TYPE "WARNING"

#define LOG_FILE_PATH "log.txt" // accessible from all the source files to the one exact location

static void logMsg(FILE* _stream, char* _type, char* _format, va_list _args);

void logErrorToConsole(char* _format, ...);

void logInfoToConsole(char* _format, ...);

static void logToFile(char* _type, char* _format, va_list _args);

void logErrorToFile(char* _format, ...);

void logInfoToFile(char* _format, ...);

void logWarningToFile(char* _format, ...);

#ifdef __cplusplus
}
#endif

#endif