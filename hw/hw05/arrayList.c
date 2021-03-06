#include "arrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define INITSIZE 16

bool arrayListEnlarge(arrayList list);

arrayList arrayListCreate() {
	arrayList list = (arrayList)malloc(sizeof(struct arrayListStruct));
	if (list==NULL) return list;
	list->data=(int *)malloc(sizeof(int)*INITSIZE);
	list->numUsed=0;
	list->numAlloc=INITSIZE;
	return list;
}

bool arrayListEnlarge(arrayList list) {
	list->data=(int *)realloc(list->data,sizeof(int) * (2*list->numAlloc));
	if (!list->data) return false;
	list->numAlloc *=2;
	return true;
}

bool arrayListAdd(arrayList list, int item)
{
  if(list->numUsed == list->numAlloc)
      if(!arrayListEnlarge(list))return false;
  list->data[list->numUsed++] = item;
  return true;
}
void arrayListClear(arrayList list)
{
  list->numUsed=0;
}
bool arrayListContains(arrayList list, int item)
{
  int i;
  for(i = 0;i<list->numUsed;i++)
    {
      if(list->data[i]==item)return true;
    }
  return false;
}
int arrayListGet(arrayList list,int index)
{
  assert(index >=0);
  assert(index<list->numUsed);
  return list->data[index];
}
int arrayListIndexOf(arrayList list, int item)
{
  int i;
  for(i=0;i<list->numUsed;i++)
    {
      if(list->data[i]==item)return i;
    }
  return -1;
}
bool arrayListIsEmpty(arrayList list)
{
  return !list->numUsed;
}
int arrayListSet(arrayList list, int index, int item)
{
  assert(index < list->numUsed && index >= 0);
  int prev = list->data[index];
  list->data[index] = item;
  return prev;  
}
int arrayListSize(arrayList list)
{
  return list->numUsed;
}
char * arrayListToString(arrayList list,char *buffer)
{
  buffer[0]=0;
  strcat(buffer, "[");
  int i;
  for(i=0;i<list->numUsed;i++)
    {
      char* tmp = calloc(10,1);
      sprintf(tmp, "%d", list->data[i]);
      strcat(buffer,tmp);
      if(i!=list->numUsed-1)strcat(buffer, ", ");
    }
  strcat(buffer,"]");
  return buffer;
}

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}
