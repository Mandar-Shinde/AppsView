#if !defined(_PLOG_H)
#define _PLOG_H

#include <stdio.h>
#include <fstream>
#include <string>
#include <stdarg.h>
#include <zlib.h>

#ifdef _WIN32
#include "pthread.h"
# pragma comment(lib, "pthreadVC2")
#else
#include <pthread.h>	//by default in linux
#include <sys/types.h>
#include <sys/stat.h>
#endif




#define LOG_FILE_ENTRY_LEN 2*1024 //2kb
#define DEFAULT_LOG_FILE_SIZE_THRESHOLD	(5*1024*1024)

enum EPLOG{DEBUG=0,INFO=1,MSG=2,ERROR=4};

using namespace std;

class PLog
{
private:
	std::string logFileLocation;
	std::string logFileName;
	std::string logFileFullPath;

	unsigned int logFileSize;	//default 5 MB
	EPLOG mLogLevel;

	pthread_mutex_t mutex_plog;

public:
	PLog();
	~PLog();
	void InitLogFile(std::string path, std::string filename,EPLOG loglevel, unsigned int filesize=DEFAULT_LOG_FILE_SIZE_THRESHOLD);

	void Log(EPLOG logenum,char* test,  ...);
	void PrintBanner(char* text);
	void RotateFile(size_t filesize);
	void RotateToArchive(size_t filesize);
	std::string compressFile();

};

extern PLog glogobj;

#endif  //_LOG_H


//#define PLOG_ERROR_LEVEL	4
//#define PLOG_MSG_LEVEL		2
//#define PLOG_INFO_LEVEL		1
//#define PLOG_DEBUG_LEVEL	0
//
//#define PLDEBUG PLOG_DEBUG_LEVEL
//#define PLERROR PLOG_ERROR_LEVEL
//#define PLINFO PLOG_INFO_LEVEL
//#define PLMSG PLOG_MSG_LEVEL
