#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main(void) {
  List list;
  int data;
  ListInit(&list);

  LInsert(&list, 111);
  LInsert(&list, 222);
  LInsert(&list, 333);
  LInsert(&list, 444);
  LInsert(&list, 555);
  LInsert(&list, 666);
  LInsert(&list, 777);


  if(LFirst(&list, &data)){
    printf("%d\n", data);

    while(LNext(&list, &data)){
      printf("%d\n", data);
    }

    while(LPrevious(&list, &data)){
      printf("%d\n", data);
    }

  }

  if(LFirst(&list, &data)){
      LRemove(&list);

    while(LNext(&list, &data)){
      LRemove(&list);
    }
  }


  return 0;
}
