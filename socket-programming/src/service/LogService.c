#include "../../include/service/LogService.h"

static void logMsg(FILE* _stream, char* _type, char* _format, va_list _args)
{
    time_t     now; 
    char       buffer[20];

    time(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", gmtime(&now));
    fprintf(_stream, "[%s] ", buffer);
    fprintf(_stream, "[%s] ", _type);
    vfprintf(_stream, _format, _args);
    fputc('\n', _stream);

    return;
}

void logErrorToConsole(char* _format, ...)
{
    va_list args;
    va_start(args, _format);
    logMsg(stderr, (char*)ERROR_TYPE, _format, args);
    va_end(args);

    return;
}

void logInfoToConsole(char* _format, ...)
{
    va_list args;
    va_start(args, _format);
    logMsg(stderr, (char*)INFO_TYPE, _format, args);
    va_end(args);

    return;
}

static void logToFile(char* _type, char* _format, va_list _args)
{
    FILE* stream;

    stream = fopen((char*)LOG_FILE_PATH, "a");

    if(stream == NULL){
        logErrorToConsole("failed to open %s", LOG_FILE_PATH);
        return;
    }

    logMsg(stream, _type, _format, _args);

    return;
}

void logErrorToFile(char* _format, ...)
{
    va_list args;

    va_start(args, _format);
    logToFile((char*)ERROR_TYPE, _format, args);
    va_end(args);

    return;
}

void logInfoToFile(char* _format, ...)
{
    va_list args;

    va_start(args, _format);
    logToFile((char*)INFO_TYPE, _format, args);
    va_end(args);

    return;
}

void logWarningToFile(char* _format, ...)
{
    va_list args;

    va_start(args, _format);
    logToFile((char*)WARNING_TYPE, _format, args);
    va_end(args);

    return;
}