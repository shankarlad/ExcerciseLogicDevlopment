#include <iostream>
using namespace std;
 
void decToOctal(int n)
{
     
  
    int octalNum[10];
 
    int i = 0;
    while (n != 0) {
 
        octalNum[i] = n % 8;
        cout<<"rem "<<octalNum[i]<<endl;
        n = n / 8;
        cout<<"num "<<n<<endl;
        i++;
    }
 
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}

int main()
{
    int n = 33;
     
 
    decToOctal(n);
 
    return 0;
}
