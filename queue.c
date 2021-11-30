#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(empty(q)){
		q->proc[0] = proc;
		q->size = 1;
	}
	else{
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/*
	if(empty(q)){
		return NULL;
	}	*/
	
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	int index = 0;
	uint32_t max_priority =  q->proc[0]->priority;
	for(int i = 0 ; i< q->size; i++){		/////// Find the pcb with highest priority and its index
		if(q->proc[i]->priority > max_priority){
			index = i;
			max_priority = q->proc[i]->priority;
		}
	}		
	for (int i = index; i < q->size -1; i++){		//////// Remove it from the queue and decrease the size by 1
		q->proc[i] = q->proc[i+1];					//////// If the highest priority is the last pcb -> no loop
	}
	q->size--;
	return q->proc[index];
}

