// Manager.hpp
// Holds array of all active tasks

#pragma once

#include <map>

#include "Task.hpp"
#include "FileIO.hpp"

#define MAX_TASK_ID 99

class Manager
{
public:
	bool AddTask(Task task);							// Push task to m_ActiveTasks. Returns false if more tasks defined than MAX_TASK_ID	
	TaskId CalculateNextId();							// Calculate the next unused TaskId

	std::map<TaskId, Task> GetActiveTasks() { return m_ActiveTasks; }
	Task* GetTaskPtr(TaskId id) { return &m_ActiveTasks.find(id)->second; }

	void SaveTasksToConfig() { g_FileIO.WriteTaskData(m_ActiveTasks); }
	void LoadTasksFromConfig() { g_FileIO.ReadTaskData(m_ActiveTasks); }
private:
	std::map<TaskId, Task> m_ActiveTasks = {};			// Map of all active tasks: key is TaskId, value is Task
};

extern Manager g_Manager;