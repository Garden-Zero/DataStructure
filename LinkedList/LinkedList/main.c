#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node * next;
}Node;

int main(void) {
  Node * head=NULL;
  Node * tail=NULL;
  Node * cur=NULL;

  Node * newNode=NULL;
  int input;

  while(1){
    printf("자연수 입력: ");
    scanf("%d", &input);
    if(input<1){
      break;
    }

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = input;
    newNode->next=NULL;

    if(head==NULL){
      head = newNode;
    }
    else{
      tail->next=newNode;
    }

    tail = newNode;
    }

    printf("출력!\n");
    if(head==NULL){
      printf("저장된 데이터가 없습니다.\n");
    }
    else{
      cur = head;
      printf("%d\n", cur->data);

      while(cur->next!=NULL){
        cur = cur->next;
        printf("%d\n", cur->data);
      }
    }

    printf("메모리 해제\n");

    if(head==NULL){
      printf("해제할 데이터가 없습니다.\n");
    }
    else{
      Node * delNode = head;
      Node * delNodeNext = head->next;

      free(delNode);

      while(delNodeNext->next != NULL){
        delNode = delNodeNext;
        delNodeNext = delNode->next;
        free(delNode);
      }

      printf("해제 완료!\n");
      
    }

  return 0;

}
