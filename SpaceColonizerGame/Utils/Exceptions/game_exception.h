/*
James Felts 2015
*/
//root of all exceptions used by the game

//to avoid turning this exception heirarchary into an inheritance graph due to inheiriting from the standard version of each exception AND this root exception
//no other exception type will inheirit from the standard exceptions but this one
#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H
#include <string>
#include <stdexcept>
namespace Exceptions
{
	class game_exception: 
		public std::exception
	{
	public:
		game_exception(const std::string msg, const std::string throwingFile, const std::string throwingFunction) noexcept;
		game_exception(const char* msg, const char* throwingFile, const char* throwingFunction) noexcept;
		//copy ctor
		game_exception(const game_exception& other)noexcept;
		//copy assign
		game_exception& operator=(const game_exception& other)noexcept 
		{
			if (this != &other)
			{
				m_msg = other.m_msg;
				m_throwingFile = other.m_throwingFile;
				m_throwingFunction = other.m_throwingFunction;
			}
			return *this;
		}
		virtual ~game_exception();
		virtual const char* what()const noexcept override{ return m_msg; }
		virtual const char* getThrowingFile()const noexcept { return m_throwingFile; }
		virtual const char* getThrowingFunction()const noexcept { return m_throwingFunction; }
	private:
		const char* m_throwingFile;
		const char* m_throwingFunction;
		const char* m_msg;
	};
}
#endif
