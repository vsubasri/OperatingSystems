/*
 * Name: Valli Subasri
 * Student Number: 250697148
 * 
 * SEMAPHORE WITH MUTUAL EXCLUSION IMPLEMENTED 
 *
 */

#include <stdio.h>      
#include <stdlib.h>

typedef int *semaphore;
semaphore me;       // Mutual Exclusion semaphore

semaphore make_sem() {
    int *sem;

    sem = calloc(2,sizeof(int));
    pipe(sem);
    return sem;
}

void WAIT(semaphore s) {
    int junk;

    if (read(s[0], &junk, 1) <=0) {   // it blocks if pipe is empty
      fprintf(stderr, "ERROR : wait\n");
       exit(1);
       }
}

void SIGNAL(semaphore s) {
    if (write(s[1], "x", 1) <=0) {
      fprintf(stderr, "ERROR : signal\n");
       exit(1);
       }
}


int critical_section (int loop_limit, int who_called) {
    printf("\nChild pid: %d from pid %d\n", getpid(), getppid());
    printf("Process\t| Loop Index\n");
    int i;
    for (i =0; i < loop_limit; i++){
        printf("P[%d]\t|\t%d\n", who_called, i);
    }
    printf("Returning to caller process x\n"); //x is the caller process
    return 0;
}

void process(int i) {
      WAIT(me); 
      printf("\nEntering critical section of process %d:", i);
      sleep(2);
      critical_section(50, i);
      sleep(2);
      printf("Exiting critical section of process %d\n",i);
      SIGNAL(me); 
      sleep(1);  
}


int main() {

    me = make_sem();
    SIGNAL(me);    //  initialize to 1 sem me semaphore

    //parent making 9 children
    printf("Parent pid: %d\n", getpid());
    int ps[9];
    int j, l;

    for (j = 0; j < 9; j++){
        if (fork() == 0) {       
            ps[j] = getpid();
            process(j+1);
            exit(0);
        }
    }

    for (l = 0; l < 9; l++) {
        wait(NULL);
    }

    
    exit(0);
}
