#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

int length(node* head)
{
	int len=0;
	while(head)
	{
		len++;
		head=head->next;
	}
	return len;
}

void insertionAtFront(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}
	node* n=new node(d);
	n->next=head;
	head=n;
}

void insertionAtEnd(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}

	node* n=new node(d);
	tail->next=n;
	tail=n;
}

void insertionAtPos(node* &head,node* &tail,int d,int p)
{
	if(p==0)
	{
		insertionAtFront(head,tail,d);
		return;
	}

	else if(p>=length(head))
	{
		insertionAtEnd(head,tail,d);
		return;
	}

	int pos=1;
	node* temp=head;
	node* n=new node(d);
	while(pos<p)
	{
		temp=temp->next;
		pos++;
	}

	n->next=temp->next;
	temp->next=n;
}

void deletionAtFront(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}

	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}

	else
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
}


void deletionAtEnd(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}

	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}

	else
	{
		node* temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		delete tail;
		tail=temp;
	}
}

void deletionAtPos(node* &head,node* &tail,int p)
{
	if(p==0)
	{
		deletionAtFront(head,tail);
		return;
	}
	else if(p==length(head)-1)
	{
		deletionAtEnd(head,tail);
		return;
	}

	else if(p>=length(head))
	{
		return;
	}

	else
	{
		node* temp=head;
		int pos=1;
		while(pos<p)
		{
			temp=temp->next;
			pos++;	
		}

		node* n=temp->next;
		temp->next=n->next;
		delete n;
	}
}

node* search(node* head,int d)
{
	while(head)
	{
		if(head->data==d)
		{
			return head;
		}
		head=head->next;
	}
	return NULL;
}

void print(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}


int main(){
	node* head=NULL;
	node* tail=NULL;
    insertionAtFront(head,tail,3);
	insertionAtFront(head,tail,2);
	insertionAtFront(head,tail,1);
	insertionAtEnd(head,tail,4);
	insertionAtEnd(head,tail,5);
	insertionAtEnd(head,tail,6);
	insertionAtPos(head,tail,0,0);
	insertionAtPos(head,tail,7,7);
	insertionAtPos(head,tail,11,3);


	print(head);
	cout<<endl;

    deletionAtFront(head,tail);
	deletionAtEnd(head,tail);

	print(head);
	cout<<endl;

	deletionAtPos(head,tail,0);
	deletionAtPos(head,tail,8);
	deletionAtPos(head,tail,3);

	print(head);
	cout<<endl;

    int d;
	cin>>d;
	node* n=search(head,d);
	if(n)
	{
		cout<<"Data found : "<<n->data<<endl;
	}
	else
	{
		cout<<"Data Not found"<<endl;
	}

    return 0;
}