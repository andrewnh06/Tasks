# Tasks - A simple, lightweight task manager

11/1/2022 - Initial Commit. Added Task class and started Manager. TODO: finish Manager, add gui

11/2/2022 - finsihed Manager class. Ported ImGui to the project. TODO: add config system, with file read/write

11/3/2022 - Added FileIO class, can now write to file. TODO: finish config system, need to finish reading from config

11/4/2022 - Finished FileIO class. You can now read/write to file when needed, meaning you can make tasks for another date and close the program. There was a weird bug based around reading the task names from file, but is now fixed by switching Task::m_Name type from const char* to std::string. Also added an override to default Task constructor, now allowing user to specify the date created and task status during object creation. TODO: Start implementing a way to show current tasks with ImGui.

11/5/2022 - (written before programming) It's a Saturday, not working on the program too much. Goals for today: Set up ImGui to look the way I want it to. Plan out a way to render current tasks.
