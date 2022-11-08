// Task.cpp 

#include "Task.hpp"

std::tm GetCurrentDate() {
	std::time_t currentTime = time(0);
	std::tm currentDate;

	localtime_s(&currentDate, &currentTime);
	return currentDate;
}

Task::Task(std::string name, bool completed, std::tm dateCreated)
{
	m_Name = name;
	m_DateCreated = dateCreated;
	m_Completed = completed;
}

Task::Task(std::string name) {
	m_Name = name;
	m_DateCreated = GetCurrentDate();
}

std::string Task::GetDateCreatedStr() {
	std::string year = std::to_string(m_DateCreated.tm_year + 1900);
	std::string month = std::to_string(m_DateCreated.tm_mon + 1);
	std::string day = std::to_string(m_DateCreated.tm_mday);
	
	return month + "/" + day + "/" + year;
}
