#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string command;
    while (true) {
        cout << "Enter command: ";
        getline(cin, command);
        if (command == "exit") {
            break;
        }
        pid_t pid = fork();
        if (pid == 0) {
            execlp(command.c_str(), command.c_str(), NULL);
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            cerr << "Fork failed" << endl;
            return 1;
        }
    }
    return 0;
}
