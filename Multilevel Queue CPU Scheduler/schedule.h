/*
 * Name: Valli Subasri
 */
 
typedef struct { 
	int process_id, at, bt, wt, tat, rt; 
}process_struct;

typedef struct {
	int queue_id, priority, p; //number of processes in queue
	int scheduling_method, q; //1 = fcfs, 2 = rr, 3 = sjf
	process_struct process[10];
}queue_struct;

void sjf(queue_struct *queue);
void roundrobin(queue_struct *queue);
void fcfs(queue_struct *queue);

extern queue_struct queues[];

