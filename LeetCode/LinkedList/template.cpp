#include <iostream>

class LinkedList{
	struct node{
		int data;
		node *next;
	}*head;
	node *createNode(int val){
		node *newNode = new node;
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
	}
	void reverse_recursion_private(node *temp, node *prev){
		// Base condition
		if(!temp)
			return;
		
		node *next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
		head = prev;
		reverse_recursion_private(temp, prev);
	}
public:
	LinkedList(){
		head = NULL;
	}
	void insert(int val){
		if(!head){
			head = createNode(val);
			return;
		}
		node *newNode = createNode(val);
		// Go to the end
		node *temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = newNode;
	}
	void print(){
		node *temp = head;
		while(temp){
			std::cout << temp->data << "-->";
			temp = temp->next;
		}
		std::cout << "NULL\n";
	}
	void reverse(){
		node *temp = head;
		if(!temp)
			return;
		node *prev = NULL;
		node *curr = temp;
		while(curr){
			node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	void reverse_recursion(){
		node *temp = head;
		node *prev = NULL;
		reverse_recursion_private(temp, prev);
	}
};

int main(){

	LinkedList obj;

	obj.insert(4);
	obj.insert(1);
	//obj.insert(9);
	//obj.insert(7);
	//obj.insert(-3);
	obj.print();

	obj.reverse();
	obj.print();

	obj.reverse_recursion();
	obj.print();

	return 0;
}