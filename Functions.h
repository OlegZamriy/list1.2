#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.h"
#include "Repository.h"

class TaskManager {
public:
    void addTask();
    void deleteTask();
    void editTask();
    void searchTasks();
    void displayTasksByTime();
    void displayTasksByPriority();

private:
    TaskRepository taskRepository;

    void displayTasks(const std::vector<Task>& tasks);
};

void displayMenu();
void displayMainMenu(TaskManager& taskManager); 

#endif 
