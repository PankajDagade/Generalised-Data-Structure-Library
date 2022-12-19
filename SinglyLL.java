import java.lang.*;
import java.util.*;

class node 
{
	public int data;
	public node next;
}

class SLL 
{
	
	public node Head;
	public int Count;
	
	public SLL()
	{
		Head = null;
		Count = 0;
	}
	
	public void InsertFirst(int no)
	{
		node newn = new node();
		
		newn.data = no;
		newn.next = null;
		
		if(Head == null){
			Head = newn;
		}else{
			newn.next = Head;
			Head = newn;
		}
		Count++;
	}
	
	public void InsertLast(int no)
	{
		node newn = new node();
		
		newn.data = no;
		newn.next = null;
		
		if(Head == null){
			Head = newn;
		}else{
			node temp = Head;
			
			while(temp.next != null){
				temp = temp.next;
			}
			temp.next = newn;
		}
		Count++;
	}
	public void Display()
	{
		node temp = Head;
		
		System.out.println();
		System.out.println("Elements of Linked list are : ");
		while(temp != null){
			System.out.print("|"+temp.data+"|->");
			temp = temp.next;
		}
		System.out.println("NULL");
	}
	public void InsertAtPos(int no, int pos)
	{
		if((pos < 1) || (pos > 1+Count )){
			return;
		}
		if(pos == 1){
			InsertFirst(no);
		}
		if(pos == Count+1){
			InsertLast(no);
		}else{
			node newn = new node();
			
			newn.data = no;
			newn.next = null;
			
			node temp = Head;
			
			for(int i = 1 ; i < pos - 1 ; i++){
				temp = temp.next;
			}
			
			newn.next = temp.next;
			temp.next = newn;
			
			Count++;
		}
	}
	public void DeleteFirst()
	{
		if(Count == 0){
			return;
		}else if(Count == 1){
			Head = null;
		}else{
			node temp = Head;
			
			Head = Head.next;
			temp = null;
		}
		Count--;
	}
	public void DeleteLast()
	{
		if(Count == 0){
			return;
		}else if(Count == 1){
			Head = null;
		}else{
			node temp = Head;
			while(temp.next.next != null){
				temp = temp.next;
			}
			temp.next = null;
		}
		Count--;
	}
	public int CountNode()
	{
		return Count;
	}
	public void DeleteAtPos(int Pos)
	{
		if( (Pos < 1) || (Pos > Count) ){
			return;
		}
	    if(Pos == 1){
			DeleteFirst();
		}else if(Pos == Count){
			DeleteLast();
		}else{
			node temp = Head;
			
			for(int i = 1 ; i<Pos-1 ; i++){
				temp = temp.next;
			}
			temp.next = temp.next.next;
			
			Count--;
		}
	}
}

class SinglyLL
{
	public static void main(String args[])
	{
		int iRet = 0;
		
		SLL obj = new SLL();
		
		obj.InsertFirst(8);
		obj.InsertFirst(7);
		obj.InsertFirst(6);
		obj.InsertLast(9);
		obj.InsertLast(10);
		obj.Display();
		iRet = obj.CountNode();
		System.out.println("Number of Elements are : "+obj.CountNode());
		
		obj.InsertAtPos(55,3);
		obj.Display();
		iRet = obj.CountNode();
		System.out.println("Number of Elements are: "+obj.CountNode());
		
		obj.DeleteFirst();
		obj.Display();
		iRet = obj.CountNode();
		System.out.println("Number of Elements are : "+obj.CountNode());
		
		obj.DeleteLast();
		obj.Display();
		iRet = obj.CountNode();
		System.out.println("Number of Elements are : "+obj.CountNode());
		
		obj.DeleteAtPos(3);
		obj.Display();
		iRet = obj.CountNode();
		System.out.println("Number of Elements are : "+obj.CountNode());
	}
}