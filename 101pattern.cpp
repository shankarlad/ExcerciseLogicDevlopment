#include <bits/stdc++.h>
using namespace std;

int Pattern(string s)
{
	int l=s.length(),count=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]!='0') 
			count++;
	}
		if(count==l) 
		return 0;
	
	int i=0,flag=0,start=0,end=1;
	count=0;

	while(i<l)
	{

		while(s[i]!='1')
		{ 
			i++;
		}

		i=i+1;
	
		if(s[i]=='0')
		{ 

			while(s[i]=='0')
				i++;
			
			if(s[i]=='1')
			{
				count++;
			}
		}
	}
	return count; 
}

int main()
{  

	string s;  
	cin>>s;
	int k=Pattern(s);
	cout<<k<<endl;    

	return 0;
}
