package com.tiaa;

public class DuplicateInArray {
	
	public static void printDuplicate(int[] arr) {
		int sum = 999*(1000)/2;
		int sum2=0;
		for(int i=0;i<1000;i++)
			sum2=sum2+arr[i];
		
		 System.out.println("duplicate numer is: "+ (sum2-sum));
		
	}

	public static void main(String[] args) {
		int[] arr = new int[1000];
		for(int i=0;i<999;i++) {
			arr[i]=i+1;
		}
		
		arr[999]= 8;// duplicate
		
		printDuplicate(arr);

	}

}