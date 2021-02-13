package com.tiaa;

public class PowerOfTen {

	public static boolean powerOf10(int n){
		if(n==1)
			return true;
		int r;
		while(n!=1) {
			r=n%10;
			if(r!=0)
				return false;
			n=n/10;
			if(n<10) {
				if(n!=1)
					return false;
			}
		}
		
		return true;
					
	}
	
	public static void main(String[] args) {
		System.out.println(powerOf10(200));

	}

}