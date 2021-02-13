#include<iostream>
using namespace std;
int main()
{
    for(int i=5;i>=1;i--)
        {   char c='[';
        for(int j=1;j<=(2*i-1);j++)
            {
                if(j<=i)
                    cout<<--c;
                 else
                    cout<<++c;

            }
            cout<<endl;
        }
        return 0;
}

