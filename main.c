#include <stdio.h>

#include "heap.h"

int compInts(void *a, void *b)
{
  int* ai = a;
  int* bi = b;

  return *ai - *bi;
}

int main() {

  int superArry[] = { -12, 2, 0, 21, -45, 13};

  Heap* h = newHeap( 10);

  for(int i=0; i < 6; i++)
    addElement(h, superArry+i, compInts);

  //printf("%d es el # de elementos\n", getCount(h));

  while(getCount(h) != 0)
  {
    printf("%d ", *(int*)removeElement(h, compInts));
  }


  return 0;
}
