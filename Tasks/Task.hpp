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
	Task(const char* name);

	std::tm GetDateCreated() { return m_DateCreated; }
	const char* GetDateCreatedStr();
	const char* GetName() { return m_Name; }
	bool GetCompleted() { return m_Completed; }
private:
	const char* m_Name = {};
	std::tm m_DateCreated = {};
	bool m_Completed = false;
};