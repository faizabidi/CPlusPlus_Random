#include <iostream>
#include <vector>
using namespace std;

void printAllSubsequences(string str1, string temp, int index){
    if(index == str1.size()){
        cout << temp << endl;
        return;
    }

    // Include it
    string temp2 = temp + str1[index];
    //cout << temp2 << endl;
    //return;
    printAllSubsequences(str1, temp2, index+1);
    // Exclude it
    printAllSubsequences(str1, temp, index+1);

}


int main(){
    string str1 = "ABC";
    printAllSubsequences(str1, "", 0);

    return 0;
}