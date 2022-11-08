# Tasks - A simple, lightweight task manager

11/1/2022 - Initial Commit. Added Task class and started Manager. TODO: finish Manager, add gui

11/2/2022 - finsihed Manager class. Ported ImGui to the project. TODO: add config system, with file read/write

11/3/2022 - Added FileIO class, can now write to file. TODO: finish config system, need to finish reading from config

11/4/2022 - Finished FileIO class. You can now read/write to file when needed, meaning you can make tasks for another date and close the program. There was a weird bug based around reading the task names from file, but is now fixed by switching Task::m_Name type from const char* to std::string. Also added an override to default Task constructor, now allowing user to specify the date created and task status during object creation. TODO: Start implementing a way to show current tasks with ImGui.

11/5/2022 - (written before programming) It's a Saturday, not working on the program too much. Goals for today: Set up ImGui to look the way I want it to. Plan out a way to render current tasks.

Current progress on GUI: added a way to render every active task. still need to make it look pretty, but functionality comes first!
![Screenshot_20221105_023933](https://user-images.githubusercontent.com/117470530/200140444-0870bb7e-0889-4923-99f7-0b9dc46f7d19.png)

11/8/2022 - took a break over the weekend. Today I implemented Data parsing, so you can read/write the Date from the config file. I also FINALLY gave a function definition to GetDateCreatedStr (all it does is just return the date of which the task was created as an std::string). I had a very frustrating bug, but I fixed it eventually by checking out the call stack. I also finished the main part of the GUI now, the task entries now have their names, dates created, and checkboxes displayed. There are theoretically an infinite amount of tasks able to be made, and you can scroll in the application. TODO: Add a "Add Task" window for task creation.
