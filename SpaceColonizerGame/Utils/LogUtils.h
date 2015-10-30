/*
James Felts 2015
*/
#ifndef LOGUTILS_H
#define LOGUTILS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4265)
#endif
#include <mutex>
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#include <ctime>
#include <cstring>
#define GET_LOG Utils::LogUtils::getLog()

namespace Utils
{
	enum LogLevel
	{
		Info,
		Warning,
		Error,
		Critical
	};

	class LogUtils
	{
	public:
		LogUtils(const LogUtils& orig) = delete;
		LogUtils& operator=(const LogUtils& orig) = delete;
		static LogUtils& getLog();
		void writeToLog(const char* msg, const char* file, const char* function, const LogLevel level,const char* exceptFile = "",const char* exceptFunction = "");
		virtual ~LogUtils();
		std::string getCurTimeUTC()const noexcept;
	private:
		std::fstream m_logFile;
		std::mutex m_logFileMutex;
		const std::string m_file = "log.log";
		LogUtils();
		std::string getLogLevelString(const LogLevel level)const noexcept;
	};
}
#endif
