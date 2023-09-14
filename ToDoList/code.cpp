#include<iostream>
#include<string.h>
using namespace std;
struct Node{
	string task;
	int number;
	Node *next;
	Node *prev;
};



bool search(Node *head,int el){
	
	Node *ptr=head;
	int i=1;
	do{
		if(ptr->number==el){
			
			return true;
		}
		i++;
		ptr=ptr->next;
	}while(ptr!=head);
	cout<<"NO MATCH FOUND FOR THIS TASK NUMBER"<<endl;
	return false;
	
}


void insertT(Node *&head){
	
	
	Node *temp=new Node();
	Node *ptr=new Node();
		char first;
		cout<<endl;
	cout<<"ENTER A NEW TASK TO ADD UP IN YOUR TODO-LIST"<<endl;
	getline(cin>>ws,temp->task);

	if(head==NULL){
	
		temp->next=temp;
		temp->prev=temp;
		head=temp;
	head = temp;
		temp->number=1;
		
	}
	else{
		
	
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;
		
		temp->number=temp->prev->number +1;
		
	}
	

}
void markcomplete(Node *head)
{
	if(head==NULL)
	{
		cout<<"NO ENTRY IN LIST YET"<<endl;
	}
	else{
	
		int pos;
		string c;
		string complete="\tcompleted";
	cout<<"Enter the task number to mark it as completed";
	cin>>pos;
	
	if(search(head,pos))
	{
	
	Node *ptr=head;
	for(int i=2;i<=pos;i++){
		ptr=ptr->next;
	}
	
	c=ptr->task;
	ptr->task=c+complete;
}


}
}

void display(Node *head){
	cout<<endl;
	if(head==NULL){
		cout<<"THE LIST IS EMPTY"<<endl;
	}
	else{
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        cout<<"\t\t\t\tLIST:"<<endl<<endl;
		Node *ptr=head;
		cout<<ptr->number<<"->"; 
			cout<<ptr->task<<endl;
		while(ptr->next!=head){
			ptr=ptr->next;
			cout<<ptr->number<<"-> ";
			cout<<ptr->task<<endl;
			
			
	
	}
	cout<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
}

void renumber(Node *head){

	
	int count=2;
	Node *ptr=head;
	head->number=1;
	while(ptr->next!=head)
	{
		
		ptr=ptr->next;
		ptr->number=count;
		count++;
	
}
}
void deleteS(Node *&head){
	if(head==NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	Node* temp = head;
	if (head->next == head) {
        head = NULL;
    }
	else{
		Node *ptr=head;
		head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        renumber(head);
	}
	delete temp;
}

void deleteP(Node *head, int pos){
	if(search(head,pos)){
		
	
	
		Node *temp,*ptr=head;
	for(int i=2;i<pos;i++){
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	delete temp;
}

}







int main()
{
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t\t\tTO-DO LIST"<<endl<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	Node *head=new Node();
	
	head=NULL;
	
	char c;
	 
	do{
	
	int choice;
	cout<<"-> press 1 for insertion of new task"<<endl;
	cout<<"->pres 2 for dsiplaying tasks"<<endl;
	cout<<"->press 3 for deletion of task"<<endl;
	cout<<"->press 4 to mark any task as completed"<<endl;
	cout<<"->press anyother key to exit";
	cout<<endl<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			int x;
			cout<<"HOW MANY TASKS YOU WANT TO INSERT"<<endl;
			cin>>x;
			for(int i=0;i<x;i++)
			{
			
			insertT(head);
		}
			break;
		case 2:
			display(head);
			break;
		case 3:
			if(head==NULL)
			{
				cout<<"NO ENTRY ADDED YET"<<endl;
			}
			else{
				
			
			int pos;
			cout<<"ENTER POSITION";
			cin>>pos;
				if(pos==1){
					deleteS(head);
				}
				else{
					deleteP(head,pos);
					renumber(head);
				}
			}
				break;
				case 4:
					markcomplete(head);
					break;
				default:
					break;
	}
cout<<endl;
	cout<<"PRESS Y TO CONTINUE OR ANYOTHER KEY TO QUIT"<<endl;
	cin>>c;
	cout<<endl;
}
while(c=='Y'|| c=='y');
	
	

	
}
