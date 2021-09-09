
#include"Header.h"
#define ADD		'1'
#define DELETE	'2'
#define SEARCH	'3'
#define READ	'4'
#define LIST	'5'
#define END     '6'
list studentList;
SimpleDb* temp = NULL;
void MAIN_MENU(void)
{
	uint8 grades[3];
	uint8 subjects[3];
	uint8 i;
	uint8 count=0,list[10];
	volatile char choice=0;
    volatile uint8 year=0;
    volatile uint8 id=0;
	volatile uint8 counter=0;
	volatile uint8 check=0;
	List_init();
	printf("School Data Base\n");
	printf("=================\n\n\n");
	printf("Here,\n>> you can create a new student\n>>view and manage scores\n");
	printf(">> check the details of an existing student\n>> remove existing student\n\n");
	printf("=======================================\n\n\n");

	do {
		printf("\nPlease choose only the number of the function you need :\n");
		printf("========================================================\n");
		printf("1-Add new entry\n2-Delete Student\n3-Search for existing student\n4-Read student\n5-Students ID's list\n6-End program\n\n");
		printf("Enter your choice: ");
		fflush(stdin);
		choice = getche();
		switch (choice)
		{
		case ADD:
		    if(!SDB_IsFull())
            {
            printf("\nPlease enter the data of the new student:\n");
			printf("=========================================\n");
            do
            {
                printf("ID: ");
                fflush(stdin);
                scanf("%d", &id);
                fflush(stdin);

                if(SDB_IsIdExist(id))
                {
                    printf("%d is already exist\nPlease enter new ID\n",id);
                }
            }while(SDB_IsIdExist(id));

			printf("Year: ");
            fflush(stdin);
			scanf("%d",&year);
            fflush(stdin);
			for (counter = 0; counter < 3; counter++)
			{
				printf("subject ID: ");
				scanf("%d", &subjects[counter]);
			}
			counter=0;
			do
            {
                printf("Grade of subject %d:",subjects[counter]);
                fflush(stdin);
                scanf("%d", &grades[counter]);
                if((grades[counter]>=0)&&(grades[counter]<=100))
                {
                    counter++;
                }
                else
                {
                    printf("\nGrade must be within 0 and 100 !\nPlease enter valid grade\n");
                }
                }while(counter < 3);
                if(SDB_AddEntry(id, year, subjects, grades))
                {
                    printf("\nAdded successfully\n");

                }
                else
                {
                    printf("\nNot Added\n");
                }
            }
            else
            {
                printf("\nSorry the list is full\n");
            }

				break;
		case DELETE:
            printf("\nPlease enter the ID that you want to search for :");
		    scanf("%d",&id);
		    if(SDB_IsIdExist(id))
            {
                SDB_DeleteEntry(id);
                printf("\nDeleted successfully\n");

            }
            else
            {
                printf("\nStudent ID %d do not exist\n",id);
            }


			break;
		case SEARCH:
		    printf("\nPlease enter the ID that you want to search for :");
		    scanf("%d",&id);
		    if(SDB_IsIdExist(id)){
                printf("\nStudent ID %d exists\n",id);
		    }
		    else{
                printf("\nStudent ID %d do not exist\n",id);
		    }
			break;
		case READ:
        printf("\nplease enter the ID that you want to search for :");
            scanf("%d",&id);
		        if(SDB_ReadEntry(id,&year,subjects,grades))
            {
                printf("Data of the Student\n");
                printf("ID:%d\nYear=%d\nSubjects' IDs=%d, %d, %d\nSubjects' grades=%d, %d, %d",id,year,subjects[0],subjects[1],subjects[2],grades[0],grades[1],grades[2]);
            }
            else{
                printf("\nStudent ID %d do not exist\n",id);
            }

			break;
		case LIST:
		    SDB_GetIdList(&count,list);
		    printf("\ncount=%d\n",count);
		    for(i=0; i<count; i++)
            {
                printf("id no %d = %d\n",i+1,list[i]);
		    }
			break;
		case END:
			break;
		default:
			printf("\nwrong choice\n");
			break;

			}

	}while (choice != END);
}

