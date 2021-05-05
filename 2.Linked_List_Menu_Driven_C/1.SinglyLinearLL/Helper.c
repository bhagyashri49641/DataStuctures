#include "Header.h"

///////////////////////////////////////////////////////////////////////////
BOOL InsertFirst(PPNODE First)
{
	PNODE newn = NULL;
	int No = 0;

	newn = (PNODE)malloc(sizeof(NODE));

	if(newn == NULL)
	{
		printf("Error allocating memory to new node\n");
		return FALSE;
	}

	printf("Enter Number:");
	scanf("%d",&No);

	newn->Data = No;
	newn->Next = NULL;

	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		newn->Next = *First;
		*First = newn;
	}
	
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
	while(First != NULL)
	{
		printf("|%d|->",First->Data);
		First = First->Next;
	}
	printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////
BOOL InsertLast(PPNODE First)
{
	PNODE newn = NULL;
	PNODE temp = NULL;

	int No = 0;

	newn = (PNODE)malloc(sizeof(NODE));
	
	if(newn == NULL)
	{
		return FALSE;
	}
	
	printf("Enter Number:");
	scanf("%d",&No);

	newn->Data = No;
	newn-> Next = NULL;

	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		temp = *First;

		while(temp->Next != NULL)	
		{
			temp = temp->Next;	
		}

		temp->Next = newn;
	}
	return TRUE;
}
////////////////////////////////////////////////////////////////////////////
BOOL InsertAtPos(PPNODE First)
{
	PNODE newn = NULL;
	PNODE temp = NULL;
	int i  = 0;
	int pos , No = 0;
	int size = Count(*First);

	printf("Enter Position:");
	scanf("%d",&pos);
	
	if(  (pos < 1) ||  (pos > (size + 1))  )
	{
		printf("Invalid position\n");
		free(newn);	
		return FALSE;
	}

	if(pos == 1)
	{
		return (InsertFirst(First));
	}
	else if(pos == (size + 1))
	{
		return (InsertLast(First));
	}
	else
	{
		temp=*First;

		newn = (PNODE)malloc(sizeof(NODE));

		if(newn == NULL)
		{
			return FALSE;
		}
		
		printf("Enter Number:");
		scanf("%d",&No);

		newn->Data = No;
		newn->Next = NULL;

		for(i = 1; i < (pos - 1); i++)
		{
			temp = temp->Next;
		}
	
		newn->Next = temp->Next;
		temp->Next = newn;
	}
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
int Count(PNODE First)
{
	int cnt = 0;

	while(First != NULL)
	{
		cnt++;
		First = First->Next;
	}
	return cnt;
}

/////////////////////////////////////////////////////////////////////////////
BOOL DeleteFirst(PPNODE First)
{
	PNODE temp = *First;

	if(*First == NULL)
	{
		return FALSE;
	}
	else
	{
		*First = (*First)->Next;
		free(temp);
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
BOOL DeleteLast(PPNODE First)
{
	PNODE temp = NULL;

	if(*First == NULL)
	{
		return FALSE;
	}
	else if((*First)->Next == NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
	        temp = *First;
		while(temp->Next->Next != NULL)
		{
			temp = temp->Next;
		}

		free(temp->Next);
		temp->Next = NULL;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
BOOL DeleteAtPos(PPNODE First)
{
	int size = 0 , i = 0 , pos = 0;
	PNODE temp1 = NULL , target = NULL;

	size = Count(*First);

	printf("Enter Position:");
	scanf("%d",&pos);

	if((pos < 1) || (pos > size))
	{
		printf("Position is wrong\n");
		return FALSE;
	}

	if(pos == 1)
	{
		return (DeleteFirst(First));
	}
	else if(pos == size)
	{
		return (DeleteLast(First));
	}
	else
	{
		temp1 = *First;
	
		for(i = 1; i < (pos - 1); i++)
		{
			temp1 = temp1->Next;
		}

		target = temp1->Next;
		temp1->Next = target->Next;
		free(target);
	}
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
