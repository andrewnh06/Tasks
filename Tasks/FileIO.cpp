// FileIO.cpp

#include "FileIO.hpp"

std::tm ParseDateData(std::string data) {
	std::string s = data;
	std::string delimiter = "/";

	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back((token));
	}

	res.push_back((s.substr(pos_start)));
	std::tm ret = std::tm();

	ret.tm_mon = std::stoi(res[0]) - 1;
	ret.tm_mday = std::stoi(res[1]);
	ret.tm_year = std::stoi(res[2]) - 1900;

	return ret;
}

FileIO::FileIO() {
	if (!FileExists()) {
		std::cout << "[+] Data file not found! Creating one now..." << std::endl;

		std::ofstream file(m_File);
		file << "No data found!";
	}
}

void FileIO::WriteTaskData(std::map<TaskId, Task> activeTasks) {
	nlohmann::json j;
	for (auto& entry : activeTasks) {
		std::string name = entry.second.GetName();
		std::string completed = entry.second.m_Completed ? "Yes" : "No";
		std::string date = entry.second.GetDateCreatedStr();
		j.push_back(nlohmann::json::array({ entry.first, { {"name", name}, {"completed", completed},{"date", date} }}));
	}

	std::ofstream file(m_File);
	file << j;
	file.close();
}

void FileIO::ReadTaskData(std::map<TaskId, Task> &activeTasks) {
	std::ifstream file(m_File);
	nlohmann::json j = nlohmann::json::parse(file);

	std::map<TaskId, Task> writtenTasks;

	for (auto& entry : j) {
		bool completed = (entry[1]["completed"] == "Yes") ? true : false;
		std::string date = entry[1]["date"];
		std::string name = entry[1]["name"];

		std::cout << date << std::endl;

		TaskId id = entry[0];
		Task appendTask = Task(name, completed, ParseDateData(date));
		std::cout << appendTask.GetName() << std::endl;
		writtenTasks.insert({id, appendTask});
	}

	activeTasks = writtenTasks;
}

bool FileIO::FileExists() {
	std::ifstream file(m_File);
	return file.good();
}

FileIO g_FileIO = FileIO();