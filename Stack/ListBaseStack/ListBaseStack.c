#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack){
  pstack->head = NULL;
}


int SIsEmpty(Stack * pstack){
  if(pstack->head == NULL)
    return TRUE;
  else
    return FALSE;
}

void SPush(Stack * pstack, Data data){
  Node * newNode = (Node*)malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = pstack->head;

  pstack->head = newNode;
}

Data SPop(Stack * pstack){
  Data tData;
  Node * tNode;

  if(SIsEmpty(pstack)){
    printf("스택이 비었습니다.");
    exit(-1);
  }

  tData = pstack->head->data;
  tNode = pstack->head;

  pstack->head = pstack->head->next;
  free(tNode);
  return tData;
}

Data SPeek(Stack * pstack){
  if(SIsEmpty(pstack)){
    printf("스택이 비었습니다.");
    exit(-1);
  }

  return pstack->head->data;
}