package com.tiaa;

import java.util.HashSet;

public class DetectLLloop<T>{
	//head node
	 Node<T> head;
	
	//static nested class to define  structure of node
	 public static class Node<T>{
		 public T data;
		 public Node<T> next;
		
		public Node(T data) {
			this.data = data;
			this.next = null;
		}
	}
		
	//Insert Node at the end of a singly Linked list
	public void insert(T data){
		Node<T> newNode =new Node<T>(data);
		if(head == null) {
			head = newNode;
		}
		else {
			Node<T> currentNode = head;
			while(currentNode.next !=null) {
				currentNode = currentNode.next;
			}
			currentNode.next = newNode;
			
		}
	}


	
	public boolean detectLoop(Node<T> h) {
		HashSet<Node<T>> set = new HashSet<Node<T>>();
		while(h!=null) {
			if(set.contains(h))
				return true;
			
			set.add(h);
			h = h.next;
						
		}
			
		return false;
	}
	
	public static void main(String[] args) {
		DetectLLloop<Integer> ll = new DetectLLloop<Integer>();
		
		ll.insert(1);
		ll.insert(2);
		ll.insert(3);
		ll.insert(4);
		ll.insert(5);
		
		ll.head.next.next.next.next.next=ll.head.next;
		
		System.out.println(ll.detectLoop(ll.head));
		
		
	}	
	
	
}