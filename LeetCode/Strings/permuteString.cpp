#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Print all permutations
// O(n^2*n!) time
// Source: https://www.geeksforgeeks.org/time-complexity-permutations-string/
void permutations(string str, int index){
    if(index == str.size()){
        cout << str << endl;
        return;
    }
    for(int i = index; i < str.size(); i++){
        // Swap elements
        swap(str[i], str[index]);
        permutations(str, index+1);
        // Swap back for backtracking
        swap(str[i], str[index]);
    }
}

int main(){
    string str = "ABC";
    permutations(str, 0);
    return 0;
}
