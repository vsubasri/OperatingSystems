/*
 * Name: Valli Subasri
 */
 
#include <stdio.h> 
#include "schedule.h"
 
void roundrobin(queue_struct *queue) { 
 
  int i,j;
  int n;                  //number of processes
  int time,remain;
  int flag=0;
  int q;                  //time quantum 
  
  int wait_time=0; 
  int turnaround_time=0;

  printf("\nEnter total number of processes for QUEUE %d:", queue->queue_id);
  scanf("%d",&n); 

  remain=n; 

  printf("\nEnter Process Burst Time\n");  
  for(i=0; i<n; i++) { 
    queue->process[i].process_id = i+1;
    printf("P[%d]:",i+1);
    scanf("%d", &queue->process[i].bt); 
    queue->process[i].rt = queue->process[i].bt;
    queue->process[i].at = 0; 
  } 


  printf("\n\nProcess\t|Turnaround Time\n"); 

  for(time=0,i=0;remain!=0;) { 
    
    if(queue->process[i].rt <= queue->q && queue->process[i].rt > 0) { 
      time += queue->process[i].rt; 
      queue->process[i].rt = 0; 
      flag = 1; 
    } 

    else if (queue->process[i].rt > 0) { 
      queue->process[i].rt -= queue->q; 
      time += queue->q; 
    } 

    if (queue->process[i].rt == 0 && flag == 1) { 
      remain--; 

      printf("P[%d]\t|%d\n", queue->process[i].process_id, time-queue->process[i].at); 
      
      turnaround_time += time - queue->process[i].at; 
      flag = 0; 
    } 

    if(i == n-1) {
      i=0; 
    }
    else if(queue->process[i+1].at<=time) {
      i++; 
    }
    else {
      i=0;
    } 
  } 
  printf("\nAvg Turnaround Time = %.2f \n",turnaround_time*1.0/n); 
  
}
