#include<stdio.h>
#include<stdlib.h>

struct dNode
{
	int iData;
	struct dNode *Next;
};

typedef struct dNode NODE;

typedef struct dNode * PNODE;

typedef struct dNode ** PPNODE;

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
	PNODE NewNode = NULL;
	
	NewNode = (PNODE)malloc(sizeof(NODE));
	
	NewNode -> iData = iNo;
	NewNode -> Next = NULL;
	
	
	if((*Head == NULL)  &&  (*Tail == NULL))
	{
		*Head = NewNode;
		*Tail = NewNode;
	}
	else
	{
		 NewNode -> Next = *Head;
		*Head = NewNode;
	}
	(*Tail) -> Next = *Head;	
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
	PNODE NewNode = NULL;
	
	NewNode -> Next = NULL;
	NewNode -> iData = iNo; 
	
	if((*Head == NULL) &&  (*Tail == NULL))
	{
		*Head = NewNode;
		*Tail = NewNode;
	}
	else
	{
		(*Tail) -> Next = NewNode;
		*Tail = NewNode;
	}
	(*Tail) -> Next = *Head;
}
void Display(PNODE Head, PNODE Tail)
{
	PNODE Temp = Head;
	
	do
	{
		printf("|%d| <=>",Temp -> iData);
		Temp = Temp -> Next;
	}while(Temp != Head);
	
	printf("NULL\n");
}
int Count(PNODE Head, PNODE Tail)
{
	PNODE Temp = Head;
	int iNodeCntt = 0;
	
	if((Head == NULL) && (Tail == NULL))
	{
		printf("No nodes in Linked List yet\n");
	}
	else
	{
		do
		{
			iNodeCntt++;
			Temp = Temp -> Next;
		}while(Temp != Tail -> Next);
		
		return  iNodeCntt;
	}
	
}
int main()
{
	//iRet is used to preserve the return value from Count Funciton.
    int iRet = 0;

    PNODE First = NULL;
	PNODE Last = NULL;
	
	//Inserting Values using InsertFirst
    InsertFirst(&First,&Last,101);
    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);
    InsertFirst(&First,&Last,1);
	
	Display(First,Last);
	iRet = Count(First,Last);
    printf(" Number of Nodes are : %d\n",iRet);
	
	return 0;
}