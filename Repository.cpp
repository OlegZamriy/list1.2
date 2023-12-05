#include "Repository.h"
#include <iostream>
#include <algorithm>



void TaskRepository::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskRepository::deleteTask(const std::string& title) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [&title](const Task& task) {
        return task.title == title;
        });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task deleted successfully!\n";
    }
    else {
        std::cout << "Task not found.\n";
    }
}

void TaskRepository::editTask(const std::string& title, const Task& newTask) {
    for (auto& task : tasks) {
        if (task.title == title) {
            task = newTask;
            std::cout << "Task edited successfully!\n";
            return;
        } 
    }

    std::cout << "Task not found.\n";
}

std::vector<Task> TaskRepository::searchTasks(const std::string& keyword) {
    std::vector<Task> result;

    for (const auto& task : tasks) {
        if (task.title.find(keyword) != std::string::npos ||
            task.description.find(keyword) != std::string::npos) {
            result.push_back(task);
        }
    }

    return result;
}

std::vector<Task> TaskRepository::getTasksByTime(const std::string& timePeriod) {
    return tasks;
}

std::vector<Task> TaskRepository::getTasksByPriority() {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
        });

    return sortedTasks;
}
