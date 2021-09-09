
#include"Header.h"

extern list studentList;
extern SimpleDb* temp;

void SDB_GetIdList(uint8* count, uint8* list)
{
    uint8 i=0;
    temp= studentList.pHead;
    *count=studentList.listsize;
   while(temp != NULL)
    {
        list[i]=temp->id;
        i++;
        temp = temp->pNext;
    }
}
