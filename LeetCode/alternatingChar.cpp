//https://www.hackerrank.com/challenges/alternating-characters/problem
#include <iostream>

int alternatingCharacters(std::string &s){
    int count = 0;
    for(auto i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]){
            count++;
            s.erase(i,1);
            i--;
        }
        std::cout << s << std::endl;
    }
    return count;
}

int main() {
    int q;
    std::cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        std::string s;
        std::cin >> s;
        int result = alternatingCharacters(s);
        std::cout << result << std::endl;
    }
    return 0;
}
