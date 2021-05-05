#include "Header.h"
/////////////////////////////////////////////////////////////////////
BOOL InsertFirst(PPNODE First)
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

	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		newn->Next = *First;
		(*First)->Prev = newn;
		*First = newn;
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
BOOL InsertLast(PPNODE First)
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

	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		while(temp->Next != NULL)
		{
			temp = temp->Next;
		}
		
		temp->Next = newn;
		newn->Prev = temp;
	}
	
	return TRUE;
}
///////////////////////////////////////////////////////////////////////////
BOOL InsertAtPos(PPNODE First)
{
	PNODE newn = NULL;
	PNODE temp = NULL;

	int No , Pos , size = 0;
	int i = 1;

	size = Count(*First);

	printf("Enter Position:");
	scanf("%d",&Pos);

	if((Pos < 1) || (Pos > size + 1))
	{
		printf("Wrong position\n");
		return FALSE;
	}

	if(Pos == 1)
	{
		return (InsertFirst(First));
	}
	else if(Pos == size + 1)
	{
		return (InsertLast(First));
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

		for(i = 1; i < (Pos - 1); i++)
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
BOOL DeleteFirst(PPNODE First)
{
	
	if(*First == NULL)
	{
		return FALSE;
	}
	else if((*First)->Next==NULL) //only one node is there
	{
		free(*First);
		*First=NULL;
	}
	else
	{
		*First = (*First)->Next;
		free((*First)->Prev);
		(*First)->Prev = NULL;	
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
BOOL DeleteLast(PPNODE First)
{
	PNODE temp = NULL;

	temp = *First;

	if(*First == NULL)
	{
		return FALSE;
	}
	else if((*First)->Next==NULL)
	{
		free(*First);
		*First=NULL;
	}
	else if(*First !=0)
	{
		while(temp->Next->Next !=NULL)
		{
			temp = temp->Next;
		}
		free(temp->Next);
		temp->Next = NULL;
	}

	return TRUE;
}
///////////////////////////////////////////////////////////////////////////
BOOL DeleteAtPos(PPNODE First)
{
	PNODE temp = NULL;

	int size , Pos = 0;

	size = Count(*First);

	printf("Enter Position:");
	scanf("%d",&Pos);

	if((Pos < 1) || (Pos > size + 1))
	{
		printf("Wrong Position:\n");
		return FALSE;
	}

	if(Pos == 1)
	{
		return (DeleteFirst(First));
	}
	else if(Pos == size)
	{
		return (DeleteLast(First));
	}
	else
	{
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
/////////////////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
	while( First != NULL )
	{
		printf("|%d|=>",First->Data);
		First = First->Next;
	}
	printf("NULL\n");
}
/////////////////////////////////////////////////////////////////////////////
int Count(PNODE First)
{
	int size = 0;

	while(NULL != First)
	{
		size++;
		First = First->Next;
	}

	return size;
}
/////////////////////////////////////////////////////////////////////////////
int SearchFirstOccurance(PNODE First)
{
	int size=0 ;
	int No = 0;

	printf("Enter Number to Search:");
	scanf("%d",&No);

	while(First != NULL)
	{
		size++;

		if(First->Data == No)
		{
			return size;			
		}
	
		First = First->Next;
	}

	return -1;
}

//////////////////////////////////////////////////////////////////////////////