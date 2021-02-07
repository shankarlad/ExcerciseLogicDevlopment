#include<iostream>
using namespace std;

int Q[100],maxsize,rear,front;

initQueue(int size){
	maxsize = size;
	rear = -1;
	front = 0;
}

void enqueue(int e){
	rear++;
	Q[rear] = e;
}

int dequeue(){
	int temp = Q[front];
	Q[front] = 0;
	front++;
	return temp;
}

bool isEmpty(){
	if(front>rear){
		return true;
	}
	else return false;
}

bool isFull(){
	if(rear == maxsize-1)
	return true;
	
	else return false;
}

int firstInQueue(){
	return Q[front];
}

int lastInQueue(){
	return Q[rear];
}

void printQueue(){
	for(int i=front;i<=rear;i++){
		cout << Q[i] << " "; 
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
		cout<< "1. to enqueue\n";
		cout<< "2. to dequeue\n";
		cout<< "3. to get first element in queue\n";
		cout<< "4. to get last element in queue\n";
		cout<< "5. to print the queue\n";
		cout<< "0. to end\n";
		cin>>choice;
		switch(choice){
			
			case 1:
				if(!isFull()){
					cout<<"Enter element to enqueue: "<<endl;
					cin>>e;	
					enqueue(e);
				}
				else
				cout<<"Queue Full!!!!"<<endl;
				break;
				
			case 2:
				if(!isEmpty())
				cout<<"Dequeued element: "<<dequeue()<<endl;
				else
				cout<<"Queue Empty!!!!"<<endl;
				break;
			
			case 3:
				if(!isEmpty())
				cout<<"First element in queue: "<<firstInQueue()<<endl;
				else
				cout<<"Queue Empty!!!!"<<endl;
				break;
				
			case 4:
				if(!isEmpty())
				cout<<"Last element in queue: "<<lastInQueue()<<endl;
				else
				cout<<"Queue Empty!!!!"<<endl;
				break;	
				
			case 5:
				if(!isEmpty()){
					cout<<"Printing Queue...: "<<endl;
					printQueue();	
				}	
				else
				cout<<"Queue Empty!!!!"<<endl;
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







