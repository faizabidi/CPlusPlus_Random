#include <iostream>
#include <map>
#include <vector>

bool ransom_note(std::vector<std::string> magazine, 
                    std::vector<std::string> ransom){
    
    std::map<std::string, int> hash;
    
    for(int i = 0; i < magazine.size(); i++)
        hash[magazine[i]]++;
    
    for(int i = 0; i < ransom.size(); i++){
        hash[ransom[i]]--;
        if(hash[ransom[i]] < 0)
            return false;
    }
    return true;
}

int main(){
    int m;
    int n;
    std::cin >> m >> n;
    std::vector<std::string> magazine(m);
    for(int i = 0; i < m; i++)
       std::cin >> magazine[i];

    std::vector<std::string> ransom(n);
    for(int i = 0; i < n; i++)
       std::cin >> ransom[i];
    
    if(ransom_note(magazine, ransom))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}
