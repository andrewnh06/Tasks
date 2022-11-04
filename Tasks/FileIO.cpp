// FileIO.cpp

#include "FileIO.hpp"

FileIO::FileIO() {
	if (!FileExists()) {
		std::cout << "[+] Data file not found! Creating one now..." << std::endl;
	}
}

void FileIO::WriteTaskData(std::map<TaskId, Task> activeTasks) {
	nlohmann::json j;
	for (auto& entry : activeTasks) {
		std::string name = entry.second.GetName();
		std::string completed = entry.second.GetCompleted() ? "Yes" : "No";
		std::string date = "undefined";
		j.push_back(nlohmann::json::array({ entry.first, { {"name", name}, {"completed", completed},{"date", date} }}));
	}

	std::ofstream file(m_File);
	file << j;
	file.close();
}

std::map<TaskId, Task> FileIO::ReadTaskData() {
	std::ifstream file(m_File);
	nlohmann::json j = nlohmann::json::parse(file);

	std::map<TaskId, Task> writtenTasks;

	for (auto& entry : j) {
		bool completed = (entry[1]["completed"] == "Yes") ? true : false;
		std::string date = entry[1]["date"];
		std::string name = entry[1]["name"];
		const char* nameChar = name.c_str();

		TaskId id = entry[0];
		Task appendTask = Task(nameChar, completed, GetCurrentDate());
		std::cout << appendTask.GetName() << std::endl;
		writtenTasks.insert({id, appendTask});
	}

	return writtenTasks;
}

bool FileIO::FileExists() {
	std::ifstream file(m_File);
	return file.good();
}

FileIO g_FileIO = FileIO();