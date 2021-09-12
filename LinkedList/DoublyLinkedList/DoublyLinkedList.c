#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void ListInit(List * plist){
  plist->head = (Node*)malloc(sizeof(Node));
  plist->tail = (Node*)malloc(sizeof(Node));

  plist->head->next = plist->tail;
  plist->tail->prev = plist->head;

  plist->numOfData = 0;
}

void LInsert(List * plist, Data data){
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  plist->tail->prev->next = newNode;
  newNode->prev = plist->tail->prev;
  newNode->next = plist->tail;
  plist->tail->prev = newNode;
  
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata){
  if(plist->head->next == plist->tail)
    return FALSE;

  plist->cur = plist->head->next;
  *pdata = plist->cur->data;
  return TRUE;
}

int LNext(List * plist, Data * pdata){
  if(plist->cur->next == plist->tail)
    return FALSE;

  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;

  return TRUE;
}

int LPrevious(List * plist, Data * pdata){
  if(plist->cur->prev == NULL || plist->cur->prev == plist->head)
    return FALSE;

  plist->cur = plist->cur->prev;
  *pdata = plist->cur->data;

  return TRUE;
}

Data LRemove(List * plist){
  Node * temp = plist->cur;
  Data data = plist->cur->data;
  plist->cur->prev->next = plist->cur->next;
  plist->cur->next->prev = plist->cur->prev;
  plist->cur = plist->cur->prev;

  free(temp);
  (plist->numOfData)--;
  printf("메모리 해제!\n");

  return data;
}

int LCount(List * plist){
  return plist->numOfData;
}