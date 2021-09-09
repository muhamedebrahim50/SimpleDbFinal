#include"Header.h"
extern list studentList;

bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
	uint8 counter;
	bool check;
	SimpleDb* newSt = (SimpleDb*)malloc(sizeof(SimpleDb));
	if (newSt == NULL)
	{
		printf("Heap is full\n");
		return false;
	}
	else{}
    if (SDB_IsFull())
	{
	    free(newSt);
		return false;
	}
	else{}
	newSt->id=id;
	newSt->year=year;

	for (counter = 0; counter < 3; counter++)
	{
		newSt->subjects[counter] = subjects[counter];
		if((grades[counter]>=0)&&(grades[counter]<=100))
        {
            newSt->grades[counter] = grades[counter];
        }
        else
        {
            free(newSt);
            return false;
        }

	}
	newSt->pNext = NULL;
	newSt->pPrev = NULL;
	if (studentList.pHead == NULL) //empty list
	{
		studentList.pHead = newSt;
		studentList.pTail = newSt;
	}
	else
	{
		studentList.pTail->pNext = newSt;
		newSt->pPrev = studentList.pTail;
		studentList.pTail = newSt;
	}
    studentList.listsize++;
	return true;
}
