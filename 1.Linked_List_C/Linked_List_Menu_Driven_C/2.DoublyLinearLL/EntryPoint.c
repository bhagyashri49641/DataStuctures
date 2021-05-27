#include "Header.h"

int main()
{
	PNODE Head = NULL;

	BOOL Bret = TRUE;

	int ret , choice = 1;

	while(choice != 0)
	{
		printf("*******************************************************\n");

		printf("1 Insert First:\n");
		printf("2 Insert Last:\n");
		printf("3 Insert At Position:\n");

		printf("4 Delete First:\n");
		printf("5 Delete Last:\n");
		printf("6 Delete At Position:\n");

		printf("7 Display Contains of Doubly Linear Linked List:\n");

		printf("8 Total Count of Nodes in Doubly Linear Linked List:\n");

		printf("9 Search First Occurance:\n");

		printf("0 Exit:\n");

		printf("*******************************************************\n");

		printf("Enter Your Choice:");
		scanf("%d",&choice);
		printf("*********************************************************\n");

		switch(choice)
		{
			case 1:
				printf("Inserting element at FIRST..\n");
				Bret = InsertFirst(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Inserted Successfully.\n");
				}
				else
				{
					printf("Insertion of element is FAIL\n");
				}
			break;

			case 2:
				printf("Inserting element at LAST..\n");
				Bret = InsertLast(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Inserted Successfully.\n");
				}
				else
				{
					printf("Insertion of element is FAIL\n");
				}
			break;

			case 3:
				printf("Inserting element at POSITION..\n");
				Bret = InsertAtPos(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Inserted Successfully..\n");
				}
				else
				{
					printf("Insertion of element is FAIL \n");
				}
			break;

			case 4:
				printf("Deleting element at FIRST..\n");
				Bret = DeleteFirst(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Deleted Successfully.\n");
				}
				else
				{
					printf("Deletion of element is FAIL\n");
				}
			break;

			case 5:
				printf("Deleting element at LAST..\n");
				Bret = DeleteLast(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Deleted Successfully..\n");
				}
				else
				{
					printf("Deletion of element is FAIL\n");
				}
			break;

			case 6:
				printf("Deleting element at POSITION..\n");
				Bret = DeleteAtPos(&Head);
				if(Bret == TRUE)
				{		
					printf("Element Deleted Successfully.\n");
				}
				else
				{
					printf("Deletion of element is FAIL \n");
				}
			break;

			case 7:
				printf("Elements of Linked List are:\n");
				Display(Head);
			break;

			case 8:
				ret = Count(Head);
				printf("Total Element Count is:%d\n",ret);
			break;

			case 9:
				ret = SearchFirstOccurance(Head);
				if(ret == -1)
				{
					printf("Number Not Found..\n");
				}
				else
				{
					printf("First Occurance of Number is at node:%d\n",ret);
				}
			break;

			case 0:
				printf("Exit From Application..\n");
			break;
	
			default:
				printf("Wrong Choice : Please try again..\n");
			break;
		}
	}

	return 0;
}
