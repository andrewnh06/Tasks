#include "Manager.hpp"

TaskId Manager::CalculateNextId() {
	for (TaskId i = 0; i < MAX_TASK_ID; i++) {
		bool found = false;
		for (auto& entry : m_ActiveTasks) {
			if (i == entry.first) {
				found = true;
			}
		}
		if (!found)
			return i;
	}
}

bool Manager::AddTask(Task task) {
	TaskId desiredTaskId = CalculateNextId();
	if (desiredTaskId > MAX_TASK_ID)
		return false;

	m_ActiveTasks.insert( { desiredTaskId, task } );
	return true;
}

Manager g_Manager = Manager();