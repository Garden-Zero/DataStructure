#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"


void StackInit(Stack * pstack){
  pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack){
  if(pstack->topIndex == -1)
    return TRUE;
  else
    return FALSE;
}

void SPush(Stack * pstack, Data data){
  pstack->topIndex += 1;
  pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack){
  int index;

  if(SIsEmpty(pstack)){
    printf("저장된 정보 없음\n");
    exit(-1);
  }

  index = pstack->topIndex;
  pstack->topIndex -= 1;

  return pstack->stackArr[index];
}

Data SPeek(Stack * pstack){
  
}