#include <sys/wait.h>   // Header for wait functions
#include <unistd.h>     // Header for fork and execlp functions
#include <iostream>     
#include <string>       

using namespace std;    

int main() {
    string command;     // Declare a string variable to store user input

    while (true) {      // Start loop
        cout << "Enter command: ";  // Prompt the user to enter a command
        getline(cin, command);      // Read a line of input from the user and store it in 'command'

        if (command == "exit") {    // If the user enters "exit," exit the loop
            break;
        }

        pid_t pid = fork();         // Create a child process using 'fork'

        if (pid == 0) {             // In the child process
            execlp(command.c_str(), command.c_str(), NULL);  // Execute the command entered by the user
            exit(EXIT_FAILURE);     // If execlp fails, exit the child process with a failure status
        } else if (pid > 0) {        // In the parent process
            wait(NULL);             // Wait for the child process to complete
            cout << "Unknown command" << endl;  // Display a message indicating an unknown command
        } else {                     // If 'fork' fails to create a child process
            cerr << "Fork failed" << endl;  // Display an error message
            return 1;              // Exit the program with an error status
        }
    }

    return 0;  // Exit the program with a success status
}
