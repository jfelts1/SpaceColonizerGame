/*
James Felts 2015
*/
#include "LogUtils.h"

using std::string;

Utils::LogUtils::LogUtils()
{
	m_logFile.open(m_file,m_logFile.out);
}


Utils::LogUtils& Utils::LogUtils::getLog()
{
	static Utils::LogUtils m_log;
	return m_log;
}

#define BUFFERSIZE 100
void Utils::LogUtils::writeToLog(const char* str)
{
	m_logFileMutex.lock();
	if (m_logFile.is_open())
	{
		string toLog;
		char buf[BUFFERSIZE] = "";
		struct tm newTime;
		//apprantly there is no safe time handling standard in C or C++
#ifdef _WIN32
		__int64 ltime;
		_time64(&ltime);
		_gmtime64_s(&newTime, &ltime);
		asctime_s(buf, BUFFERSIZE, &newTime);
#else
		time_t ltime;
		time(&ltime);
		asctime_r(gmtime_r(&ltime, &newTime), buf);
#endif
		//removing a newline that is ugly
		char* nl = strrchr(buf, '\n');
		*nl = '\0';

		toLog = string(buf);
		toLog.push_back(':');
		toLog.append(str);
		m_logFile.write(toLog.c_str(), toLog.size());
	}
	else
	{
		std::cerr << "log file not available" << std::endl;
	}
	m_logFileMutex.unlock();
}

Utils::LogUtils::~LogUtils()
{
	m_logFile.close();
}
