#include <iostream>
using namespace std;


class Stack
{
private:
    struct node
    {
        int data;
        node *next;
    };

    node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int value)
    {
        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;
        ptrNew->next = NULL;
        
        if (head == NULL)
        {
            head = ptrNew;
            return;
        }
        
        ptrNew->next=head;
        head=ptrNew;
        return;
        
    }
    
        int pop()
    {
    	
        if (isEmpty())
        {
            cout<<"Stack Empty!"<<endl;
            return -1;
        }
int value=head->data;
		head=head->next;
		return value;
    }

    bool isEmpty()
    {
        if (head == NULL)
			return true;
        else
			return false;
    }
    
    void size()
    {
        int size = 0;

        node *ptrTemp = head;

        while (ptrTemp != NULL)
        {
            size++;
            ptrTemp = ptrTemp->next;
        }

        cout << size << " elements in list";
        return;
    }

    int peek()
    {
    	if(!isEmpty())
        return head->data;
        
        return -1;
    }

    void printAll()
    {
        node *ptrTemp = head;
        cout << endl;
        while (ptrTemp != NULL)
        {
            cout << ptrTemp->data << (ptrTemp->next == NULL ? "" : ",");
            ptrTemp = ptrTemp->next;
        }
        cout << endl
             << endl;
        return;
    }
    
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
	s.push(4);
	
	s.printAll();
	
	cout<<"Peek: "<<s.peek()<<endl;
	
	cout<<"popped"<<s.pop()<<endl;
	cout<<"popped"<<s.pop()<<endl;
	cout<<"popped"<<s.pop()<<endl;
	
	cout<<"Peek: "<<s.peek()<<endl;
	s.printAll();   
}
