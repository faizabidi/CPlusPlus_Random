#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findMutationDistance(string start, string end, vector <string> bank){
    // EDGE CASE 1 - WHEN START AND END ARE SAME
    if(start == end)
        return 0;

    // EDGE CASE 2 - IF THERE IS NO END IN THE BANK and START != END
    if(std::find(bank.begin(), bank.end(), end) == bank.end())
        return -1;

    // EDGE CASE 3 - IF BANK IS EMPTY
    if(bank.size() == 0)
        return -1;

    // Store all bank in a hashmap. This will make lookups faster
    std::map<string, bool> map;
    for(int i = 0; i < bank.size(); i++)
        map[bank[i]] = true;

    std::map<string, int> distance;
    distance[start] = 0;

    std::queue<std::string> q;
    q.push(start);
    
    std::map<std::string, bool> visited;
    
    // Mark first string as visited
    visited[start] = true;
    
    while(!q.empty()){
        std::string temp = q.front();
        q.pop();
        if(temp == end)
            return distance[temp];
        //std::cout << "Temp is " << temp << endl;
        for(int i = 0; i < temp.size(); i++){
            // Find where temp and END differ and see if that exists in the bank
            std::string potentialMatch = temp;
            //std::cout << "Temp is " << temp << endl;
            // Check for all A, C, G T on this position
            std::vector<char> lables = {'A', 'C', 'G', 'T'};
            for(int j = 0; j < lables.size(); j++){
                if(potentialMatch[i] != lables[j]){
                    potentialMatch[i] = lables[j];
                    // If found, add it to the queue
                    if(map[potentialMatch] && !visited[potentialMatch]){
                        distance[potentialMatch] = distance[temp] + 1;
                        q.push(potentialMatch);
                        visited[potentialMatch] = true;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _start;
    getline(cin, _start);
    
    string _end;
    getline(cin, _end);
    
    int _bank_size = 0;
    cin >> _bank_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _bank;
    string _bank_item;
    for(int _bank_i=0; _bank_i<_bank_size; _bank_i++) {
        getline(cin, _bank_item);
        _bank.push_back(_bank_item);
    }
    
    /*bool flag = check("AA", "BB");
    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";*/

    res = findMutationDistance(_start, _end, _bank);
    cout << res << endl;
    
    //fout.close();
    return 0;
}