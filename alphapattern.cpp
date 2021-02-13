#include <iostream>

using namespace std;

int main()
{
    int i,j;char k;
   
  /*  for(i=1 ; i<=10 ;i++)
    {
		k='z';
        for(j=1 ; j<=19 ; j++)
        {
            if(j>=11-i  &&  j<=i+9)
            {
            	cout<<k;
            	
            	if(j<10)
            		k--;
            	else
            		k++;
            }
            else
            cout<<" "; 
        }
        cout<<endl;
    }*/

   
    for(i=1 ; i<=10 ;i++)
    {
		k='z';
        for(j=1 ; j<=19 ; j++)
        {
            if(j>=i  &&  j<=20-i)
            {
            	cout<<k;
            
            	if(j<10)
            		k--;
            
            	else
            		k++;
            }
            else
            cout<<" "; 
        }
        cout<<endl;
    }

    return 0;
}


