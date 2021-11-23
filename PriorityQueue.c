//
// Created by Josean Camarena on 23/11/21.
//

#include "PriorityQueue.h"

struct priorityQ {
  int (*comp)(void*, void*);
  Heap *h;
};


PriorityQ* newPrioQ(int (comp)(void*, void*))
{
  PriorityQ* q = malloc(sizeof(PriorityQ));
  q->comp = comp;
  q->h = newHeap(10);
  return q;
}

void enqueue(PriorityQ* q, void* element)
{
  addElement(q->h, element, q->comp);
}

void* dequeue(PriorityQ* q)
{
  return removeElement(q->h, q->comp);
}