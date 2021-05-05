// Singly Linear linked List without menu driven switch cases

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE,int);
void InsertLast(PPNODE ,int);
void InsertAtPos(PPNODE,int,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE,int);
void Display(PNODE);
int Count(PNODE);

int main()
{
    printf("\nWelcome to Singly Linear Linked List\n");

    PNODE Head = NULL;
    int ret =0;
    InsertFirst(&Head,10);
    InsertFirst(&Head,20);
    InsertFirst(&Head,30);
    InsertFirst(&Head,40);
    InsertFirst(&Head,50);
    InsertFirst(&Head,60);
    Display(Head);
     
    InsertLast(&Head,100);
    InsertLast(&Head,200);
    InsertLast(&Head,300);
    DeleteFirst(&Head);
    DeleteLast(&Head);
    Display(Head);

    InsertAtPos(&Head,455,4);
    Display(Head);
    DeleteAtPos(&Head,3);
    
    Display(Head);
   
    ret = Count(Head);
    printf("\n Total number of nodes present in LL are:%d",ret);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First,int No)
{
    printf("Inside InsertFirst\n");
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));  //allocate memory

    newn->Data=No;  //initialise data
    newn->Next=NULL;

    if(*First==NULL)        //LL is empty
    {
        *First = newn;
    }
    else            // LL is having atleast one node
    {
        newn->Next = *First;    //navin node chya next mde Head mdhli value taka
        *First = newn;           //Head mdhe navin node cha address takla
    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
    
    while(First != NULL)
    {
        printf("|%d|\t",First->Data);
        First = First ->Next;
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE First)
{
    printf("Inside Count\n");
    int count =0;
    while(First !=NULL)
    {
        count++;
        First = First->Next;
    }
    return count;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE First,int No)
{
    printf("Inside InsertLast\n");
    PNODE newn =NULL;
    PNODE temp=NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data=No;
    newn->Next=NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        temp = *First;

        while(temp->Next != NULL)
        {
          temp =temp->Next;
        }
        temp->Next =newn;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First)
{
    printf("Inside DeleteFirst\n");
    PNODE temp= *First;
    
    if(*First != NULL)
    {
        temp = *First;
        (*First) = (*First) -> Next;
        free(temp);
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First)
{
    printf("Inside DeleteLast\n");
    PNODE temp =NULL;

    if(*First==NULL)
    {
        return;
    }
    else if(((*First) -> Next )== NULL)
    {
        free(*First);
        *First=NULL;
    }
    else
    {
        temp=*First;
        while(temp->Next->Next !=NULL)
        {
            temp=temp->Next;
        }
        free(temp->Next);
        temp->Next=NULL;
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First, int No, int iPos)
{
    printf("Inside InsertAtPos\n");
    PNODE newn =NULL;
    PNODE temp =*First;
    int iSize=Count(*First);
    int iCnt=0;
    
    if(iPos<1 || iPos>iSize+1)  //Invalid Position
    {
        return;
    }
    else if(iPos==1)    //First position
    {
        InsertFirst(First,No);
    }
    else if(iPos==iSize+1)   //Last position
    {
        InsertLast(First,No);
    }
    else                        //Intermediate position
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->Data= No;
        newn->Next =NULL;

        for(iCnt=1;iCnt<iPos-1;iCnt++)  // position 5 la add kraych asel tr ek ghar adich thambaychy mnun iPos-1
        {
            temp = temp->Next;
        }

        newn->Next=temp->Next;
        temp->Next= newn;

    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First,int iPos)
{
    printf("Inside DeleteAtPos\n");
    PNODE temp=*First;
    PNODE target=*First;
    int i=0;
    int iSize=Count(*First);
    
    if((iPos<1)||(iPos>iSize))
    {
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst(First);
    }
    else if(iPos==iSize)
    {
        DeleteLast(First);
    }
    else
    {
        for(i=1;i<iPos-1;i++)
        {
            temp=temp->Next;
        }
        target=temp->Next;
        temp->Next = target->Next;
        free(target);
    }
}