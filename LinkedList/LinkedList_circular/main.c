#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

Data NightDuty(List * plist, char * name, int day);
void ShowInfo(Member * temp);

int main(void) {
  List list;
  Member * temp;

  ListInit(&list);

  temp = (Member*)malloc(sizeof(Member));
  temp->personalNum = 11111;
  strcpy(temp->name, "Won");
  LInsert(&list, temp);

  temp = (Member*)malloc(sizeof(Member));
  temp->personalNum = 22222;
  strcpy(temp->name,"Min");
  LInsert(&list, temp);

  temp = (Member*)malloc(sizeof(Member));
  temp->personalNum = 33333;
  strcpy(temp->name, "Su");
  LInsert(&list, temp);

  temp = (Member*)malloc(sizeof(Member));
  temp->personalNum = 44444;
  strcpy(temp->name, "An");
  LInsert(&list, temp);

  temp = NightDuty(&list, "An", 2);
  ShowInfo(temp);

  
  return 0;
}

Data NightDuty(List * plist, char * name, int day){
  int i, num;

  num = LCount(plist);
  Member * temp = (Member*)malloc(sizeof(Member));
  LFirst(plist, &temp);

  if(strcmp(temp->name, name) != 0){
    for(i=0; i<num-1; i++){
      LNext(plist, &temp);

      if(strcmp(temp->name, name) == 0)
        break;
    }

    if(i>=num-1)
      return NULL;
  }

  for(i=0; i<day; i++)
    LNext(plist, &temp);
  
  return temp;
}

void ShowInfo(Member * temp){
  printf("직원 이름 : %s\n", temp->name);
  printf("직원 사번 : %d\n", temp->personalNum);
}
