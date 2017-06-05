// https://www.hackerrank.com/challenges/big-sorting

#include <iostream>
#include <vector>

using namespace std;

bool compare(std::string a, std::string b){
    // If size is same
    if(a.size() == b.size())
        return a < b;
    // If size is not same
    else
        return a.size() < b.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    
    std::sort(unsorted.begin(), unsorted.end(), compare);

    for(int i = 0; i < unsorted.size(); i++)
        std::cout << unsorted[i] << std::endl;

    return 0;
}
