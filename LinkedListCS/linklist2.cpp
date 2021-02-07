#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
        Node* next;
    
    public:
        Node(int data)
        {
            this->data=data;
            next=NULL;
        }
        
        int getdata()
        {
            return data;
        }
        
        void setData(int data)
        {
            this->data=data;
        }
        
        Node* getNext()
        {
            return next;
        }
        
        void setNext(Node* next)
        {
            this->next=next;
        }
};

class LinkedList
{
   public:
        Node* head;
        
   public:
        LinkedList()
        {
            this->head=NULL;
        }
        
        int addBefore(int data)
        {
            Node* node=new Node(data);
            if(head==NULL)
            {
                head=node;
            }
            else
            {
                node->setNext(head);
                head=node;
            }
        }
        
        int AddEnd(int data)
        {
            Node* node=new Node(data);
            if(head==NULL)
            {
                head=node;
            }
            else
            {
                Node* temp=head;
                while(temp->getNext()!=NULL)
                {
                    temp=temp->getNext();
                }
                node->setNext(NULL);
                temp->setNext(node);
            }
        }
        
        void printLinklist()
        {
            Node* temp=head;
            while(temp->getNext()!=NULL)
            {
                cout<<temp->getdata()<<"->";
                temp=temp->getNext();
            }
            cout<<temp->getdata()<<endl;
        }
};

int main()
{
   LinkedList l1,l2;
   int d;
   cout<<"enter 10 elements randomly"<<endl;
   for(int i=0;i<10;i++)
   {
       cin>>d;
       if(d%2==0)
       {
          l1.AddEnd(d);
       }
       else
       {
           l2.AddEnd(d);
       }
       
   }
   
    Node* head=l1.head;
    Node* head1=l2.head;
    
    Node* temp=head;
    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();
    }
    temp->setNext(head1);
    
    l1.printLinklist();
    return 0;
}
