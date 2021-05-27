#include "Header.h"

void InitQueue()
{
	top = NULL;
	iSize=0;
}

void Enqueue()//Insert Last
{
	int No = 0;

	struct Node *newn;

	newn = (struct Node*)malloc(sizeof(struct Node));

	if(newn == NULL)
	{
		printf("Failed to allocate memory for new node\n");
		return;
	}

	printf("Enter Number:");
	scanf("%d",&No);

	newn->Data = No;
	newn->Next=NULL;

	if(top == NULL)
	{
		top = newn;
	}	
	else
	{
		struct Node* temp=top;
		while(temp->Next !=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=newn;
	}
	iSize++;
}

int Dequeue()//DeleteFirst
{
	int No = 0;

	struct Node *temp=top;

	if(top == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	} 
	else
	{
		No = top->Data;
		top = top->Next;
		free(temp);
		iSize--;
		return No;
	}
}

void Display()
{
	if(top==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	struct Node *temp=top;

	for (temp = top; temp != NULL; temp = temp->Next)
	{
		printf("<-|%d|",temp->Data);
	}
	printf("\n");		
}

int Count()
{
	return iSize;
}

