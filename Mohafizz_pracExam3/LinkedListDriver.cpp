#include "node.h"
#include <iostream>
#include <string>
using namespace std;

node * nodeNew(int value, node * next){
node * n = new node;
n->value = value;
n->next = next;
return n; 
}

void listPrint(const node* p)
{
    while( p!= 0 ){
      cout << p->value << " ";
      p = p->next;
   }
   cout << endl;
}

//Implement your code here and return the updated linked list.  
node* newHead(node * head){

	int largest=0;
	node* cur = head;
	node* prev = NULL;

	if(head==NULL)
	{
		cout << "Empty list!" << endl;
	}
	else 
	{
		//Traverse list to find the biggest node
		while(cur!=NULL)
		{
			if(cur->value > largest)
			{
				largest = cur->value;
			}
			// update traversal node
			cur = cur->next;
		}
		cur = head;
		//Traverse list to insert in the correct place
		while(cur!=NULL)
		{
			if(cur->value >= largest)
			{
				break;
			}
			else 
			{
				prev = cur;
				cur = cur->next;
			}
		}
        //insert at the front(not empty)
		if(cur == head)
		{
			return head;
		}
		//insert beyong the front(not empty)
		else
		{
			prev->next = cur->next;
            cur->next = head;
            head = cur;
		}

		
	}
	return head;
}

int main(){
 node * head = 0;
 head = nodeNew(10, head);
 head = nodeNew(20, head);
 head = nodeNew(30, head);
 head = nodeNew(23, head);
 listPrint(head);
 listPrint(newHead(head));
}