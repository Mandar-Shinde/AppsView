#include "PLog.h"
#include <time.h>
#include <stdio.h>
#include <cstdio>

//adding for dir check
#include <qdir.h>
#include<stdlib.h>
#include <QtCore>
#include <qmessagebox.h>

static char szBuffer[2 * LOG_FILE_ENTRY_LEN + 1] =
{ 0 };

inline bool file_exists(const std::string& name)
{
	if (FILE *file = fopen(name.c_str(), "r"))
	{
		fclose(file);
		return true;
	}
	else
	{
		return false;
	}
}
std::string GetCurrentDateTime(std::string format)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, format.c_str(), timeinfo);

	//Format Sting accordingly
	//specifier	Replaced by	Example
	//%a	Abbreviated weekday name *	Thu
	//%A	Full weekday name *	Thursday
	//%b	Abbreviated month name *	Aug
	//%B	Full month name *	August
	//%c	Date and time representation *	Thu Aug 23 14:55:02 2001
	//%C	Year divided by 100 and truncated to integer (00-99)	20
	//%d	Day of the month, zero-padded (01-31)	23
	//%D	Short MM/DD/YY date, equivalent to %m/%d/%y	08/23/01
	//%e	Day of the month, space-padded ( 1-31)	23
	//%F	Short YYYY-MM-DD date, equivalent to %Y-%m-%d	2001-08-23
	//%g	Week-based year, last two digits (00-99)	01
	//%G	Week-based year	2001
	//%h	Abbreviated month name * (same as %b)	Aug
	//%H	Hour in 24h format (00-23)	14
	//%I	Hour in 12h format (01-12)	02
	//%j	Day of the year (001-366)	235
	//%m	Month as a decimal number (01-12)	08
	//%M	Minute (00-59)	55
	//%n	New-line character ('\n')
	//%p	AM or PM designation	PM
	//%r	12-hour clock time *	02:55:02 pm
	//%R	24-hour HH:MM time, equivalent to %H:%M	14:55
	//%S	Second (00-61)	02
	//%t	Horizontal-tab character ('\t')
	//%T	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S	14:55:02
	//%u	ISO 8601 weekday as number with Monday as 1 (1-7)	4
	//%U	Week number with the first Sunday as the first day of week one (00-53)	33
	//%V	ISO 8601 week number (00-53)	34
	//%w	Weekday as a decimal number with Sunday as 0 (0-6)	4
	//%W	Week number with the first Monday as the first day of week one (00-53)	34
	//%x	Date representation *	08/23/01
	//%X	Time representation *	14:55:02
	//%y	Year, last two digits (00-99)	01
	//%Y	Year	2001
	//%z	ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100) If timezone cannot be termined, no characters	+100
	//%Z	Timezone name or abbreviation *  If timezone cannot be termined, no characters	CDT
	//%%	A % sign	%

	return string(buffer);
}

PLog::PLog()
{
	logFileLocation = "";
	logFileName = "";
	logFileFullPath = "";

	mLogLevel = DEBUG;						//log mode
	logFileSize = DEFAULT_LOG_FILE_SIZE_THRESHOLD; //log file size

#ifndef __APPLE__
	mutex_plog=PTHREAD_MUTEX_INITIALIZER;		 // mutex init
#endif

	pthread_mutex_init(&mutex_plog, NULL);
}
PLog::~PLog()
{
	pthread_mutex_destroy(&mutex_plog);
}

void PLog::InitLogFile(std::string strLoc, std::string filename, EPLOG loglevel,
		unsigned int maxSize)
{
	logFileLocation = strLoc;
	logFileName = filename;
	logFileFullPath = strLoc;

#ifdef __WIN32
	if((logFileFullPath.c_str())[logFileFullPath.size()-1] != '\\')
	logFileFullPath.append("\\");
#else
	if ((logFileFullPath.c_str())[logFileFullPath.size() - 1] != '/')
		logFileFullPath.append("/");
#endif

	//added in 7.0.1.8
	//create dir if not exist
	QString qpath("mkdir -p ");
	qpath.append(logFileFullPath.c_str());
	system(qpath.toUtf8().data());

	logFileFullPath.append(filename);

	logFileSize = maxSize;

	Log(DEBUG, "Log file [%s] initialized with log level [%d]",
			logFileFullPath.c_str(), mLogLevel);
}

void PLog::PrintBanner(char* banner)
{
	Log(MSG, "///////////////////////////////////////////");
	Log(MSG, banner);
	Log(MSG, "///////////////////////////////////////////");
}

void PLog::Log(EPLOG loglevel, char* logmessage, ...)
{
	FILE* pLog;

	if (loglevel < mLogLevel)
		return;
	std::string strdatetime = GetCurrentDateTime("%x_%X");
	pthread_mutex_lock(&mutex_plog);
	pLog = fopen(logFileFullPath.c_str(), "a");

	if (pLog != NULL)
	{
		fprintf(pLog, "%s ", strdatetime.c_str());
#ifdef __WIN32
		fprintf(pLog, "[%d] ", pthread_self());
#else
		fprintf(pLog, "[%d] ", getpid()); //todo:
#endif

		switch (loglevel)
		{
		case DEBUG:
			fprintf(pLog, "[DEBUG] ");
			break;
		case INFO:
			fprintf(pLog, "[INFO ] ");
			break;
		case ERROR:
			fprintf(pLog, "[ERROR] ");
			break;
		default:
			break;

		}

		va_list args;
		va_start(args, logmessage);

		vsprintf(szBuffer, logmessage, args);

		fprintf(pLog, "%s\r\n", szBuffer);
		size_t filesize = ftell(pLog);
		fclose(pLog);
		//RotateFile(filesize);
		RotateToArchive(filesize);
	}
	pthread_mutex_unlock(&mutex_plog);
}

void PLog::RotateToArchive(size_t filesize)
{


	if (filesize >= logFileSize)
	{
		char cnt[3] =
		{ 0 };
		std::string archname;
		std::string fullArchNamePath;

		// moving all old archive
		for (int i = 5; i > 0; i--)
		{
			fullArchNamePath.clear();
			fullArchNamePath.append(logFileLocation).append(logFileName).append(
					"_ARC");
			;	//.append(itoa(i));
			sprintf(cnt, "%d", i);
			fullArchNamePath.append(cnt).append(".txt");

			//delete last archive
			if (i == 5)
				if (file_exists(fullArchNamePath) == true)
					remove(fullArchNamePath.c_str());

			// move old archive
			if (file_exists(fullArchNamePath) == true)
			{
				std::string fullArchNamePath_new;
				fullArchNamePath_new.append(logFileLocation).append(logFileName).append(
						"_ARC"); //.append(itoa(i));
				sprintf(cnt, "%d", (1 + i));
				fullArchNamePath_new.append(cnt).append(".txt");

				rename(fullArchNamePath.c_str(), fullArchNamePath_new.c_str()); //renaming log file at size limit
			}
		}

		// write new archive
		fullArchNamePath.clear();
		fullArchNamePath.append(logFileLocation).append(logFileName).append(
				"_ARC1.txt");

		rename(logFileFullPath.c_str(), fullArchNamePath.c_str()); //renaming log file at size limit

		FILE* pLog = fopen(logFileFullPath.c_str(), "a");
		if (pLog != NULL)
			fclose(pLog);

	}
}

