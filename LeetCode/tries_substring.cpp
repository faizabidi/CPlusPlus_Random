// https://www.hackerrank.com/challenges/ctci-contacts?h_r=next-challenge&h_v=zen

#include <iostream>
#include <map>
#include <vector>

// nxn solution
void check(std::vector<std::string> &adds, std::vector<std::string> &finds){
    std::vector<std::string>::iterator itr;
    for(itr = finds.begin(); itr != finds.end(); itr++){
        int sum = 0;
        std::vector<std::string>::iterator itr2;
        for(itr2 = adds.begin(); itr2 != adds.end(); itr2++){
            if((*itr2).find(*itr) != std::string::npos)
                sum++;
        }
        std::cout << sum << std::endl;
    }
}

void check2(std::map<std::string, int> &hash_adds, std::vector<std::string> &finds){
    std::vector<std::string>::iterator itr;
    for(itr = finds.begin(); itr != finds.end(); itr++){
        if()
    }
}   

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> adds;
    std::vector<std::string> finds;

    std::map<std::string, int> hash;
    //std::map<std::string, int> hash_finds;

    for(int i = 0; i < n; i++){
        std::string op;
        std::string contact;
        std::cin >> op >> contact;
        if(op == "add"){
            // Create all possible substrings, and store in hashmap
            
        	adds.push_back(contact);
            hash_adds[contact]++;
        }
        else if(op == "find")
            finds.push_back(contact);
    }

    check2(hash_adds, finds);

    return 0;
}
