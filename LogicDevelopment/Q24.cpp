#include<iostream>
using namespace std;
long int multiplyNumbers(int n) {
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}

int main() {
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    cout<<"Factorial of "<< n <<" :"<<multiplyNumbers(n);
    return 0;
}


