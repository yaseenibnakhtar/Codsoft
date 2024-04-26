#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int TaskID;

// Define a structure for tasks
struct Task {
    int ID;
    string description;
};

// Function to add a new task
void addTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                   WELCOME TO Your Task Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    Task task;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, task.description); // Get user input
    TaskID++; // Increment task ID

    // Write the task to the task.txt file
    ofstream write;
    write.open("task.txt", ios::app);
    write << "\n" << TaskID;
    write << "\n" << task.description;
    write.close();

    // Write the task ID to a separate file for later use
    write.open("TaskID.txt");
    write << TaskID;
    write.close();

    char ch;
    cout << "Do you want to add more tasks? y/n" << endl;
    cin >> ch;

    // If user wants to add another task, call the addTask() function recursively
    if (ch == 'y') {
        addTask();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// Function to print a task
void printTask(Task task) {
    cout << "\n\tTask ID: " << task.ID;
    cout << "\n\tDescription: " << task.description;
}

// Function to read tasks from the task.txt file and print them
void readTasks() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                   WELCOME TO Your Task Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    Task task;
    ifstream read;
    read.open("task.txt");
    cout << "\n\t------------------ Your current Tasks ------------------" << endl;
    
    // Read tasks from file and print them
    while (!read.eof()) {
        read >> task.ID;
        read.ignore();
        getline(read, task.description);
        printTask(task);
    }
    read.close();
}

// Function to search for a specific task
int searchTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                   WELCOME TO Your Task Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id;
    cout << "\n\tEnter task ID: ";
    cin >> id;
    Task task;
    ifstream read;
    read.open("task.txt");
    
    // Search for the task with the given ID
    while (!read.eof()) {
        read >> task.ID;
        read.ignore();
        getline(read, task.description);
        if (task.ID == id) {
            printTask(task);
            return id;
        }
    }
}

// Function to delete a task
void deleteTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                   WELCOME TO Your Task Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchTask();
    cout << "\n\tDo you want to delete this task? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Task task;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("task.txt");
        
        // Copy tasks to a temporary file, excluding the one to be deleted
        while (!read.eof()) {
            read >> task.ID;
            read.ignore();
            getline(read, task.description);
            if (task.ID != id) {
                tempFile << "\n" << task.ID;
                tempFile << "\n" << task.description;
            }
        }
        read.close();
        tempFile.close();
        
        // Replace original file with the temporary file
        remove("task.txt");
        rename("temp.txt", "task.txt");
        cout << "\n\tTask deleted successfully";
    }
    else {
        cout << "\n\tTask not deleted";
    }
}

// Function to update a task
void updateTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                   WELCOME TO Your Task Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchTask();
    cout << "\n\tDo you want to update this task? (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Task newData;
        cout << "\n\tEnter new task description: ";
        cin.get();
        getline(cin, newData.description);
        Task task;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("task.txt");
        
        // Update the task in the temporary file
        while (!read.eof()) {
            read >> task.ID;
            read.ignore();
            getline(read, task.description);
            if (task.ID != id) {
                tempFile << "\n" << task.ID;
                tempFile << "\n" << task.description;
            }
            else {
                tempFile << "\n" << task.ID;
                tempFile << "\n" << newData.description;
            }
        }
        read.close();
        tempFile.close();
        
        // Replace original file with the temporary file
        remove("task.txt");
        rename("temp.txt", "task.txt");
        cout << "\n\tTask updated successfully";
    }
    else {
        cout << "\n\tTask not updated";
    }
}

int main()
{
    system("cls");
    system("Color E0"); // "Color XY", X - backgroung color, Y - text color
    system("title TaskManager @copyassignment");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                   WELCOME TO Your Task Manager                       *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
    ifstream read;
    read.open("TaskID.txt");
    if (!read.fail()) {
        read >> TaskID;
    }
    else {
        TaskID = 0;
    }
    read.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1. Add a new task";
        cout << "\n\t2. See all tasks";
        cout << "\n\t3. Search for a task";
        cout << "\n\t4. Delete a task";
        cout << "\n\t5. Update a task";

        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            readTasks();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            updateTask();
            break;
        }
    }

    return 0;
}
