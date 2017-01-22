#include <iostream>
#include <map>

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
	bool checkCycle(){
		if(head == NULL || head->Next() == NULL)
			return false;
		Node *slow = head, *fast = head;
		while(fast && fast->Next()){
			slow = slow->Next();
			fast = fast->Next()->Next();
			if(slow == fast)
				return true;
		}
		return false;
	}

	bool checkCycleHashMap(){
		if(head == NULL || head->Next() == NULL)
			return false;
		std::map<Node *, bool> hash;
		Node *temp = head;
		while(temp != NULL){
			// If not found
			if(hash.find(temp) == hash.end()){
				hash[temp] = true;
				temp = temp->Next();
			}
			else 
				return false;
		}
		return true;
	}
};

int main(){

	LinkedList obj;

	obj.insert(4);
	obj.insert(1);
	obj.insert(9);
	obj.insert(7);
	obj.insert(-3);
	obj.insert(-7);

	obj.printList();

	if(!obj.checkCycle())
		std::cout << "No cycle in the linked list.\n";

	return 0;
}