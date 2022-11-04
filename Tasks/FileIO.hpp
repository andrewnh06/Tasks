#pragma once

#include <fstream>
#include <iostream>
#include <map>

#include "json.hpp"
#include "Task.hpp"
#include "Manager.hpp"

class FileIO
{
public:
	FileIO();
	void WriteTaskData(std::map<TaskId, Task> activeTasks);
private:
	bool FileExists();

	std::string m_File = "data.txt";
};

extern FileIO g_FileIO;