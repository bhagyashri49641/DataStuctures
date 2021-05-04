//Doubly circular Linked List without switch cases in main

#include<stdio.h>
//#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int Data;
	struct Node *Next;
	struct Node *Prev;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

///////////////////////////////////////////////////////////////////////////
void DisplayF(PNODE First,PNODE Last)
{
	do
	{
		printf("|%d|<=>",First->Data);
		First=First->Next;
	}while(First != Last->Next);
	printf("\n");

}
//////////////////////////////////////////////////////////////////////////
void DisplayB(PNODE First,PNODE Last)
{
	do
	{
		printf("|%d|<=>",Last->Data);
		Last=Last->Prev;
	}while(Last != First->Prev);
	printf("\n");

}

////////////////////////////////////////////////////////////////////////////
int Count(PNODE First,PNODE Last)
{
	int Cnt=0;

	do
	{
		Cnt++;
		First=First->Next;

	}while(First != Last->Next);
	return Cnt;

}

////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First,PPNODE Last)
{
	PNODE newn=NULL;
	
	newn =(PNODE)malloc(sizeof(NODE));
	int Value=0;

	printf("Enter value to insert at first:");
	scanf("%d",&Value);

	newn->Data=Value;
	newn->Next=NULL;
	newn->Prev=NULL;

	if((*First==NULL)&&(*Last==NULL))
	{
		*First=newn;
		*Last=newn;
	}
	else
	{
		newn-> Next = (*First);
		(*First)-> Prev = newn;
		*First=newn;    //(*First) = (*First)->Prev; // 
	}
	//pudchi don vakya same astil sglya fuction mdhe
	(*First)->Prev=*Last;  //pahilyachya Prev mdhe shevtchya cha addr
	(*Last)->Next=*First;  //shevtchya chya Next mdhe pahilyacha addr
}
//////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE First,PPNODE Last)
{
	PNODE newn=NULL;
	newn =(PNODE)malloc(sizeof(NODE));

	int Value=0;

	printf("Enter value to insert at Last:");
	scanf("%d",&Value);
	

	newn->Data=Value;
	newn->Next=NULL;
	newn->Prev=NULL;

	if((*First==NULL)&&(*Last==NULL))
	{
		*First=newn;
		*Last=newn;
	}
	else
	{
		newn->Prev=*Last;
		(*Last)->Next=newn;
		*Last=newn;
	}
	//pudchi don vakya same astil sglya fuction mdhe
	(*First)->Prev=*Last;  //pahilyachya Prev mdhe shevtchya cha addr
	(*Last)->Next=*First;  //shevtchya chya Next mdhe pahilyacha addr
}
/////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First ,PPNODE Last)
{
	int Pos=0;
	int Value=0;
	int i=0;

	PNODE temp=*First;
	PNODE newn=NULL;

	printf("Enter Position :");
	scanf("%d",&Pos);

	int Cnt=Count(*First,*Last);

	if( (Pos<1) || (Pos > Cnt))
	{
		printf("invalid position");
		return;
	}

	else if(Pos==1)
	{
		InsertFirst(First,Last);
	}
	else if(Pos==Cnt+1)
	{
		InsertLast(First,Last);
	}
	else
	{
		printf("Enter Value :");
		scanf("%d",&Value);

		newn=(PNODE)malloc(sizeof(NODE));

		newn->Next=NULL;
		newn->Prev=NULL;
		newn->Data=Value;

		for(i=1;i<Pos-1;i++)
		{
			temp=temp->Next;
		}

		newn->Next=temp->Next;
		newn->Prev=temp;
		temp->Next->Prev=newn;
		temp->Next=newn;
	}

}
////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First,PPNODE Last)
{
	if((*First==NULL)&&(*Last==NULL))	//LL is empty
	{
		return;
	}
	else if(*First == *Last)		//LL ontain only one node
	{
		free(*First);
		(*First)->Next=NULL;
		(*Last)->Next=NULL;
	}
	else						//LL contains more than one node
	{
		(*First)=(*First)->Next;
		free((*Last)->Next);
		// nehmichi don vakya
		(*First)->Prev = (*Last);
		(*Last)->Next = (*First);
	}
}
/////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First,PPNODE Last)
{
	if((*First==NULL)&&(*Last==NULL))	//LL is empty
	{
		return;
	}
	else if(*First == *Last)		//LL ontain only one node
	{
		free(*First);
		(*First)->Next=NULL;
		(*Last)->Next=NULL;
	}
	else						//LL contains more than one node
	{
		(*Last) =(*Last)->Prev;
		free((*First)->Prev);
		// nehmichi don vakya
		(*First)->Prev = (*Last);
		(*Last)->Next = (*First);
	}
}

/////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First,PPNODE Last)
{
	PNODE temp=*First;
	int i=0;
	int Pos=0;

	int Cnt=Count(*First,*Last);

	printf("Enter position to delete node:");
	scanf("%d",&Pos);

	if((Pos<1)||(Pos>Cnt))
	{
		return ;
	}
	else if(Pos==1)
	{
		DeleteFirst(First,Last);
	}
	else if(Pos==Cnt)
	{
		DeleteLast(First,Last);
	}
	else
	{
		temp=*First;
		for(i=1;i<Pos-1;i++)
		{
			temp=temp->Next;
		}
		temp->Next=temp->Next->Next;
		free(temp->Next->Prev);
		temp->Next->Prev=temp;

	}
	
}
///////////////////////////////////////////////////////////////////////////
int main()
{
	PNODE Head=NULL;
	PNODE Tail=NULL;

	int iRet=0;

	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);
	DisplayF(Head,Tail);
	printf("\n");


	InsertLast(&Head,&Tail);
	InsertLast(&Head,&Tail);
	InsertLast(&Head,&Tail);
	DisplayF(Head,Tail);

	DeleteFirst(&Head,&Tail);
	DeleteFirst(&Head,&Tail);
	DeleteLast(&Head,&Tail);
	DeleteLast(&Head,&Tail);
	DisplayF(Head,Tail);

	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);
	InsertFirst(&Head,&Tail);
	DisplayF(Head,Tail);

	InsertAtPos(&Head,&Tail);
	InsertAtPos(&Head,&Tail);
	InsertAtPos(&Head,&Tail);
	DisplayF(Head,Tail);


	DeleteAtPos(&Head,&Tail);
	DeleteAtPos(&Head,&Tail);

	DisplayB(Head,Tail);

	iRet = Count(Head,Tail);
	printf("Total number of nodes are:%d",iRet);
	printf("\n");

	return 0;

}
//////////////////////////////////////////////////////////////////////////////