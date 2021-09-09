#include"Header.h"

extern list studentList;
extern SimpleDb* temp;

bool SDB_IsIdExist(uint8 ID)
{

temp= studentList.pHead;

    while(temp != NULL){
        if(ID == (temp->id))
        {
            return true;
        }
        temp = temp->pNext;
    }

    return false;

}
