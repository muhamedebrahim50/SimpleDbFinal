
#include"Header.h"

extern list studentList;
extern SimpleDb* temp;


void SDB_DeleteEntry(uint8 id)
{
         if(SDB_IsIdExist(id))
        {
            if(studentList.pHead==studentList.pTail)
            {
                List_init();
            }
            else if(temp==studentList.pTail)
            {
                studentList.pTail = studentList.pTail->pPrev;
                studentList.pTail->pNext = NULL;
            }
            else if(temp==studentList.pHead)
            {
                studentList.pHead = studentList.pHead->pNext;
                studentList.pHead->pPrev = NULL;
            }
            else
            {
                temp->pPrev->pNext=temp->pNext;
                temp->pNext->pPrev=temp->pPrev;
            }
            free(temp);
            studentList.listsize--;

        }
        else{}
}
