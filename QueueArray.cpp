#include<iostream>
using namespace std;

class Queue
{
	private:
	int front,rear,size;
	int *queue;
	
	public:	
	
	Queue(int s)
	{
		 front=0;
		 rear=0;
		 size=s;
		 queue= new int;
		
	}
	
	~Queue()
	{
		delete [] queue;
	}
	
	void AddAtTail(int data)
	{
		
		if(size == rear)
		{
			cout<<"Queue is Full...";
			return;
			
		}
		else
		{
			queue[rear]=data;
			rear++;
		}
		return;
		
	 	
	}
	
	void RemoveAtHead()
	{
		if(front == rear)
		{
			cout<<"Queue is empty..";
			return;
		}
		
		else
		{
			
			for(int i = 0 ; i<rear-1 ; i++ )
			{
				queue[i]=queue[i+1];
			}
			
			rear--;
			
		}
	
		return;
	}
	
	void display()
	{
		if(front==rear)
		{
			cout<<"Queue is empty..";
			return;
		}
		else
		{
			for(int i = front ; i < rear ; i++ )
			{
				cout<<queue[i]<<",";
				
			}
			cout<<endl<<endl;
			
		}
		
		return;
	}
	
	void peek()
	{
		if(front == rear)
		{
			cout<<"Queue is empty..";
			
		}
		else
		{
			cout<<"First item = "<<queue[front]<<endl<<endl;
			
		}
		
		
	}
	
	void isFull()
	{
	 	for(int i=front ; i<rear ; i++)
	 	{
	 		if(queue[4] != 0)
	 		{
	 			cout<<"Queue is full.."<<endl<<endl;
				return;			  
			}
	 		else
	 		cout<<"Queue is not full.."<<endl<<endl;
	 		return;
		}
	 	cout<<endl<<endl;
	 
	 
	}
	
	void isEmpty()
	{
		for(int i=front ; i<rear ; i++)
	 	{
	 		if(queue[i] == NULL)
	 		{
	 			cout<<"Queue is empty.."<<endl<<endl;
				return;			  
			}
	 		else
	 		cout<<"Queue is not empty..";
	 		return;
		}
	 	cout<<endl<<endl;
		
	}
	
	void qSize()
	{
		int sizee=0;
		for(int i=front ; i<rear ; i++)
		{
			sizee++;		
		}
		cout<<"size = "<<sizee<<endl;
	}
};

int main()
{
	Queue obj(5);
	
	cout<<"Inserting 4 items.."<<endl;
	obj.AddAtTail(1);
	obj.AddAtTail(2);
	obj.AddAtTail(3);
	obj.AddAtTail(4);
	obj.display();
	
	cout<<"Deleting 3 items.."<<endl;
	obj.RemoveAtHead();
	obj.RemoveAtHead();
	obj.RemoveAtHead();
	
	obj.display();
	obj.isFull();
	
	cout<<"Inserting 3 items.."<<endl;
	obj.AddAtTail(5);
	obj.AddAtTail(6);
	obj.AddAtTail(7);
	obj.display();
	
	obj.peek();
	
	obj.AddAtTail(99);
	obj.display();
	
	obj.qSize();
	
	
	return 0;
}



