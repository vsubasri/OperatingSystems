#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void) {

    pid_t pids[3], grandchild, child_2;
    int i, status = 0;
    int n = 3;

    /* Start children. */
    for (i = 0; i < n; i++) {
      if ((pids[i] = fork()) < 0) {
        perror("fork");
         exit(pids[i]);
      } 
      else if (pids[i] == 0) {
        printf("From parent Process %d: child %d is created with PID %d\n", getppid(), i+1, getpid());
        if (i == 0) {
          grandchild = fork();
          if (grandchild < 0) {
              perror("fork");
              printf("Main function: Errno number is %d\n", errno);
              exit(pids[0]);
          } 
          else if (grandchild == 0){
            printf("From child 1: child 1.1 is created with PID %d\n", getpid());
          }
        }
        else if (i == 1) {
            child_2 = getpid();
        }
        else {
          printf("From child_3: Calling an external program B.out and leaving child_3\n");
          printf("From external program B:\n");

          execl("B.out", "B.out", NULL);
        }
        exit(0);
      }
      else {
        waitpid(child_2, &status, 0);
      }
    }

    return 0; 

}
