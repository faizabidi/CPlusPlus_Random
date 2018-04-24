#include <iostream>

struct Node{
	int data;
	Node *next;
};

// Create a node
Node *createNode(int value){
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

// Insert a node at the end
void insertNode(Node *&head, int value){
	if(head == NULL){
		head = createNode(value);
		return;
	}
	else{
		Node *temp = head;
		// Go to the end of the linked list
		while(temp->next != NULL)
			temp = temp->next;
		Node *newNode = createNode(value);
		temp->next = newNode;
	}
}

void printList(Node *head){
	Node *temp = head;
	while(temp){
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "NULL\n";
}

int main(){
	Node *head = NULL;
	insertNode(head, 1);
	insertNode(head, 2);
	insertNode(head, 3);
	insertNode(head, 4);
	insertNode(head, 5);
	insertNode(head, 6);
	insertNode(head, 7);
	printList(head); // Ans = 1->2->3->4->5->6->7->NULL

	return 0;
}
