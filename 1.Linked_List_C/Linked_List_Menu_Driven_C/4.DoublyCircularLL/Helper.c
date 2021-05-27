#include "Header.h"
/////////////////////////////////////////////////////////////////////////////
BOOL InsertFirst(PPNODE First , PPNODE Last)
{

	PNODE newn = NULL;

	int No = 0;

	newn = (PNODE)malloc(sizeof(NODE));
	if(newn == NULL)
	{
		return FALSE;
	}

	printf("Enter Number:");
	scanf("%d",&No);

	newn->Data = No;
	newn->Next = NULL;
	newn->Prev = NULL;

	printf("Inserting element at First..\n");
	if((*First == NULL) && (*Last == NULL))
	{
		*First = newn;
		*Last = newn;
		(*Last)->Next = *First;
		(*First)->Prev = *Last;
	}
	else
	{
		newn->Next = *First;
		(*First)->Prev = newn;
		*First = newn;
		(*Last)->Next = *First;
		(*First)->Prev = *Last;
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
BOOL InsertLast(PPNODE First , PPNODE Last)
{
	PNODE newn = NULL;
	PNODE temp = NULL;

	int No = 0;

	temp = *First;

	newn = (PNODE)malloc(sizeof(NODE));
	if(newn == NULL)
	{
		return FALSE;
	}

	printf("Enter Number:");
	scanf("%d",&No);

	newn->Data = No;
	newn->Next = NULL;
	newn->Prev = NULL;

	printf("Inserting element at LAST..\n");
	if((*First == NULL) && (*Last == NULL))
	{
		*First = newn;
		*Last = newn;
		(*Last)->Next = *First;
		(*First)->Prev = *Last;
	}
	else
	{
		(*Last)->Next = newn;
		newn->Prev = *Last;
		*Last = newn;	//*Last=(*Last)->Next;
		(*Last)->Next = *First;
		(*First)->Prev = *Last;	
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
BOOL InsertAtPos(PPNODE First , PPNODE Last)
{
	PNODE newn = NULL;
	PNODE temp = NULL;

	int size , Pos , No = 0;

	if((*First == NULL) && (*Last == NULL))
	{
		printf("LL is empty\n");
		return FALSE;
	}

	size = Count(*First , *Last);

	printf("Enter Position:");
	scanf("%d",&Pos);

	if((Pos < 1) || (Pos > size + 1))
	{
		printf("Wrong position\n");
		return FALSE;
	}

	if(Pos == 1)
	{
		return (InsertFirst(First , Last));
	}
	else if(Pos == size + 1)
	{
		return (InsertLast(First , Last));
	}
	else
	{
		
		temp = *First;

		newn = (PNODE)malloc(sizeof(NODE));
		if(newn == NULL)
		{
			return FALSE;
		}

		printf("Enter Number:");
		scanf("%d",&No);

		newn->Data = No;
		newn->Next = NULL;
		newn->Prev = NULL;

		printf("Inserting element at POSITION..\n");
		for(int i = 1; i < (Pos - 1); i++)
		{
			temp = temp->Next;
		}

		newn->Next = temp->Next;
		temp->Next->Prev = newn;
		temp->Next = newn;
		newn->Prev = temp;
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
BOOL DeleteFirst(PPNODE First , PPNODE Last)
{
	PNODE temp = NULL;

	temp = *First;

	if((*First == NULL) &&(*Last ==NULL) )  //empty LL
	{
		printf("LL is empty\n");
		return FALSE;
	}

    printf("Deleting element at FIRST..\n");
	if(*First == *Last) //LL contains single node
	{
		free(*First);
		*First = NULL;
		*Last = NULL;
	}

	else
	{
		*First = temp->Next;
		(*Last)->Next = *First;
		(*First)->Prev = *Last;
		free(temp);
		/* without using temp
			
			*First =(*First)->Next;
			free((*Last)->Next);
			(*Last)->Next =*First;
			*First->Prev =*Last;
		*/
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
BOOL DeleteLast(PPNODE First , PPNODE Last)
{

	if((*First == NULL) && (*Last == NULL))
	{
		printf("LL is empty\n");
		return FALSE;
	}

	printf("Deleting element at LAST..\n");
	if(*First == *Last)
	{
		free(*First);
		(*Last)->Next = NULL;
		(*First)->Prev = NULL;
	}
	else
	{
		*Last = (*Last)->Prev;
		free((*First)->Prev); //free((*Last)->Next);
		(*Last)->Next = *First;
		(*First)->Prev = *Last;
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
BOOL DeleteAtPos(PPNODE First , PPNODE Last)
{
	PNODE temp = NULL;

	int size , Pos = 0;

	if((*First == NULL) && (*Last == NULL))
	{
		printf("LL is empty\n");
		return FALSE;
	}

	size =Count(*First , *Last);

	printf("Enter position:");
	scanf("%d",&Pos);

	if((Pos < 1) || (Pos > size))
	{
		printf("Wrong Position\n");
		return FALSE;
	}


	if(Pos == 1)
	{
		return (DeleteFirst(First , Last));
	}
	else if(Pos == size)
	{
		return (DeleteLast(First , Last));
	}
	else
	{
		printf("Deleting element at POSITION..\n");
		temp = *First;
		

		for(int i = 1; i < (Pos - 1); i++)
		{
			temp = temp->Next;
		}
		temp->Next = temp->Next->Next;
		free(temp->Next->Prev);
		temp->Next->Prev = temp;
		
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
void DisplayForward(PNODE First , PNODE Last)
{
	if((First==NULL)&&(Last==NULL))
	{
		printf("LL is empty\n");
		return ;
	}
	printf("Display elements of Linked List in Forward Direction..\n");
	do
	{
		printf("|%d|<=>",First->Data);
		First = First->Next;
	}while(First != Last->Next);
	printf("Connected to First node\n");
}
/////////////////////////////////////////////////////////////////////////////
int Count(PNODE First , PNODE Last)
{
	int size = 0;

	if((First == NULL) && (Last == NULL))
	{
		
		return -1;
	}

	do
	{
		size++;
		First = First->Next;
	}while(First != Last->Next);

	return size;
}
/////////////////////////////////////////////////////////////////////////////
int SearchFirstOccurance(PNODE First , PNODE Last)
{
	int size =0;
	int  No = 0;

	if((First == NULL) && (Last == NULL))
	{
		return -1;
	}
	
	printf("Enter Number to Search:");
	scanf("%d",&No);

	do
	{
		size++;

		if(First->Data == No)
		{
			return size;
		}

		First = First->Next;
	}while(First != Last->Next);

	return -2;
}
/////////////////////////////////////////////////////////////////////////////
void DisplayReverse(PNODE First , PNODE Last)
{
	PNODE temp = NULL;

	temp = Last;

	if((First == NULL) && (Last == NULL))
	{
		printf("LL is empty\n");
		return ;
	}
	else
	{
		printf("Elements of Linked List in Backward Direction..\n");
		printf("Connected to First Node");
		do
		{
			printf("<=>|%d|",temp->Data);
			temp = temp->Prev;
		}while(temp != (First)->Prev);
	}

	/*without using temp
		
		do
		{
			printf("|%d|<=>",Last->Data);
			Last=Last->Prev;
		}while(Last != First->Prev);

		printf("\n");
	*/
}

//////////////////////////////////////////////////////////////////////////////