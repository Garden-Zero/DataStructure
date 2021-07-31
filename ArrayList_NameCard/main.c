#include <stdio.h>
#include "NameCard.h"

void RemoveBSN(char * name){
  int len = strlen(name);
  name[len-1]=0;
}

int main(void) {
  NameCard * list[3];
  char name[NAME_LEN];
  char phone[PHONE_LEN];
  int input;

  for(int i=0; i<3; i++){
    printf("입력: ");
    scanf("%s %s", name, phone);
    
    list[i]=MakeNameCard(name, phone);
  }

  while(1){
    puts("1. 탐색");
    puts("2. 전화번호 변경");
    puts("3. 정보 삭제");
    puts("4. 모든 정보 출력");
    scanf("%d", &input);
    getchar();

    if(input==1){
      printf("입력: ");
      fgets(name, NAME_LEN, stdin);
      RemoveBSN(name);

      for(int i=0; i<3; i++){
        if(!NameCompare(list[i], name)){
          printf("이름: %s\t", list[i]->name);
          printf("전화번호: %s\n", list[i]->phone);
        }
      }
      

    }
    else if(input==2){
      printf("입력: ");
      fgets(name, NAME_LEN, stdin);
      RemoveBSN(name);

      for(int i=0; i<3; i++){
        if(!NameCompare(list[i], name)){
          printf("입력: ");
          scanf("%s", phone);
          strcpy(list[i]->phone,phone);
        }
      }

    }
    else if(input==3){
      printf("입력: ");
      fgets(name, NAME_LEN, stdin);
      RemoveBSN(name);

      for(int i=0; i<3; i++){
        if(!NameCompare(list[i], name)){
          free(list[i]);
        }
      }
      


    }
    else if(input==4){
      for(int i=0; i<3; i++){
        printf("이름: %s\t", list[i]->name);
        printf("전화번호: %s\n", list[i]->phone);
      }
    }
  }


}
