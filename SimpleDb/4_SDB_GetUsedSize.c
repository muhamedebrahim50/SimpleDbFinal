#include"Header.h"
extern list studentList;
uint8 SDB_GetUsedSize(void)
{
	return studentList.listsize;
}
bool SDB_IsFull(void)
{
	uint8 checker;
	if (SDB_GetUsedSize() >= 10)
	{
		checker = true;
	}
	else
	{
		checker = false;
	}
	return checker;
}
void List_init(void)
{
	studentList.pHead = NULL;
	studentList.pTail = NULL;
	studentList.listsize = 0;
}
