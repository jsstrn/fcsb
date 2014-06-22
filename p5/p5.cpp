#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

/* * * * * Function Declarations * * * * */

/* Q1 — Find the length of a list  */
int listLength(Node*);

/* Q2 — Add a new node at the head of a list */
void listAddFront(Node* &, Node*);

/* Q3 — Find a node in a list */
Node* listFind(Node*, int);

/* Q4 — Add a new node at the tail of a list  */
void listAddBack(Node* &, Node*);

/* Q5 — Delete a node from a list */
Node* listDelete(Node* &, int);

/* Creates nodes in a list */
Node* listCreate(int);

/* Displays each node in a list */
void listDisplay(Node*);

/* * * * * * * Main Function * * * * * * */

int main()
{
	Node* firstNode = listCreate(0);   //To test building an empty list
	listDisplay(firstNode);

	/* Q1 — Find the length of a list  */
	int length = listLength(firstNode);
	cout << "There are " << length << " nodes in this list." << endl;
	cout << endl;
	
	/* Q2 — Add a new node at the head of a list */
	int input=0;
	Node* frontNode = new Node();
	cout << "Enter a value to add to the front of the list:" << endl;
	cin >> input;
	frontNode->data = input;
	frontNode->next = NULL;
	listAddFront(firstNode, frontNode);
	listDisplay(firstNode);
	
	// Check the length of list again after creating 1 value to list
	length = listLength(firstNode);
	cout << "There are " << length << " nodes in this list." << endl;
	cout << endl;


	/* Q3 — Find a node in a list */
	cout << "Enter search value to search in link list:" << endl;
	cin >> input;
	Node* findNode = listFind(firstNode, input);
	if(findNode!=NULL) cout << "Node "<< findNode->data << " is found!" << endl;
	else cout << "Node is not found!" << endl;


	/* Q4 — Add a new node at the tail of a list  */
	Node* backNode = new Node();
	cout << "Enter a value to add to the back of the link list:" << endl;
	cin >> input;
	backNode->data = input;
	backNode->next = NULL;
	listAddBack(firstNode, backNode);
	listDisplay(firstNode);

	/* Q5 — Delete a node from a list */
	cout << "Enter a value to delete from link list:" << endl;
	cin >> input;
	Node* deleteNode =listDelete(firstNode, input);
	if(deleteNode!=NULL) cout << "Node "<< deleteNode->data << " is found and deleted!" << endl;
	else cout << "Node is not in the list!" << endl;
	listDisplay(firstNode);

	delete firstNode;
	return 0;
}

/* * * * * Function Definitions * * * * */

/* Q1 — Find the length of a list  */
int listLength(Node* firstNode) {
	Node* currentNode = firstNode;
	int count = 0;
	if (currentNode == NULL) return count; // empty list
	while (currentNode != NULL) {
		count++;
		currentNode = currentNode->next;
	}
	return count;
}

/* Q2 — Add a new node at the head of a list */
void listAddFront(Node* &firstNode, Node* newNode) {
	newNode->next = firstNode;
	firstNode = newNode;
}

/* Q3 — Find a node in a list */
Node* listFind(Node* firstNode, int value) {
	Node* currentNode = firstNode;
	while (currentNode != NULL) {
		if (currentNode->data == value) {
			//currentNode->next = NULL;        //this is the culprit
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

/* Q4 — Add a new node at the tail of a list  */
void listAddBack(Node* &firstNode, Node* newNode) {
	Node* currentNode = firstNode;
	while (currentNode != NULL) {
		if (currentNode->next == NULL) {
			currentNode->next = newNode;
			newNode->next = NULL;
		}
		currentNode = currentNode->next;
	}
}

/* Q5 — Delete a node from a list */
Node* listDelete(Node* &firstNode, int value) {
	Node* currentNode = firstNode;
	Node* previousNode = firstNode;
	while (currentNode != NULL) {
		if (currentNode->data == value) {
			if (currentNode == firstNode) {
				delete firstNode;
				firstNode = firstNode->next;
			} else {
				previousNode->next = currentNode->next;
			}
			currentNode->next = NULL;
			return currentNode;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	return NULL; // value not found
}

/* Creates a predefined number of nodes in a list */
Node* listCreate(int size) {
	Node* newNode = NULL;
	for (int i = size - 1; i >= 0; --i) {
		Node* tmpNode = new Node();
		tmpNode->data = i;
		tmpNode->next = newNode;
		newNode = tmpNode;
	}
	return newNode;
}

/* Displays each node in a list */
void listDisplay(Node* firstNode) {
	Node* currentNode = firstNode;
	if (currentNode == NULL) cout << "List is empty!";
	while (currentNode != NULL) {
		cout << currentNode->data;
		if (currentNode->next != NULL) cout << " -> ";
		currentNode = currentNode->next;
		
	}
	cout << endl;
}