// Online C++  to run C++ program online
#include <iostream>
using namespace std;
int Q[100],rear,front, cnt,maxsize;

void createQueue(int size){
    rear=-1;
    front=0;
    cnt=0;
    maxsize=size;
}

void enqueue(int e){
    cnt++;
    rear= (rear+1)%maxsize;
    Q[rear]=e;
}

int dequeue(){
    cnt--;
    int temp= Q[front];
    Q[front] = 0;
    front=(front+1)%maxsize;
    return temp;
}

bool isFull(){
    if(cnt==maxsize)
    	return true;
    else 
		return false;
}


bool isEmpty(){
    if(cnt==0)
    return true;
    else return false;
}

void printQueue(){
	int i=0;
	int j= front;
	while(i<cnt){
		cout<<Q[j]<<" ";
		i++;
		j= (j+1)%maxsize;
	}
	cout<<endl;
}
int main() {
    int size,no;
    cout<<"please enter the size"<<endl;
    cin>>size;
    createQueue(size);
    int c=1;
    while(c){
    cout<<"please enter choice\n1 enqueue\n2 dequeue\n3 print queue\n0 exit"<<endl;
    cin>>c;
    switch(c){
    	
    case 1:
    
    if(!isFull()){
    	 cout<<"please enter the number"<<endl;
    cin>>no;
    	 enqueue(no);
    	 }
    else cout<<"Queue Full!!!\n";
    break;
    
    case 2:
    if(!isEmpty())
    cout<<"dequeued element "<<dequeue()<<endl;
    else cout<<"Queue Empty!!!!\n";
       break;
       
       case 3:
       	if(!isEmpty())
       	printQueue();
       	else cout<<"Queue Empty!!!!\n";
       	break;
    case 0:
    cout<< "exiting!!!!!\n";
    break;
    default:
    cout<<"invalid input\n";
    break;
    
    }
    }

    return 0;
}

