#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string description;
    bool isCompleted;
};

vector<Task> tasks;

void addTask()
{
    string description;
    cout << "Enter task description: ";
    cin.ignore(); // Ignore any leftover newline character from previous input
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully.\n"; // adding task to tasks vector
}

void viewTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks available.\n";
        return;
    }
    
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << (tasks[i].isCompleted ? "[Completed] " : "[Pending] ") << tasks[i].description << "\n";
    } // printing the tasks according to the completion.
}

void markTaskAsCompleted()
{
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks[taskNumber - 1].isCompleted = true; // updating a task to completed
        cout << "Task marked as completed.\n";
    }

    else
    {
        cout << "Invalid task number.\n";
    }
}

void removeTask()
{
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + taskNumber - 1); // removing the respective task user given
        cout << "Task removed successfully.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}



void displayMenu()
{
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    do
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
