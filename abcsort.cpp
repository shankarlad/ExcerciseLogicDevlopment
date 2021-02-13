#include<iostream>
#include<cstring>

using namespace std;

void SortName(string arr[],int n)
{
    string temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].compare(arr[j+1])>0)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the Number of Members : ";
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    
    SortName(arr,n);
    cout<<"Sorted Names are as follows : "<<endl;
	for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}
