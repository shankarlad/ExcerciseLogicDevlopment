#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class DynamicQueue{
	private:
		Node *front,*rear;
	public:
		void createQueue();
		void enqueue(int e);
		void dequeue();
		void printQueue();
		bool isEmpty();
};

void DynamicQueue::createQueue(){
	front = NULL;
	rear = NULL;
}

void DynamicQueue::enqueue(int e){
	Node *n;
	n = new Node;
	n->data = e;
	n->next = NULL;
	
	if(front==NULL){
		front = rear = n;
	}
	else{
		rear->next = n;
		rear = n;
	}
}

bool DynamicQueue::isEmpty(){
	if(front == NULL)
	return true;
	else return false;
}

void DynamicQueue::dequeue(){
	Node *t;
	if(isEmpty()){
		cout<<"Queue is Empty!!\n";
	}
	else{
		t = front;
		front = front->next;
		cout<<"Dequeued element: "<<t->data<<endl;
		delete t;
	}
}

void DynamicQueue::printQueue(){
	Node *t;
	if(!isEmpty()){
		t = front;
		while(t!=NULL){
			cout<<t->data<<" ";
			t=t->next;
		}
		cout<<endl;
	}
	else cout<<"Queue is Empty\n";
}


int main(){
	DynamicQueue q;
	q.createQueue();
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
				{
					cout<<"Enter element to enqueue: "<<endl;
					cin>>e;	
					q.enqueue(e);
					break;
				}
			case 2:
				if(!q.isEmpty())
				q.dequeue();
				else
				cout<<"Queue Empty!!!!"<<endl;
				break;
			case 3:
				if(!q.isEmpty()){
					cout<<"Printing Queue...: "<<endl;
					q.printQueue();	
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
