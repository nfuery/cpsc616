#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main() {
    std::string command;
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
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
            std::cerr << "Fork failed\n";
            return 1;
        }
    }
    return 0;
}
