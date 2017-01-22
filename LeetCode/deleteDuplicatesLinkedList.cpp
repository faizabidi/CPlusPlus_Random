// https://www.hackerrank.com/challenges/30-linked-list-deletion

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;	
class Node
{
public:
	int data;
	Node *next;
	Node(int d){
		data=d;
		next=NULL;
	}
};
class Solution{
public:
	// Without using a hash table
	/*Node* removeDuplicates(Node *head)
	{
		if(!head)
			return NULL;
		Node *prev = head;
		Node *curr = head->next;
		std::vector<int> bucket;
		bucket.push_back(prev->data);
		while(curr){
            // If value present in bucket
			if(std::find(bucket.begin(), bucket.end(), curr->data) != bucket.end()){
				prev->next = curr->next;
				Node *temp = curr;
				curr = curr->next;
				delete temp;
			}
			else{
				bucket.push_back(curr->data);
				prev = curr;
				Node *temp = curr;
				curr = curr->next;
				//delete temp;
			}
		}
		return head;
	}*/
	// Using a hash table
	Node* removeDuplicates(Node *head)
	{
		if(!head)
			return NULL;
		std::map<int, bool> hash;
		Node *prev = head;
	// Put head in hashmap
		hash[prev->data] = true;
		Node *curr = prev->next;
		while(curr){
        // If character doesn't exists in hashmap
			if(hash.find(curr->data) == hash.end()){
				hash[curr->data] = true;
				prev = curr;
				curr = curr->next;
			}
			else{
				prev->next = curr->next;
				Node *temp = curr;
				curr = curr->next;
				delete temp;
			}
		}
		return head;
	}
	Node* insert(Node *head,int data)
	{
		Node* p=new Node(data);
		if(head==NULL){
			head=p;  

		}
		else if(head->next==NULL){
			head->next=p;

		}
		else{
			Node *start=head;
			while(start->next!=NULL){
				start=start->next;
			}
			start->next=p;   

		}
		return head;


	}
	void display(Node *head)
	{
		Node *start=head;
		while(start)
		{
			cout<<start->data<<" ";
			start=start->next;
		}
	}
};

	int main()
	{
		Node* head=NULL;
		Solution mylist;
		int T,data;
		cin>>T;
		while(T-->0){
			cin>>data;
			head=mylist.insert(head,data);
		}	
		head=mylist.removeDuplicates(head);

		mylist.display(head);

	}