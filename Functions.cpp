#include <iostream>
#include <algorithm>
#include "Functions.h"
#include "Constants.h"

void TaskManager::addTask() {
    Task newTask;
    std::cout << "Enter task title: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.title);
    std::cout << "Enter task priority (1 - Low, 2 - Medium, 3 - High): ";
    std::cin >> newTask.priority;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.description);
    std::cout << "Enter task due date and time (YYYY-MM-DD HH:mm): ";
    std::cin >> newTask.dateTime;

    taskRepository.addTask(newTask);
    std::cout << "Task added successfully!\n";
}

void TaskManager::deleteTask() {
    std::string title;
    std::cout << "Enter the title of the task to delete: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    taskRepository.deleteTask(title);
}

void TaskManager::editTask() {
    std::string title;
    std::cout << "Enter the title of the task to edit: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    Task newTask;
    std::cout << "Enter new task title: ";
    std::getline(std::cin, newTask.title);
    std::cout << "Enter new task priority (1 - Low, 2 - Medium, 3 - High): ";
    std::cin >> newTask.priority;
    std::cout << "Enter new task description: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.description);
    std::cout << "Enter new task due date and time (YYYY-MM-DD HH:mm): ";
    std::cin >> newTask.dateTime;

    taskRepository.editTask(title, newTask);
}

void TaskManager::searchTasks() {
    std::string keyword;
    std::cout << "Enter a keyword to search for tasks: ";
    std::cin.ignore();
    std::getline(std::cin, keyword);

    std::vector<Task> result = taskRepository.searchTasks(keyword);

    if (result.empty()) {
        std::cout << "No matching tasks found.\n";
    }
    else {
        displayTasks(result);
    }
}

void TaskManager::displayTasksByTime() {
    std::vector<Task> tasksByTime = taskRepository.getTasksByTime(TIME_PERIOD_ALL);
    displayTasks(tasksByTime);
}

void TaskManager::displayTasksByPriority() {
    std::vector<Task> tasksByPriority = taskRepository.getTasksByPriority();
    displayTasks(tasksByPriority);
}

void TaskManager::displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
    }
    else {
        for (const auto& task : tasks) {
            std::cout << "Title: " << task.title << "\n";
            std::cout << "Priority: " << task.priority << "\n";
            std::cout << "Description: " << task.description << "\n";
            std::cout << "Due Date and Time: " << task.dateTime << "\n";
            std::cout << "--------------------------\n";
        }
    }
}

void displayMenu() {
    std::cout << "1. Add Task\n";
    std::cout << "2. Delete Task\n";
    std::cout << "3. Edit Task\n";
    std::cout << "4. Search Tasks\n";
    std::cout << "5. Display Tasks by Time\n";
    std::cout << "6. Display Tasks by Priority\n";
    std::cout << "7. Exit\n";
}
