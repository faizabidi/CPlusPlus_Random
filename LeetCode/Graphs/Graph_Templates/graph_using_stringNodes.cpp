/*
We want to create a graph of node type strings.
We do not know the size of the graph before hand.
We also want to check if two nodes are connected to each other.
Finally, we define a method to remove a node from the graph.
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>

using namespace std;

class IdentityResolutionApi
{
    public:
    // Default constructor
    IdentityResolutionApi(){
        id = 0;
    }

    // Function to get an id for a corresponding string
    int stringToInt(string str){
        // Check if this string exists in the hashmap
        //cout << "str = " << str << endl;
        auto it = hashmap_of_string.find(str);
        if(it != hashmap_of_string.end())
            return hashmap_of_string[str];
        else{
            hashmap_of_string[str] = id;
            hashmap_of_id[id] = str;
            id++;
        }
        return hashmap_of_string[str];
    }

    // Add links in the graph
    void addLink(string id1, string id2){
        int id1_num = stringToInt(id1);
        int id2_num = stringToInt(id2);
        // Add to hashset
        uniqueNodes.insert(id1_num);
        uniqueNodes.insert(id2_num);
        // Resize on the adjacency list based on how many nodes exists in the uniqueNodes set
        adjList.resize(uniqueNodes.size());
        adjList[id1_num].push_back(id2_num);
        adjList[id2_num].push_back(id1_num);
    }

    // Print the graph
    void printGraph(){
        for(int i = 0; i < adjList.size(); i++){
            cout << hashmap_of_id[i] << ":";
            for(auto it = adjList[i].begin(); it != adjList[i].end(); it++)
                cout << hashmap_of_id[*it] << "->";
            cout << "NULL\n";
        }
    }

    // Check if two nodes are connected or not
    bool isLinked(string id1, string id2){
        int id1_num = stringToInt(id1);
        int id2_num = stringToInt(id2);
        // Apply BFS
        if(id1_num == id2_num)
            return true;
        vector<bool> visited(uniqueNodes.size(), false);
        queue<int> q;
        q.push(id1_num);
        visited[id1_num] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it = adjList[temp].begin(); it != adjList[temp].end(); 
                                                                    it++){
                // If found
                if(*it == id2_num)
                    return true;
                // Else, add to queue
                if(!visited[*it]){
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        return false;
    }
    
    // Remove a node from the graph
    void removeId(string id){
        int id_num = stringToInt(id);
        // Remove all edges from this node and to this node
        for(int i = 0; i < adjList.size(); i++){
            // If this is the node to be removed, empty its list
            if(i == id_num)
                adjList[i].clear();
            else{
                // Find it in the list and delete it
                auto it = find(adjList[i].begin(), adjList[i].end(), id_num);
                if(it != adjList[i].end())
                    adjList[i].erase(it);
            }
            
        }
    }

    private:
    vector<list<int>> adjList;
    // Keep a tab of unique ids with each string
    map<string, int> hashmap_of_string;
    // Keep a tab of what id corresponds to what string
    map<int, string> hashmap_of_id;
    // Id starts from 0
    int id;
    // Hashset to help define the size of the adjacency list as nodes come in
    set<int> uniqueNodes;
};

int main(){
    IdentityResolutionApi obj1;
    obj1.addLink("a", "b");
    obj1.addLink("b", "c");
    obj1.addLink("a", "d");
    obj1.addLink("e", "f");

    obj1.printGraph();

    cout << "\nChecking if node a and e are connected\n";
    if(obj1.isLinked("a", "e"))
        cout << "\na and e are connected\n";
    else
        cout << "\na and e are not connected\n";

    cout << "\nDeleting the node a.\n";
    obj1.removeId("a");
    obj1.printGraph();

    return 0;

}
