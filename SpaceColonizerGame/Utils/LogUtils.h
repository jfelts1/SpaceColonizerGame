/*
James Felts 2015
*/
#ifndef LOGUTILS_H
#define LOGUTILS_H
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <mutex>
#include <ctime>
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
		static LogUtils& getLog();
		void writeToLog(const char* msg, const char* file, const char* function, const LogLevel level,const char* exceptFile = "",const char* exceptFunction = "");
		virtual ~LogUtils();
		std::string getCurTimeUTC()const noexcept;
	private:
		std::fstream m_logFile;
		std::mutex m_logFileMutex;
		const std::string m_file = "log.txt";
		LogUtils();
		std::string getLogLevelString(const LogLevel level)const noexcept;
	};
}
#endif
