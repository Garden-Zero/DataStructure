#include <stdio.h>
#include "ArrayList.h"

int main(void) {
  int sum=0;
  int data;
  List list;

  ListInit(&list);
  
  for(int i=1; i<=9; i++){
    LInsert(&list, i);
  }

  if(LFirst(&list, &data)){
    sum+=data;

    while(LNext(&list, &data)){
      sum+=data;
    }

    printf("%d\n",sum);
  }

  if(LFirst(&list, &data)){
    if(data%2==0 || data%3==0){
      LRemove(&list);
    }

    while(LNext(&list, &data)){
      if(data%2==0 || data%3==0){
      LRemove(&list);
      }
    }
  }

  if(LFirst(&list, &data)){
    printf("%d\n",data);

    while(LNext(&list, &data)){
      printf("%d\n",data);
    }
  }
}
