// Dynamic implementation of stack using linked list

// push             InsertFirst
// pop               DeleteFirst
// Display          Display

// type of linked list used : Singly linear

#include<stdio.h>
#include<stdlib.h>

/*
 typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;
*/

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef  struct node ** PPNODE;

void Push(PPNODE First, int value)   // InsertFirst
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next = NULL;
    
    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}
int Pop(PPNODE First)        // Deletefirst
{
    int no = 0;
    PNODE temp = *First;
    
    if(*First == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        no = (*First)->data;      
        *First = (*First)->next;
        free(temp);
        return no;
    }
}

int Peep(PNODE First)    // It just return the value without deleting the node
{
    int no = 0;
    
    if(First == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        no = First->data;
        return no;
    }
}

void Display(PNODE First)    
{
    if(First==NULL)
    {
    	printf("Stack is empty\n");
    }
    while(First != NULL)
    {
        printf("<-|%d|",First->data);
        First = First->next;
    }
    printf("\n");
}

int Count(PNODE First)       
{
    int iCnt = 0;
    
    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    int choice = 1, no = 0;
    
    printf("Dynamic implementation of stack\n");
    
    while(choice != 0)
    {
        printf("************************************************************\n");
        printf("1: Push the element\n");
        printf("2: Pop the elemet\n");
        printf("3: Display the elemets of stack\n");
        printf("4: Count the number of elements of stack\n");
        printf("5: Peep the element\n");
        printf("0: Exit the application\n");
        printf("************************************************************\n");
        
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter the element that you want to insert\n");
                scanf("%d",&no);
                Push(&Head, no);
                break;
                
            case 2 :
                no = Pop(&Head);
                printf("Poped element is : %d\n",no);
                break;
              
            case 3 :
                Display(Head);
                break;
                
            case 4:
                printf("Number of elements are : %d\n",Count(Head));
                break;
                
            case 5:
                printf("Peeped element is : %d\n",Peep(Head));
                break;
                
            case 0:
                printf("Thank you for using the application\n");
                break;
                
            default:
                printf("Wrong choice\n");
        } // end of swicth
    }// end of while
    
    return 0;
}// end of main








