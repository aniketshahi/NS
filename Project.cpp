         #include <iostream>
         #include <unistd.h>

         using namespace std;

         int main() {
            pid_t pid;

            pid = fork();
            if (pid == 0) {
               cout << "This is the child process" << endl;
            } else if (pid > 0) {
               cout << "This is the parent process" << endl;
            } else {
               cout << "Error: fork() failed" << endl;
            }
            return 0;
         }
