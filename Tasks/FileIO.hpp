// FileIO.hpp
// Useful class for managing read/writing Task class to file

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "json.hpp"
#include "Task.hpp"

std::tm ParseDateData(std::string data);

class FileIO
{
public:
	FileIO();
	void WriteTaskData(std::map<TaskId, Task> activeTasks);
	void ReadTaskData(std::map<TaskId, Task>& activeTasks);
private:
	bool FileExists();

	std::string m_File = "data.txt";
};

extern FileIO g_FileIO;