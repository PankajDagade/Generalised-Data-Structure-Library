import java.lang.*;
import java.util.*;

class node 
{
	public int Data;
	public node next;
}

class SCLL
{
	public node Head;
	public node Tail;
	public int Count;
	
	public SCLL()
	{
		Head = null;
		Tail = null;
		Count = 0;
	}
	
	public void InsertFirst(int no)
	{
		node newn = new node();
		
		newn.Data = no;
		newn.next = null;
		
		if( (Head == null) && (Tail == null) ){
			Head = newn;
			Tail = newn;
		}else{
			newn.next = Head;
			Head = newn;
		}
		Tail.next = Head;
	}
	
	public void InsertLast(int no)
	{
		node newn = new node();
		
		newn.Data = no;
		newn.next = null;
		
		if( (Head == null) && (Tail == null) ){
			Head = newn;
			Tail = newn;
		}else{
			
			Tail.next = newn;
			Tail = newn;
		}
		Tail.next = Head;
	}
	public void Display()
	{
		node temp = Head;
		
		if( (Head == null) && (Tail == null) ){
			return;
		}
		do
		{
			System.out.print("|"+temp.Data+"|->");
			temp = temp.next;
		}while(temp != Head);
		
		System.out.print("NULL");
	}
	
	public int CountNode()
	{
		int iCnt = 0;
		node temp = Head;
		
		if( (Head == null) && (Tail == null) ){
			return 0;
		}
		do
		{
			iCnt++;
			temp = temp.next;
		}while(temp != Head);
		
		return iCnt;
	}

    public void InsertAtPos(int no, int pos)
	{
		node newn = new node();
		
		newn.Data = no;
		newn.next = null;
		
		if( (Head == null) && (Tail == null) ){
			Head = newn;
			Tail = newn;
		}else{
			
			node temp = Head;
			
			while(temp.next.next != Head)
			{
				temp = temp.next;
			}
			newn.next = temp.next;
			temp.next = newn;
		}
		Tail.next = Head;
	}
     
    public void DeleteFirst()
	{
		if( (Head == null) && (Tail == null) )
		{
			return;
		}else if(Head == Tail)
		{
			Head = null;
			Tail = null;
		}else{
			
			Head = Head.next;
			Tail.next = Head;
		}
	}

    public void DeleteLast()
	{

		if(Head == null && Tail == null)
		{
			return;
		}else{
			
			node temp = Head;
			
			
			while(temp.next != Tail)
			{
				temp = temp.next;
			}
			Tail = temp;
			Tail.next = Head;
		}
		Count--;
	}
    
    public void DeleteAtPos(int  pos)
	{
		if((Head == null) && (Tail == null) )
		{
			return;
		}
		else{
			
			node temp = Head;
			node NodetoDelete = Head;
			
			for(int i = 1 ; i < pos-1 ; i++)
			{
				temp = temp.next;
			}
			NodetoDelete = temp.next;
			temp.next = temp.next.next;
			NodetoDelete = null;
			
			Count--;
		}
	}	
}
class SinglyCircularLL
{
	public static void main(String args[])
	{
		int iRet = 0;
		SCLL sobj = new SCLL();
		
		sobj.InsertFirst(8);
		sobj.InsertFirst(7);
		sobj.InsertFirst(6);
		sobj.InsertLast(9);
		sobj.InsertLast(10);
		sobj.Display();
		iRet = sobj.CountNode();
		System.out.println("\nNumber of Elements are : "+sobj.CountNode());
		
		sobj.InsertAtPos(55,3);
		sobj.Display();
		iRet = sobj.CountNode();
		System.out.println("\nNumber of Elements are: "+sobj.CountNode());
		
		sobj.DeleteFirst();
		sobj.Display();
		iRet = sobj.CountNode();
		System.out.println("\nNumber of Elements are : "+sobj.CountNode());
	
		sobj.DeleteLast();
		sobj.Display();
		iRet = sobj.CountNode();
		System.out.println("\nNumber of Elements are : "+sobj.CountNode());
		
		sobj.DeleteAtPos(3);
		sobj.Display();
		iRet = sobj.CountNode();
		System.out.println("\nNumber of Elements are : "+sobj.CountNode());
	}
}