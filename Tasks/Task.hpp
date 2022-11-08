#pragma once

// Task.hpp
// Base class for the whole program

#include <iostream>
#include <time.h>

std::tm GetCurrentDate();

typedef int TaskId;

class Task
{
public:
	// Override for read/write
	Task(std::string name, bool completed, std::tm dateCreated);
	Task(std::string name);

	std::tm GetDateCreated() { return m_DateCreated; }
	const char* GetDateCreatedStr();
	std::string GetName() { return m_Name; }
	bool m_Completed = false;
private:
	std::string m_Name = {};
	std::tm m_DateCreated = {};
};