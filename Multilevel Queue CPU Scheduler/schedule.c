/*
 * Name: Valli Subasri
 */
 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "schedule.h"

int main (int argc, char *argv[]) {

	if (argc != 2) {
		printf("Usage: schedule 3\n");
	}

	int i, j; 
	int q = atoi(argv[1]); 					//number of queues 
	queue_struct queues[q];

  for (i = 0; i < q; i++) {
    queues[i].queue_id = i+1;
    printf("Enter priority for q%d:", i+1);
    scanf("%d",&queues[i].priority);
    printf("Enter scheduling method for q%d (1 for fcfs, 2 for roundrobin or 3 for sjf):", i+1);
    scanf("%d",&queues[i].scheduling_method);
  }

   //sort queues based on priority

	int pos;
	queue_struct temp;

    for(i = 0; i < q; i++) {
        pos=i;
        for(j=i+1;j<q;j++)
        {
            if(queues[j].priority < queues[pos].priority)
                pos=j;
        }
 
        temp = queues[i];
        queues[i] = queues[pos];
        queues[pos] = temp;
 
    }
	
	for (i = 0; i < q; i++) {
		if (queues[i].scheduling_method == 1) {
			fcfs(&queues[i]);
		}
		if (queues[i].scheduling_method == 2) {
        printf("\nEnter Time Quantum: "); 
        scanf("%d",&queues[i].q);
			  roundrobin(&queues[i]);
		}
		if (queues[i].scheduling_method == 3) {
			sjf(&queues[i]);
		}
	}

	return 0;

}

