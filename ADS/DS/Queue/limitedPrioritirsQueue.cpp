
/*
This is a limited priorities queue.
	Data:
		int cnt-(to keep count of elements)
		
		int nop-(number of priorities)
		
		int size-(maximum number of elements that can be stored in the queue)
		
		if user wants 3 priorities, we will have to create a different array for each priority, so here we will have 
		3 arrays, when user wants to add element to the queue, he will be asked to enter a priorty for that element
		(1 OR 2 OR 3) if priority is 1, it will be added to first array.If priority is 2, it will be added to second array.
		and so on.
		Each array must have the same size equal to the size of the queue, because if user enters all elements with the 
		same priority than we should be able to store them in a single array.
		
		int **Q-(array of pointers to array of integers)
		
		if size = 8, nop = 3 (1,2,3) where 1 is highest priority, 3 is lowest
		Q = [100, 200, 300]   ---  these are addresses of array1(for priority 1),array2(for priority 12),
									array3(for priority 3)
		
		Q[0] = [12,16,88,X,X,X,X,X]  each array is of size 8, X denotes no data.
		Q[1] = [10,9,14,X,X,X,X,X]
		Q[2] = [33,45,X,X,X,X,X,X]
		
		now cnt = 8 and size = 8 so it is full.
		
		to dequeue we must dequeue from the first array till it gets empty , then from the mext array and so on....
		
*/

#include<iostream>
using namespace std;

class Queue{
	private:
	int nop;//number of priorities
	int size; // maxsize of the queue
	int **Q; // 
	int *rear;
	int *front;
	int count;
	
	public:
		Queue(int size,int nop){
		this->size = size;
		count = 0;
		this->nop = nop;
        Q = new int*[nop];
        
		for(int i=0;i<nop;i++){
        	Q[i] = new int[size];
		}
		
		rear = new int[nop];
		for(int i=0;i<nop;i++){
        	rear[i] = -1;
		}
		
		front = new int[nop];
		for(int i=0;i<nop;i++){
        	front[i] = 0; 
		 }
        
    }

	void enqueue(int e,int p);
	int dequeue();
	void display();
	bool isEmpty();
	bool isFull();    
};

void Queue::enqueue(int e, int p){
	count++;
	rear[(p-1)]++;
	Q[(p-1)][rear[(p-1)]] = e;
}

int Queue::dequeue(){
	for(int i=0;i<nop;i++){
		if(front[i]<=rear[i]){
			int temp = 	Q[i][front[i]];
			front[i]++;
			count--;
			return temp;
		}
	}
}

bool Queue::isEmpty(){
	if(count == 0){
		return true;
	}
	else return false;
}

bool Queue::isFull(){
	if(count == size)
	return true;
	
	else return false;
}

void Queue::display(){
	for(int i=0;i<nop;i++){
		for(int j = front[i];j<=rear[i];j++){
			cout << Q[i][j] << " "; 
		}
	}
	cout<<endl;
}



int main()
{
    int size,np;
	cout<<"Please enter the maxsize of the Queue"<<endl;
	cin>>size;
	cout<<"Please enter the number of priorities"<<endl;
	cin>>np;
	Queue q(size,np);
	
	int choice = 1;
	int e,p;
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
					cout<<"Enter priority("<<1<<"-highest to "<<np<<"-lowest): "<<endl;
					cin>>p;
					q.enqueue(e,p);
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

