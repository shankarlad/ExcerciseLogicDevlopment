#include <iostream>
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(int size){
    	front = 0;
        rear = -1;
        this->size = size;
        Q = new int[size];
	}
	
	void enqueue(int e);
	int dequeue();
	void display();
	bool isEmpty();
	bool isFull();
	
};

void Queue::enqueue(int e){
	rear++;
	Q[rear] = e;
}

int Queue::dequeue(){
	int temp = Q[front];
	Q[front] = 0;
	front++;
	return temp;
}

bool Queue::isEmpty(){
	if(front>rear)
		return true;
	else 
		return false;
}

bool Queue::isFull(){
	if(rear == size-1)
		return true;
	else 
		return false;
}

void Queue::display(){
	for(int i=front;i<=rear;i++){
		cout << Q[i] << " "; 
		cout<<endl;
	}
}

int main()
{
    int size;
	cout<<"Please enter the maxsize of the Queue"<<endl;
	cin>>size;
	Queue q(size);
	
	int choice = 1;
	int e;
	while(choice){
		cout<< "Please select a choice"<<endl;
		cout<< "1. to enqueue\n";
		cout<< "2. to dequeue\n";
		cout<< "3. to print the queue\n";
		cout<< "0. to end\n";
		cin>>choice;
		switch(choice){
			
			case 1:
				if(!q.isFull()){
					cout<<"Enter element to enqueue: "<<endl;
					cin>>e;	
					q.enqueue(e);
				}
				else
				cout<<"Queue Full!!!!"<<endl;
				break;
				
			case 2:
				if(!q.isEmpty())
				cout<<"Dequeued element: "<<q.dequeue()<<endl;
				else
				cout<<"Queue Empty!!!!"<<endl;
				break;
				
			case 3:
				if(!q.isEmpty()){
					cout<<"Printing Queue...: "<<endl;
					q.display();	
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
    
    return 0;
}


