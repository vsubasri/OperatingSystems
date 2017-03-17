/*
 * Name: Valli Subasri
 * Student Number: 250697148
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void) {

    pid_t pids[3], grandchild;
    int i;
    int n = 3;

    //create children and grandchild
    for (i = 0; i < n; i++) {
      //error creating children
      if ((pids[i] = fork()) < 0) {
         perror("fork");
         exit(pids[i]);
      } 

      //child process
      else if (pids[i] == 0) {
        printf("From parent Process %d: child %d is created with PID %d\n", getppid(), i+1, getpid());
        //create child 1
        if (i == 0) {
          //create grandchild 1
          grandchild = fork();
          if (grandchild < 0) {
              perror("fork");
              printf("Main function: Errno number is %d\n", errno);
              exit(pids[0]);
          } 
          else if (grandchild == 0){
            printf("From child 1: child 1.1 is created with PID %d\n", getpid());
          }
          else {
                wait(NULL);
          }
        }
        //child 2 waits for child 3
        else if (i == 1) {
                printf("From parent Process %d: Waiting for child 2 to complete before creating child 3\n", getppid());                         
        }
        //child 3 opens up external program B 
        else {
          printf("From child_3: Calling an external program B.out and leaving child 3\n");
          printf("From external program B:\n");

          //opens external program B
          execl("B.out", "B.out", NULL);
        }
        exit(0);
      }

      //parent waits for child process to terminate before execution
      else {
        wait(NULL);   
      }
    }

    return 0; 

}
Contact GitHub API Training Shop Blog About
© 2017 GitHub, Inc. Terms Privacy Security Status Help
