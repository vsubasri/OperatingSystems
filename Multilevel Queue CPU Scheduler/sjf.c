/*
 * Name: Valli Subasri
 */
 
#include <stdio.h>
#include "schedule.h"

void sjf(queue_struct *queue) {
    int i,j;        //loop indices
    int n;          //total number of processes 
    int total=0;    //variable to hold total for wait time and turn around time
    int pos;
    process_struct temp;
    
    float avg_wt; //average wait time, average turn around time

    
    printf("\nEnter total number of processes for QUEUE %d:", queue->queue_id);
    scanf("%d",&queue->p);
    
    n = queue->p;

    printf("\nEnter Process Burst Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]:",i+1);
        queue->process[i].process_id = i+1;
        scanf("%d", &queue->process[i].bt);
    }
 
    //sorting burst time in ascending order using selection sort
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if((queue->process[j].bt) < (queue->process[pos].bt)) {
                pos = j;
            }
        }
        
        temp = queue->process[i];
        queue->process[i] = queue->process[pos];
        queue->process[pos] = temp;
    }

    queue->process[0].wt = 0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i = 1; i < n; i++) {
        queue->process[i].wt = 0;

        for (j = 0; j < i; j++) {
            queue->process[i].wt += queue->process[i].bt;
        }

        total+= queue->process[i].wt;
    }
 
    avg_wt = (float)total/n;      //average waiting time
 
    printf("\nProcess\t|Burst Time\t|Waiting Time");
    for(i = 0; i < n; i++) {
        printf("\np%d\t|%d\t\t|%d", queue->process[i].process_id, queue->process[i].bt, queue->process[i].wt);
    }
 
    printf("\n\nAverage Waiting Time = %.2f\n", avg_wt);
}
