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
	class LogUtils
	{
	public:
		static LogUtils& getLog();
		void writeToLog(const char * str);
		virtual ~LogUtils();
	private:
		std::fstream m_logFile;
		std::mutex m_logFileMutex;
		const std::string m_file = "log.txt";
		LogUtils();
	};
}
#endif
