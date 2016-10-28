#include <iostream>

class LinkedList{

private:
	struct node{
		int data;
		node *next;
	}*head;

public:
	LinkedList():head(NULL){};
	
	node *CreateNode(int data){
		node *newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

    void PrintList(){
		if(head == NULL)
			return;

		node *temp = head;
		while (temp != NULL){
			std::cout << temp->data << "-->";
			temp = temp->next;
		}

		std::cout << "NULL";
	}

	void AddNode(int data){
		if(head == NULL){
			head = CreateNode(data);
			return;
		}

		node *newNode = CreateNode(data);
		node *temp = head;

		while(temp->next != NULL)
			temp = temp->next;
		
		temp->next = newNode;
	}

	void Partition(int value){
		if(head == NULL)
			return;

		// Go to the end of the list
		node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;

        // Go to the position of the pivot
        node *pivot = head;
        while(pivot->next != NULL){
            if(pivot->data == value)
                break;
            else
                pivot = pivot->next;
        }

     	// Swap the last element with the pivot
        std::swap(pivot->data, temp->data);

        node *i = head;
        node *j = head;

        while(j->next != NULL){
            if(j->data <= temp->data){
                std::swap(j->data, i->data);
                i = i->next;
            }
            j = j->next;
        }

        // Swap the pivot to its correct location
        std::swap(i->data, temp->data);
	}
};

int main()
{	
	LinkedList obj1;
	int pivot;

	obj1.AddNode(5);
	obj1.AddNode(8);
	obj1.AddNode(1);
	obj1.AddNode(0);
	obj1.AddNode(3);
	obj1.AddNode(6);
	obj1.AddNode(1);
	obj1.AddNode(789);
	obj1.AddNode(54);
	obj1.AddNode(-78);

	obj1.PrintList();
    std::cout << std::endl;

	std::cout << "Enter pivot:";
    std::cin >> pivot;

	obj1.Partition(pivot);
	obj1.PrintList();
	std::cout << std::endl;

	return 0;
}