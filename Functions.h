#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.h"
#include "Repository.h"

void displayMenu(); 

class TaskManager {
public:
    void addTask();
    void deleteTask();
    void editTask();
    void searchTasks();
    void displayTasksByTime();
    void displayTasksByPriority();
    void displayTasksGraphical();

private:
    TaskRepository taskRepository;

    void displayTasks(const std::vector<Task>& tasks);
    void drawTask(const Task& task);
};

#endif // FUNCTIONS_H
