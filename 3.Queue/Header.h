#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int Data;
	struct Node *Next;
};

struct Node *top; //Global pointer 
int iSize;//global variable

void InitQueue();

void Enqueue();
int Dequeue();
void Display();
int Count();
