package com.tiaa;

import java.util.LinkedHashMap;
import java.util.Map;

public class FirstNonRepeatedCharacter {
	
	public static Character firstNonRepeatedCharacter(char[] arr){
		LinkedHashMap<Character,Integer> map = new LinkedHashMap<Character,Integer>();
		for(int i=0;i<arr.length;i++) {
			if(map.containsKey(arr[i]))
				map.put(arr[i], map.get(arr[i])+1);
			else
				map.put(arr[i], 1);
		}
		
		for(Map.Entry<Character, Integer> entry: map.entrySet()) {
			if(entry.getValue()==1)
				return entry.getKey();
		}
		
		return null;
	}
	
	public static void main(String[] args) {
		String s = "MorningStar";
		char c = firstNonRepeatedCharacter(s.toCharArray());
		System.out.println(c);
	}
}