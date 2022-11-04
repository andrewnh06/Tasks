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
		std::string completed = entry.second.GetCompleted() ? "Yes" : "No";
		std::string date = "undefined";
		j.push_back(nlohmann::json::array({ entry.first, {{"completed", completed},{"date", date}} }));
	}

	std::ofstream file(m_File);
	file << j;
	file.close();
}

bool FileIO::FileExists() {
	std::ifstream file(m_File);
	return file.good();
}

FileIO g_FileIO = FileIO();