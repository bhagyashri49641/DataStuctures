#include "Header.h"

int main()
{
	int iRet =0;
	int Choice = 1;

	InitQueue();// initialisation of queue

	while(Choice != 0)
	{
		printf("*******************************************\n");

		printf("Operations on Queue\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Count\n");
		printf("0. Exit\n");
		printf("*****************************************\n");
		printf("Enter Your Choice:-");
		scanf("%d",&Choice);

		switch (Choice)
		{
			case 1:Enqueue();
			break;

			case 2:iRet=Dequeue();
				printf("Removed element is:%d\n",iRet);
			break;

			case 3:Display();
			break;

			case 4:iRet=Count();
				printf("Total elememts in queue are :%d\n",iRet);
			break;

			case 0:
			printf("Thank you for using my Queue\n");
			break;

			default:printf("Wrong Choice : Please Enter Valid Choice..\n");
			break;
		}
	}

	return 0;
}

