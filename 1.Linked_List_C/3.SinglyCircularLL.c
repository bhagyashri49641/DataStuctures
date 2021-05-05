//Singly Circular linked List without menu driven switch cases

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int Data;
	struct Node *Next;

}NODE,*PNODE,**PPNODE;

/*
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;
*/

/////////////////////////////////////////////////////////////////////////////
void Display(PNODE First,PNODE Last)
{
	do
	{
		printf("|%d|<=>",First->Data);
		First=(First)->Next;
	}while(First != Last->Next);
	printf("\n");

}
/////////////////////////////////////////////////////////////////////////////
int Count(PNODE First,PNODE Last)
{
	int Cnt=0;
	do
	{
		Cnt++;
		First=(First)->Next;
	}while(First != Last->Next);
	return Cnt;
	
}
////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First,PPNODE Last)
{
	int No=0;
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	printf("Enter value:");
	scanf("%d",&No);
	
	newn->Data=No;
	newn->Next=NULL;

	if((*First==NULL)&&(*Last==NULL))	//LL is empty
	{
		*First=newn;
		*Last=newn;
	}
	else	//LL contains atleast one node
	{
		newn->Next=*First; // navin node chya next mdhe pahilyacha address takla
		*First=newn; //teacher chya dokyat navin node cha address takla
	}
	(*Last)->Next=*First;	//shevtchya chya next mdhe pahilya node address takla
}
/////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE First,PPNODE Last)
{
	int No=0;
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	printf("Enter value:");
	scanf("%d",&No);
	
	newn->Data=No;
	newn->Next=NULL;

	if((*First == NULL) && (*Last == NULL))	//LL is empty
	{
		*First=newn;
		*Last=newn;
	}
	else	//LL contains atleast one node
	{
		(*Last)->Next=newn; // shevtchya chya next mdhe navin node cha addr takla
		*Last=newn;	// last pointer navin last node la point krun dila  or //*Last=(*Last)->Next
	}
	(*Last)->Next=*First;	//shevtchya chya next mdhe pahilya node address takla
}
////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First,PPNODE Last)
{
	int size=0;
	int Pos=0;
	int No=0;
	int i=0;

	PNODE temp= *First;

	PNODE newn =NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	printf("Enter postion to insert node:");
	scanf("%d",&Pos);

	size=Count(*First,*Last);

	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if((Pos<1) ||(Pos>size))
	{
		return;
	}
	else if(Pos==1)		//contains only one node
	{
		InsertFirst(First,Last);
	}
	else if(Pos==size+1)
	{
		InsertLast(First,Last);
	}
	else
	{
		printf("Enter value to insert:");
		scanf("%d",&No);

		newn->Data=No;
		newn->Next=NULL;

		for(i=1;i<Pos-1;i++)
		{
			temp=temp->Next;
		}
		newn->Next=temp->Next;
		temp->Next=newn;
	}

}

///////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First,PPNODE Last)
{
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First==*Last) //contains only one node
	{
		free(*First);
		*First=NULL;
		*Last=NULL;
	}
	else	//more than one node
	{
		*First=(*First)->Next;
		free((*Last)->Next);
	}
	(*Last)->Next=*First;

}
//////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First,PPNODE Last)
{
	PNODE temp=*First;
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First==*Last) //contains only one node
	{
		free(*First);
		*First=NULL;
		*Last=NULL;
	}
	else	//more than one node
	{
		while(temp->Next != *Last)
		{
			temp=temp->Next;
		}
		free(temp->Next);
		*Last=temp;
	}
	(*Last)->Next=*First;

}

////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First,PPNODE Last)
{
	int Pos=0;
	int size = 0;
	int i=0;

	PNODE temp=*First;
	PNODE target=NULL;

	size = Count(*First,*Last);

	printf("Enter position to delete node:");
	scanf("%d",&Pos);

	if((Pos<1) || (Pos>size))
	{
		return;
	}
	else if(Pos==1)
	{
		DeleteFirst(First,Last);
	}
	else if(Pos==size)
	{
		DeleteLast(First,Last);
	}
	else
	{
		printf("I am in else part\n");
		for(i=1;i<Pos-1;i++)
		{
			temp=temp->Next;
		}
		target=temp->Next;
		temp->Next=target->Next;
		free(target);
	}
}

/////////////////////////////////////////////////////////////////////////////
int main()
{
	PNODE Head=NULL;
	PNODE Tail=NULL;
	int No=0;
	int iRet;

	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);

	InsertLast(&Head,&Tail);
	InsertLast(&Head,&Tail);
	InsertLast(&Head,&Tail);
	Display(Head,Tail);

	DeleteFirst(&Head,&Tail);
	DeleteLast(&Head,&Tail);
	Display(Head,Tail);

	DeleteAtPos(&Head,&Tail);
	Display(Head,Tail);

	InsertAtPos(&Head,&Tail);
	

	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total number of noes in LL are:%d\n",iRet);


	return 0;
}
