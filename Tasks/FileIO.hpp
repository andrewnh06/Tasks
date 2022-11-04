// FileIO.hpp
// Useful class for managing read/writing Task class to file

#pragma once

#include <fstream>
#include <iostream>
#include <map>

#include "json.hpp"
#include "Task.hpp"

class FileIO
{
public:
	FileIO();
	void WriteTaskData(std::map<TaskId, Task> activeTasks);
	std::map<TaskId, Task> ReadTaskData();
private:
	bool FileExists();

	std::string m_File = "data.txt";
};

extern FileIO g_FileIO;