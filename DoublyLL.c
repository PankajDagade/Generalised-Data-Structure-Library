//////////////////////////////////////////////////////////////////////////////////////////////////
//  Write a program on Doubly Linear LinkedList and all 8 fucntions
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Structure of a Node of Doubly Linear LinkedList
//////////////////////////////////////////////////////////////////////////////////////////////////

struct dNode
{
    int iData;
    struct dNode *Next;
    struct dNode *Prev;          // *
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Using typedef to increase readablity of the program
//////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct dNode NODE;
typedef struct dNode * PNODE;
typedef struct dNode ** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Description :    Used to Display the Doubly Linear LinkedList
// Input :          Structure Pointer
// Output :         NA
// Date :           29/05/2022
// Author :        Pankaj Vishnu Dagade
//////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    printf("Data from linked list is : \n");

    while(Head != NULL)
    {
        printf("| %d | <=> ",Head -> iData);
        Head = Head -> Next;
    }
    printf(" NULL\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Description :    Used to Count the node of Doubly Linear LinkedList
// Input :          Structure Pointer
// Output :         Integer
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> Next;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Description :    Used to Insert First node in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer,Integer
// Output :         NA
// Date :           18/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE NewNode = NULL;

    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode -> iData = iNo;
    NewNode -> Next = NULL;
    NewNode -> Prev = NULL;        // *

    if(*Head == NULL)       // If LL is empty
    {
           *Head = NewNode;
    }
    else        // LL contains atleast one node
    {
            NewNode -> Next  = *Head;
            (*Head) -> Prev = NewNode;       // *
            *Head = NewNode;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Description :    Used to Insert Last node in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer,Integer
// Output :         NA
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, int iNo)
{
    PNODE NewNode = NULL;
    PNODE Temp = NULL;

    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode -> iData = iNo;
    NewNode -> Next = NULL;
    NewNode -> Prev = NULL;        // *

    if(*Head == NULL)       // If LL is empty
    {
           *Head = NewNode;
    }
    else        // LL contains atleast one node
    {
        Temp =  *Head;

        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }

        Temp -> Next = NewNode;
        NewNode -> Prev = Temp;        // *    temp->next->prev = temp;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Description :    Used to Delete First node in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer
// Output :         NA
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)       // if LL is empty
    {
        return;
    }

    if((*Head) -> Next == NULL)        // Single node
    {
        free(*Head);
        *Head = NULL;
    }
    else        // More than one node
    {
        *Head = (*Head) -> Next;     // *
        free((*Head) -> Prev);            // *
        (*Head) -> Prev = NULL;     // *
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Description :    Used to Delete Last node in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer
// Output :         NA
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
    PNODE Temp = NULL;

    if(*Head == NULL)       // if LL is empty
    {
        return;
    }

    if((*Head) -> Next == NULL)        // Single node
    {
        free(*Head);
        *Head = NULL;
    }
    else        // More than one node
    {
         Temp = *Head;

        while(Temp -> Next -> Next != NULL)
        {
            Temp = Temp -> Next;
        }

        free(Temp -> Next);
        Temp -> Next = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Description: Used to Delete at specifed postion in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer,Structure Pointer Pointer,Integer,Integer
// Output :         NA
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE Head, int iNo, int iPos)
{
    PNODE Temp = NULL;
    PNODE NewNode = NULL;

    int size = 0, iCnt = 0;
    size = Count(*Head);

    if((iPos < 1) || (iPos > (size+1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos ==1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos == (size+1))
    {
        InsertLast(Head,iNo);
    }
    else
    {
        Temp = *Head;
        NewNode = (PNODE)malloc(sizeof(NODE));

        NewNode -> iData = iNo;
        NewNode -> Next = NULL;
        NewNode -> Prev = NULL;        // *

        for(iCnt =1; iCnt < (iPos-1) ;iCnt++)
        {
            Temp = Temp -> Next;
        }

        NewNode -> Next = Temp -> Next;
        Temp -> Next -> Prev = NewNode;        // *
        Temp -> Next = NewNode;
        NewNode -> Prev = Temp;              // *
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Description : Used to Delete at specifed postion in the Doubly Linear LinkedList
// Input :          Structure Pointer Pointer,Structure Pointer Pointer,Integer
// Output :         NA
// Date :           29/05/2022
// Author :         Pankaj Vishnu Dagade
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE Head, int iPos)
{
    PNODE Temp = NULL;

    int size = 0, iCnt = 0;
    size = Count(*Head);

    if((iPos < 1) || (iPos > size))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos ==1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        Temp = *Head;

        for(iCnt =1; iCnt < (iPos-1) ;iCnt++)
        {
            Temp = Temp -> Next;
        }

        Temp -> Next = Temp -> Next -> Next;
        free(Temp -> Next -> Prev);
        Temp -> Next -> Prev = Temp;
     }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  Main fucntion
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE first = NULL;
	
	//iRet is used to preserve the return value from Count Funciton.
    int ret = 0;
    
	//Inserting Values using InsertFirst
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    //Inserting Values using InsertLast
    InsertLast(&first,51);
    InsertLast(&first,101);

    // Displaying the Linked List
    Display(first);
	
    // Counting the nodes of Linked List
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    //Inserting Values at specfic position on a Linked List
    InsertAtPos(&first,75,3);
    Display(first);
	ret = Count(first);
	printf("Number of nodes are : %d\n",ret);

    //Deleting Values at specfic position on a Linked List
    DeleteAtPos(&first,3);
    Display(first);
	ret = Count(first);
	printf("Number of nodes are : %d\n",ret);

    //Deleting Values using DeleteFirst
    DeleteFirst(&first);
	Display(first);
	ret = Count(first);
	printf("Number of nodes are : %d\n",ret);
	
	//Deleting Values using DeleteLast
    DeleteLast(&first);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    // Return 0 notifies Operation System to terminate successfully
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//              OUTPUT:
//  Data from linked list is :
// | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>  NULL
// Number of nodes are : 4
// Data from linked list is :
// | 11 | <=> | 21 | <=> | 75 | <=> | 51 | <=> | 101 | <=>  NULL
// Number of nodes are : 5
// Data from linked list is :
// | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>  NULL
// Number of nodes are : 4
// Data from linked list is :
// | 21 | <=> | 51 | <=> | 101 | <=>  NULL
// Number of nodes are : 3
// Data from linked list is :
// | 21 | <=> | 51 | <=>  NULL
// Number of nodes are : 2
//
//////////////////////////////////////////////////////////////////////////////////////////////////