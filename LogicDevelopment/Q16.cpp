#include<iostream>
#include <math.h>
using namespace std;
int main(){
	
	int num, originalNum, remainder, n = 0;
   float result = 0.0;

   cout<<"Enter an integer: ";
   cin>>num;

   originalNum = num;


   for (originalNum = num; originalNum != 0; ++n) {
       originalNum /= 10;
   }

   for (originalNum = num; originalNum != 0; originalNum /= 10) {
       remainder = originalNum % 10;

      
      result += pow(remainder, n);
   }

  
   if ((int)result == num)
   cout<<"is an Armstrong number.";
   else
    cout<<"is not an Armstrong number.";
   return 0;
}
