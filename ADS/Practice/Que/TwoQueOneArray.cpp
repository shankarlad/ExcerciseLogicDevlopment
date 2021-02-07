#include<iostream>
using namespace std;

int Q[100],maxsize,r1,f1,r2,f2;

initQueue(int size){
	maxsize = size;
	r1 = -1;
	f1 = 0;
	r2 = maxsize;
	f2 = maxsize-1;
}

bool isFull(){
	if(r1+1 == r2 || r2-1 == r1)
	return true;
	
	else return false;
}

bool isEmpty1(){
	if(f1>r1) return true;
	
	else return false;
}

bool isEmpty2(){
	if(f2<r2) return true;
	
	else return false;
}


void enqueue1(int e){
	if(isFull()){
		cout<<"Queues are Full!!!\n";
	}
	else{
		Q[++r1] = e;	
	}
}

void dequeue1(){
	if(isEmpty1()){
		cout<<"Queue1 is Empty!!!\n";
	}
	else{
		int temp = Q[f1];
		Q[f1] = 0;
		f1++;
		cout<<"Dequeued element: "<<temp<<endl;		
	}
	
}

void enqueue2(int e){
	if(isFull()){
		cout<<"Queues are Full!!!\n";
	}
	else{
		Q[--r2] = e;	
	}
}

void dequeue2(){
	if(isEmpty2()){
		cout<<"Queue2 is Empty!!!\n";
	}
	else{
		int temp = Q[f2];
		Q[f2] = 0;
		f2--;
		cout<<"Dequeued element: "<<temp<<endl;	
	}
	
}

void printQueue1(){
	if(isEmpty1()){
		cout<<"Queue1 is Empty!!!\n";
	}
	else{
		for(int i=f1;i<=r1;i++)
		cout<<Q[i]<<" ";
		cout<<endl;	
	}
}


void printQueue2(){
	if(isEmpty2()){
		cout<<"Queue2 is Empty!!!\n";
	}
	else{
		for(int i=f2;i>=r2;i--)
		cout<<Q[i]<<" ";
		cout<<endl;	
	}
}

int main(){
	int size;
	cout<<"Please enter the maxsize of the Queue"<<endl;
	cin>>size;
	initQueue(size);
	
	int choice = 1;
	int e;
	while(choice){
		cout<< "Please select a choice"<<endl;
		cout<< "1. to enqueue in Queue-1\n";
		cout<< "2. to enqueue in Queue-2\n";
		cout<< "3. to dequeue from Queue-1\n";
		cout<< "4. to dequeue from Queue-2\n";
		cout<< "5. to print the Queue-1\n";
		cout<< "6. to print the Queue-2\n";
		cout<< "0. to end\n";
		cin>>choice;
		switch(choice){
			case 1:
				{
					cout<<"Enter element to enqueue: "<<endl;
					cin>>e;	
					enqueue1(e);
					break;
				}
			case 2:
				{
					cout<<"Enter element to enqueue: "<<endl;
					cin>>e;	
					enqueue2(e);
					break;
				}	
				
			case 3:
				dequeue1();
				break;
				
			case 4:
				dequeue2();
				break;
				
			case 5:
				printQueue1();
				break;			
			
			case 6:
				printQueue2();
				break;
				
			case 0:
				cout<<"Exiting....!!!!!!"<<endl;
				break;
				
			default :
				cout<<"Invalid input"<<endl;
				break;	
		}
	}
	
	
}








