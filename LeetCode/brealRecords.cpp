//https://www.hackerrank.com/challenges/breaking-best-and-worst-records

#include <iostream>
#include <vector>

using namespace std;

vector <int> getRecord(vector < int > s){
    vector<int> ans;
    
    if(s.size() < 2)
        return ans;
    
    int largest = s[0];
    int smallest = s[0];
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 1; i < s.size(); i++){
        if(s[i] > largest){
            count1++;
            largest = s[i];
        }
        else if(s[i] < smallest){
            count2++;
            smallest = s[i];
        }
    }
    ans.push_back(count1);
    ans.push_back(count2);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
