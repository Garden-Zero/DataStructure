#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone){
  NameCard * newNameCard = NULL;
  newNameCard = (NameCard*)malloc(sizeof(NameCard));
  strcpy(newNameCard->name,name);
  strcpy(newNameCard->phone, phone);

  return newNameCard;
}

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard){
  fputs(pcard->name, stdout);
  fputs(pcard->phone, stdout);
}
   
// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name){
  if(!strcmp(pcard->name, name))
    return 0;
  else
    return 1;
}
   
// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone){
  strcpy(pcard->phone, phone);
}