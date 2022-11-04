#include "GUI.hpp"
#include "Manager.hpp"

int main() {
	// RenderGUI();

	g_Manager.LoadTasksFromConfig();

	/*Task a = "Dishes";
	Task b = "Laundry";
	Task c = "School";
	Task d = "Homework";

	g_Manager.AddTask(a);
	g_Manager.AddTask(b);
	g_Manager.AddTask(c);
	g_Manager.AddTask(d);

	g_Manager.SaveTasksToConfig();*/

	for (auto& entry : g_Manager.GetActiveTasks()) {
		std::cout << entry.second.GetName() << std::endl;
	}

	system("pause");
}