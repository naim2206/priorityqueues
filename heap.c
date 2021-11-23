//
// Created by Josean Camarena on 23/11/21.
//

#include "heap.h"

struct heap
{
  void **array;
  int capacity;
  int count;
};

Heap* newHeap(int initialCapacity)
{
  Heap* h = malloc(sizeof(Heap));

  h->array = malloc(sizeof(void*) * initialCapacity);
  h->capacity = initialCapacity;
  h->count = 0;

  return h;
}

int getParent(int index)
{
  return (index -1)/2;
}

void swap(void **a, void **b)
{
  void* temp = *a;
  *a = *b;
  *b = temp;
}

void addElement(Heap *h, void* newElement, int (comp)(void*, void*))
{
  // primero revisamos si tenemos espacio
  if(h->count == h->capacity)
  {
    printf("UPS! se nos acabo el espacio :(\n");
    h->capacity = h->capacity * 2;
    h->array = realloc(h->array, h->capacity * sizeof(void*));
  }
  // insertamos el nuevo elemento al final del monticulo
  h->array[h->count] = newElement;
  int newIndex = h->count;
  int parent = getParent(newIndex);
  // mientras no se respete la caracte. de monticulo, haceAmos swap con el padre
  // heapify up
  while(comp(h->array[parent], h->array[newIndex]) > 0)
  {
    swap(&h->array[newIndex], &h->array[parent]);
    newIndex = parent;
    parent = getParent(parent);
  }
  h->count++;
}

void* removeElement(Heap *h, int (comp)(void*, void*))
{
  // regresamos el elemento que esta en 0 SIEMPRE
  if(h->count == 0)
    return NULL; // return h->array[0]

  void* toRemove = h->array[0];

  // heapify down
  h->count--;
  int newIndex = 0;
  h->array[newIndex] = h->array[h->count]; // aqui YA se respeta la topologia de un monticulo.

  int lIndex = (newIndex*2) + 1;
  int rIndex = (newIndex*2) + 2;

  // que nos falta respetar?
  // primero tenemos que ver si YA se respeta la condicion de heap

  while( (lIndex < h->count && comp(h->array[newIndex], h->array[lIndex]) > 0) ||
         (rIndex < h->count && comp(h->array[newIndex], h->array[rIndex]) > 0)
  ){
    int smallest = lIndex;
    if(rIndex < h->count && comp(h->array[lIndex], h->array[rIndex]) > 0)
      smallest = rIndex;
    swap(&h->array[newIndex], &h->array[smallest]);

    newIndex = smallest;
    lIndex = (newIndex*2) + 1;
    rIndex = (newIndex*2) + 2;
  }

  return toRemove;
}

int getCount(Heap *h)
{
  return h->count;
}

