//
// Created by Josean Camarena on 23/11/21.
//

#ifndef PRIORITYQUEUES_PRIORITYQUEUE_H
#define PRIORITYQUEUES_PRIORITYQUEUE_H

#include "stdlib.h"
#include "heap.h"

typedef struct priorityQ PriorityQ;

PriorityQ* newPrioQ(int (comp)(void*, void*));
void enqueue(PriorityQ* q, void* element);
void* dequeue(PriorityQ* q);

#endif //PRIORITYQUEUES_PRIORITYQUEUE_H
