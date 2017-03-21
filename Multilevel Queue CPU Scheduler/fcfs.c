/*
 * Name: Valli Subasri
 */

#include <stdio.h>
#include "schedule.h"
 
void fcfs(queue_struct *queue) {
    int n;                  //number of processes
    int avwt=0;     //average wait/turn around time 
    int i,j;                //loop indices 

    printf("\nEnter total number of processes for QUEUE %d:", queue->queue_id);
    scanf("%d",&n);

    queue->q = n;
 
    printf("\nEnter Process Burst Time\n");
    for(i = 0; i < n; i++) {
        queue->process[i].process_id = i+1;
        printf("P[%d]:",i+1);
        scanf("%d", &queue->process[i].bt);
    }

     queue->process[0].wt=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for (i = 1; i < n; i++) {
        queue->process[i].wt = 0;
        for(j = 0; j < i; j++) {
            queue->process[i].wt += queue->process[j].bt;
        }
    }
 
    printf("\nProcess\t|Burst Time\t|Waiting Time");
 
    //calculating turnaround time
    for(i = 0; i < n; i++) {
        avwt += queue->process[i].wt;
        printf("\nP[%d]\t|%d\t\t|%d", queue->process[i].process_id, queue->process[i].bt, queue->process[i].wt);
    }
 
    avwt /= i;

    printf("\n\nAverage Waiting Time: %d\n", avwt);
 
}
