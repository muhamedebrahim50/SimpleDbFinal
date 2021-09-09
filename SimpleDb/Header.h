#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

typedef int uint8 ; /*unsigned char could be used here instead and the application will work fine ,
but integer is recommended because of the format specifier %d in scanf are designed for decimal integar and may cause data corruption */

typedef struct db
{

	uint8 id;
	uint8 year;
	uint8 subjects[3];
	uint8 grades[3];
	struct db* pNext;
	struct db* pPrev;

}SimpleDb;
typedef struct mylist
{
	SimpleDb* pHead;
	SimpleDb* pTail;
	uint8 listsize;
}list;




void MAIN_MENU(void);
void List_init(void);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades);
void SDB_GetIdList(uint8* count, uint8* list);
bool SDB_IsIdExist(uint8 ID);




