// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include <iostream>

using namespace std;

// O(n*n!) time 
void permute(string str, int index){
    if(index == str.size()){
        cout << str << endl;
        return;
    }
    // Swapping
    for(int i = index; i < str.size(); i++){
        swap(str[i], str[index]);
        permute(str, index+1);
    }
}

int main(){
    string str = "abc";
    permute(str, 0);

    return 0;
}
