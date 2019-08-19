#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Priority queue

Push and pop: log(n) time 
Building it: O(n) time - Floyd's algorithm
Insert: O(log(n)) time
Deletion: O(n * log(n)) time
*/


template <class T>
void printQ(T q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

template <class T>
void printPQ(T pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    vector<int> array = {-5,1,67,7,0,10};
    queue<int> q;
    // If in ascending order - minHeap
    //priority_queue<int, vector<int>, greater<int>> pq;
    // If in descending order - maxHeap
    priority_queue<int> pq;

    for(int i = 0; i < array.size(); i++){
        q.push(array[i]);
        pq.push(array[i]);
    }

    printQ(q);
    printPQ(pq);
    return 0;
}
