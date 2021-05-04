// Doubly linear Linked List without menu driven options
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node* Next ;
    struct Node* Prev;
};

typedef struct Node  NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE,int);
void InsertLast(PPNODE,int);
void Display(PNODE);
int Count(struct Node*);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE,int,int);
void DeleteAtPos(PPNODE,int);

int main()
{
   PNODE Head =NULL;
   int no=0;
   int iRet=0;

   printf("Enter number\n");
   scanf("%d",&no);
   InsertFirst(&Head,no);

   printf("Enter number\n");
   scanf("%d",&no);
   InsertFirst(&Head,no);

   printf("Enter number\n");
   scanf("%d",&no);
   InsertFirst(&Head,no);

   printf("Enter number\n");
   scanf("%d",&no);
   InsertLast(&Head,no);

   printf("Enter number\n");
   scanf("%d",&no);
   InsertLast(&Head,no);
   Display(Head);

   DeleteFirst(&Head);
   Display(Head);
   DeleteLast(&Head);
   Display(Head);

   InsertAtPos(&Head,101,3);
   InsertAtPos(&Head,111,4);
   InsertAtPos(&Head,121,5);
   InsertAtPos(&Head,151,6);

   Display(Head);

   DeleteAtPos(&Head,1);
   DeleteAtPos(&Head,2);
   DeleteAtPos(&Head,3);
   Display(Head);

   iRet=Count(Head);
   printf("Number of Nodes are:%d",iRet);

  
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First,int no)
{
    PNODE newn =NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->Next=NULL;
    newn->Data=no;
    newn->Prev=NULL;

    if(*First==NULL)
    {
        *First=newn;
    }
    else
    {
        newn->Next=*First;
        (*First)->Prev=newn;
        *First=newn;
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("|%d|<->",First->Data);
        First = First->Next;
    }
    printf("NULL\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(struct Node* First)
{
    int iCnt=0;
    while(First != NULL)
    {
        iCnt++;
        First=First->Next;
    }
    return iCnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE First,int No)
{
    PNODE newn =NULL;
    PNODE temp=*First;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->Next=NULL;
    newn->Prev=NULL;
    newn->Data=No;

    if(*First ==NULL)
    {
        *First=newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp=temp->Next;
        }
        
        temp->Next =newn;
        newn -> Prev = temp;

    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First)
{
    if(*First == NULL)   //ekpn node nahi
    {
        return;
    }
    else if((*First)->Next==NULL)     // LL mdhe ekch node ahe
    {
        free(*First);
        *First=NULL;
    }
    else if(*First!=NULL)       //more than one node
    {
        *First =(*First)->Next;
        free((*First)->Prev);
        (*First)->Prev=NULL;
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE First)
{
    PNODE temp=*First;
    if(*First == NULL)   //ekpn node nahi
    {
        return;
    }
    else if((*First)->Next == NULL)     // LL mdhe ekch node ahe
    {
        free(*First);
        *First=NULL;
    }
    else if(*First!=NULL)       //more than one node
    {
        while(temp->Next->Next !=NULL)
        {
            temp=temp->Next;
        }
        free(temp->Next);
        temp->Next=NULL;
        
    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First,int No,int iPos)
{
  PNODE temp=*First;
  PNODE newn=NULL;
  int i=0;

  newn=(PNODE)malloc(sizeof(NODE));
  newn->Next=NULL;
  newn->Prev=NULL;
  newn->Data=No;

  int size=Count(*First);

  if((iPos<1)||(iPos>size+1))  //wrong position
  {
    return;
  }
  else if(iPos==1)  //LL is empty
  {
    InsertFirst(First,No);
  }
  else if(iPos==size+1)
  {
    InsertLast(First,No);
  }
  else
  {
    for(i=1;i<iPos-1;i++)
    {
      temp=temp->Next;
    }
    newn->Next=temp->Next;
    temp->Next->Prev=newn;
    temp->Next=newn;
    newn->Prev=temp;
  }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First,int iPos)
{
  PNODE temp=*First;
  int i=0;
  int size=Count(*First);

  if((iPos<1)||(iPos>size))
  {
    return;
  }
  else if(iPos==1)
  {
    DeleteFirst(First);
  }
  else if(iPos==size)
  {
    DeleteLast(First);
  }
  else
  {
    for(i=1;i<(iPos);i++)
    {
      temp=temp->Next;
    } 
    temp->Next->Prev = temp->Prev;
    temp->Prev->Next = temp->Next;
    free(temp); 

  }
  

}