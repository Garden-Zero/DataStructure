#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node * next;
}Node;


int main(void){

  Node * head=NULL;
  Node * tail=NULL;
  Node * cur=NULL;

  Node * newNode=NULL;

  int input;

  head=(Node *)malloc(sizeof(Node));
  tail = head;

  while(1){
    printf("입력: ");
    scanf("%d", &input);

    if(input < 1){
      break;
    }

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data=input;
    tail->next = newNode;
    tail = newNode;
  } 

  printf("출력!\n");
  if(head==NULL){
    printf("출력할 데이터가 없습니다.\n");  
    
  }
  else{
    cur = head;
    while(cur->next!=NULL){
      cur=cur->next;
      printf("%d\n", cur->data);
    }
  }


  printf("메모리 해제!\n");
  if(head==NULL){
    printf("해제할 메모리가 없습니다.");
  }
  else{
    Node * delNode = head;
    Node * delNodeNext = head->next;
    while(delNode->next!=NULL){
      delNode=delNodeNext;
      delNodeNext=delNode->next;
      printf("해제!\n");
      free(delNode);
    }
  }
  
  return 0;
}

