#include <iostream>

class Node{
	int data;
	Node *next;
public:
	Node(int d){
		data = d;
		next = NULL;
	}
	void setNext(Node *newNode_next){
		next = newNode_next;
	}
	int Data(){
		return data;
	}
	Node *Next(){
		return next;
	}
};

class LinkedList{
	Node *head;
public:
	LinkedList(){
		head = NULL;
	}
	void insert(int value){
		Node *newNode = new Node(value);
		if(head == NULL)
			head = newNode;
		else{
			// Go to the end of the list
			Node *tmp = head;
			while(tmp->Next() != NULL)
				tmp = tmp->Next();
			tmp->setNext(newNode);
		}
	}
	void printList(){
		if(head == NULL)
			return;
		Node *temp = head;
		while(temp != NULL){
			std::cout << temp->Data() << "-->";
			temp = temp->Next();
		}
		std::cout << "NULL\n";
	}
	void reverseList(Node* &firstNode){
		// If 0 or 1 items
		if(firstNode == NULL || firstNode->Next() == NULL)
			return;
		Node *rest = firstNode->Next();
		reverseList(rest);
		firstNode->Next()->setNext(firstNode);
		firstNode->setNext(NULL);
		firstNode = rest;
	}
	void printRevList(){
		reverseList(head);
		printList();
	}
};

int main(){

	LinkedList obj;

	obj.insert(4);
	obj.insert(1);
	obj.insert(9);
	obj.insert(7);
	obj.insert(-3);

	obj.printList();

	obj.printRevList();

	return 0;
}