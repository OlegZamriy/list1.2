#include <iostream>
#include "Functions.h"

int main() {
    TaskManager taskManager;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            taskManager.addTask();
            break;
        case 2:
            taskManager.deleteTask();
            break;
        case 3:
            taskManager.editTask();
            break;
        case 4:
            taskManager.searchTasks();
            break;
        case 5:
            taskManager.displayTasksByTime();
            break;
        case 6:
            taskManager.displayTasksByPriority();
            break;
        case 7:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
