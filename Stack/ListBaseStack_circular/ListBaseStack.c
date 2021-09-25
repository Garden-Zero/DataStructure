#include <stdio.h>
#include <stdlib.h>


#include "LinkedList.h"
#include "ListBaseStack.h"


void StackInit(Stack * pstack){
  pstack->plist->numOfData = 0;
}

int SIsEmpty(Stack * pstack){
  if(pstack->plist->numOfData == 0)
    return TRUE;
  else
    return FALSE;
}

void SPush(Stack * pstack, Data data){
  LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack){
  Data rdata;
  LFirst(pstack->plist, &rdata);
  LRemove(pstack->plist);
  return rdata;
}

Data SPeek(Stack * pstack){
  Data data;
  LFirst(pstack->plist, &data);
  return data;
}