// Task.cpp 

#include "Task.hpp"

std::tm GetCurrentDate() {
	std::time_t currentTime = time(0);
	std::tm currentDate;

	localtime_s(&currentDate, &currentTime);
	return currentDate;
}

// Override for Read/Write
Task::Task(const char* name, bool completed, std::tm dateCreated)
{
	m_Name = name;
	m_DateCreated = dateCreated;
	m_Completed = completed;
}

Task::Task(const char* name) {
	m_Name = name;
	m_DateCreated = GetCurrentDate();
}