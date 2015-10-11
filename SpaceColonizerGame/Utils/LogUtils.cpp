/*
James Felts 2015
*/
#include "LogUtils.h"

using std::string;

Utils::LogUtils::LogUtils()
{
	m_logFile.open(m_file,m_logFile.out);
}

std::string Utils::LogUtils::getLogLevelString(const LogLevel level) const noexcept
{
	if (level == Info)
	{
		return "[Info]";
	}
	else if (level == Warning)
	{
		return "[Warning]";
	}
	else if(level == Error)
	{
		return "[Error]";
	}
	else
	{
		return "[Critical]";
	}
}

Utils::LogUtils& Utils::LogUtils::getLog()
{
	static Utils::LogUtils m_log;
	return m_log;
}

void Utils::LogUtils::writeToLog(const char* msg, const char* file, const char* function, const LogLevel level, const char* exceptFile, const char* exceptFunction)
{
	m_logFileMutex.lock();
	if (m_logFile.is_open())
	{
		string toLog;
		toLog.append(getLogLevelString(level));
		toLog.push_back(':');
		toLog.append(getCurTimeUTC());
		toLog.push_back(':');
		toLog.append(file);
		toLog.push_back(':');
		toLog.append(function);
		toLog.push_back(':');
		toLog.append(msg);

		toLog.push_back(':');
		toLog.append(exceptFile);
		toLog.push_back(':');
		toLog.append(exceptFunction);
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

#define BUFFERSIZE 100
std::string Utils::LogUtils::getCurTimeUTC() const noexcept
{
	string ret;
	char buf[BUFFERSIZE] = "";
	struct tm newTime;

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

	ret = string(buf);
	return ret;
}
