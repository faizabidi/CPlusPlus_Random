#include <iostream>

struct Node{
	int data;
	Node *next;
};

Node *createNode(int value){
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertNode(Node *&head, int value){
	if(!head){
		head = createNode(value);
		return;
	}
	else{
		Node *temp = head;
		while(temp->next)
			temp = temp->next;
		Node *newNode = createNode(value);
		temp->next = newNode;
	}
}

void printList(Node *head){
	Node *temp = head;
	while(head){
		std::cout << head->data << "->";
		head = head->next;
	}
	std::cout << "NULL\n";
}
	
void deleteNode(Node *&head, int position){
	Node *temp = head;
	// Go to that position
	int i = 1;
	while(i < position){
		temp = temp->next;
		i++;
	}
	// If it's the head node
	if(i == 1){
		temp = temp->next;
		head = temp;
		return;
	}
	// If it's ant other node
	// Go to one node before the node to be delete and point its next piointer to the next pointer of the node to be delete.
	Node *temp1 = head;
	while(temp1->next != temp)
		temp1 = temp1->next;
	temp1->next = temp->next;
	delete temp;
	return;
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
	// Delete the node in 1st position
	deleteNode(head, 1); // Ans = 2->3->4->5->6->7->NULL
	printList(head);
	deleteNode(head, 6); // Ans = 2->3->4->5->6->NULL
	printList(head);
	deleteNode(head, 2);
	printList(head); // Ans = 2->4->5->6->NULL

	return 0;
}
