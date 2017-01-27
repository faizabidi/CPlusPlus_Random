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

std::vector<std::string> getPermutation(std::string &str){
    std::vector<std::string> permutations;
    do{
        permutations.push_back(str);
    }while(std::next_permutation(str.begin(),str.end()));
    return permutations;
}

std::vector<std::string> checkDivisibility(std::vector<std::string> arr){
    std::vector<std::string> result;
    for(int i = 0; i < arr.size(); i++){
        std::vector<std::string> values = getPermutation(arr[i]);
        int flag = 0;
        for(int j = 0; j < values.size(); j++){
            if(std::stoi(values[j]) % 8 == 0)
               flag = 1;
        }
        if(flag == 1)
            result.push_back("YES");
        else
            result.push_back("NO");
    }
    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;
    
    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _arr;
    string _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        getline(cin, _arr_item);
        _arr.push_back(_arr_item);
    }
    
    res = checkDivisibility(_arr);
    for(int res_i=0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
