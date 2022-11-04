// Manager.hpp

#pragma once

#include <map>

#include "Task.hpp"

#define MAX_TASK_ID 99

class Manager
{
public:
	bool AddTask(Task task);							// Push task to m_ActiveTasks. Returns false if more tasks defined than MAX_TASK_ID	
	TaskId CalculateNextId();							// Calculate the next unused TaskId

	std::map<TaskId, Task> GetActiveTasks() { return m_ActiveTasks; }
private:
	std::map<TaskId, Task> m_ActiveTasks = {};			// Map of all active tasks: key is TaskId, value is Task
};

extern Manager g_Manager;