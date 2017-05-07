/*
 * Name: Valli Subasri
 * Student Number: 250697148
 *
 * WITHOUT MUTUAL EXCLUSION IMPLEMENTED
 *
 */
 
#include <stdio.h>      
#include <stdlib.h>

int critical_section (int loop_limit, int who_called) {
    printf("Process\t| Loop Index\n");
    int i;
    for (i =0; i < loop_limit; i++){
        printf("P[%d]\t|\t%d\n", who_called, i);
    }
    sleep(2);
    printf("Returning to caller process x\n"); //x is the caller process
    return 0;
}

int main() {
    //parent making 9 children
    printf("Parent pid: %d\n", getpid());
    int ps[9];
    int j, l;

    for (j = 0; j < 9; j++){
        if (fork() == 0) {       
            ps[j] = getpid();
            printf("\nChild pid: %d from pid %d\n", getpid(), getppid());
            sleep(2);
            critical_section(50, j+1);
            exit(0);
        }
    }

    for (l = 0; l < 9; l++) {
        wait(NULL);
    }

    
    exit(0);
}
