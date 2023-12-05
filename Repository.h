#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Data.h"

class TaskRepository {
public:
    void addTask(const Task& task);
    void deleteTask(const std::string& title);
    void editTask(const std::string& title, const Task& newTask);
    std::vector<Task> searchTasks(const std::string& keyword);
    std::vector<Task> getTasksByTime(const std::string& timePeriod);
    std::vector<Task> getTasksByPriority();

private:
    std::vector<Task> tasks;
};

#endif // REPOSITORY_H

