#include"Header.h"

extern list studentList;
extern SimpleDb* temp;

bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{

    if(SDB_IsIdExist(id))
    {

        year=temp->year;
        subjects=temp->subjects;
        grades=temp->grades;
        return true;
    }
    else
    {
        return false;
    }
}
