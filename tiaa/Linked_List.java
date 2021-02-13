package com.tiaa;
class Node{
	int data;
	Node next;
	int count;
	Node(int data){
		this.data=data;
	}
	
	Node(){
		this.count=0;
		this.next=null;
	}
	
	public static boolean detectCycle(Node head) {
		
		while(head!=null) {
			if(head.count==1)
				return true;
			head.count=1;
			head=head.next;
		}
		
		return false;
	}
	
	public Node push(Node head,int data) {
		
		Node node=new Node(data);
		node.next=head;
		node.count=0;
		head=node;
		return head;
	}	
}

public class Linked_List {
	public static void main(String[] args) {
		Node head=new Node();
		head = head.push(head, 20);
	    head = head.push(head, 4);
	    head = head.push(head, 15);
	    head = head.push(head, 4);
	    head = head.push(head, 10);
	    
	    if(Node.detectCycle(head)) {
	    	System.out.println("cycle present");
	    }else {
	    	System.out.println("No cycle");
	    }
	}

}