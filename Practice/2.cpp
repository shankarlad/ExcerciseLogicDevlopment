/*
    *         *
   ***       ***
  *****     *****
 *******   *******
*******************
 *****************
  ***************
   *************
    ***********
	 *********
	  *******
	   *****
	    ***
		 * 
		 
		*/
#include<iostream>
using namespace std;

int main() {
	
	int n,i,j,s,k;
	
	cout << "Please enter the number of rows : ";
	cin >> n;
	
	for (i = 1; i <=2*n; i++) {
		for (s = 0; s < i; s++) {
			cout << " ";
		}
		for (j = 0; j < 2*n-2*i; j++) {
			cout << "*";
		}
		for (k = 1; k < i; k++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
		   
