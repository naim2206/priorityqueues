//
// Created by Josean Camarena on 23/11/21.
//

#ifndef PRIORITYQUEUES_HEAP_H
#define PRIORITYQUEUES_HEAP_H

#include "stdlib.h"
#include "stdio.h"

typedef struct heap Heap;

Heap* newHeap(int initialCapacity);
int getCount(Heap *h);
void addElement(Heap *h, void* element, int (comp)(void*, void*));
void* removeElement(Heap *h, int (comp)(void*, void*));


#endif //PRIORITYQUEUES_HEAP_H
