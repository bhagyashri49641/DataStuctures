#include "Header.h"

int main()
{
	PNODE Head = NULL;
	PNODE Tail = NULL;

	BOOL Bret = TRUE;

	int ret = 0;

	int choice = 1;

	while(choice != 0)
	{
		printf("\n************************************************\n");

		printf("1 Insert First:\n");
		printf("2 Insert Last:\n");
		printf("3 Insert At Position:\n");

		printf("4 Delete First:\n");
		printf("5 Delete Last:\n");
		printf("6 Delete At Position:\n");

		printf("7 Display Contains of Doubly Circular Linked List(Forward):\n");

		printf("8 Total Count of Nodes in Doubly Circular Linked List:\n");

		printf("9 Search First Occurance:\n");

		printf("10 Display Contains of Doubly Circular Linked List(Backward):\n");

		printf("0 Exit:");

		printf("\n***************************************************\n");

		printf("Enter Your Choice:");
		scanf(" %d",&choice);

		printf("******************************************************\n");

		switch(choice)
		{
			case 1:
				Bret = InsertFirst(&Head , &Tail);
				if(Bret == TRUE)
				{		
					printf("Element Inserted Successfully..\n");
				}
				else
				{
					printf("Insertion of element is FAIL\n");
				}
			break;

			case 2:
				Bret = InsertLast(&Head , &Tail);
				if(Bret == TRUE)
				{		
					printf("Element Inserted Successfully..\n");
				}
				else
				{
					printf("Insertion of element is FAIL\n");
				}
			break;

			case 3:
				Bret = InsertAtPos(&Head , &Tail);
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
				Bret = DeleteFirst(&Head , &Tail);
				if(Bret == TRUE)
				{		
					printf("Element Deleted Successfully..\n");
				}
				else
				{
					printf("Deletion of element is FAIL\n");
				}
			break;

			case 5:
				Bret = DeleteLast(&Head , &Tail);
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
				Bret = DeleteAtPos(&Head , &Tail);
				if(Bret == TRUE)
				{		
					printf("Element Deleted Successfully..\n");
				}
				else
				{
					printf("Deletion of element is FAIL \n");
				}
			break;

			case 7:
				DisplayForward(Head , Tail);
			break;

			case 8:
				ret = Count(Head , Tail);
				if(ret==-1)
				{
					printf("LL is empty\n");
				}
				else
				{
					printf("Total Element Count is:%d\n",ret);
				}
			break;

			case 9:
				ret = SearchFirstOccurance(Head , Tail);
				if(ret == -1)
				{
					printf("LL is empty\n");
				}
				else if(ret==-2)
				{
					printf("Number Not Found..\n");
				}
				else
				{
					printf("First Occurance of Node at:%d\n",ret);
				}
			break;

			case 10:
				DisplayReverse(Head , Tail);
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
