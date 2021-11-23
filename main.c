#include <stdio.h>

#include "PriorityQueue.h"

struct alumno
{
  int id;
  float calificacion;
};

int compInts(void *a, void *b)
{
  int* ai = a;
  int* bi = b;

  return *ai - *bi;
}

int compAlumnos(void *a, void *b)
{
  struct alumno *ap = a;
  struct alumno *bp = b;

  return ap->id - bp->id;
}


int main() {

  struct alumno alumnos_array[4];

  alumnos_array[0].id = 10;
  alumnos_array[0].calificacion = 9.8;

  alumnos_array[1].id = 11;
  alumnos_array[1].calificacion = 5.9999;

  alumnos_array[2].id = 12;
  alumnos_array[2].calificacion = 8;


  PriorityQ* revisionDeProjectos = newPrioQ(compAlumnos);

  enqueue(revisionDeProjectos, alumnos_array);
  enqueue(revisionDeProjectos, alumnos_array+1);
  enqueue(revisionDeProjectos, alumnos_array+2);

  printf("el siguiente alumno por calificar es %d\n", ((struct alumno*)dequeue(revisionDeProjectos))->id);
  printf("el siguiente alumno por calificar es %d\n", ((struct alumno*)dequeue(revisionDeProjectos))->id);
  printf("el siguiente alumno por calificar es %d\n", ((struct alumno*)dequeue(revisionDeProjectos))->id);

  /*
  for(int i=0; i < 6; i++)
    addElement(h, superArry+i, compInts);

  //printf("%d es el # de elementos\n", getCount(h));

  while(getCount(h) != 0)
  {
    printf("%d ", *(int*)removeElement(h, compInts));
  }*/


  return 0;
}
