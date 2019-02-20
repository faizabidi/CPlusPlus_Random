#include <iostream>
#include <vector>
using namespace std;

// O(2^n) time
void printAllSubsequences(string str1, string temp, int index){
    if(index == str1.size()){
        cout << temp << endl;
        return;
    }

    // Include it
    printAllSubsequences(str1, temp+str1[index], index+1);
    // Exclude it
    printAllSubsequences(str1, temp, index+1);
}

int main(){
    string str1 = "ABC";
    printAllSubsequences(str1, "", 0);

    return 0;
}