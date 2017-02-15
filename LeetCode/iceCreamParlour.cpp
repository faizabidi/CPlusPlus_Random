// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor

#include <iostream>
#include <vector>
#include <map>

// O(nxn) solution
/*std::vector<int> cost(int money, int flavours, std::vector<int> cost_icecreams){
    std::vector<int> result;
    for(int i = 0; i < cost_icecreams.size(); i++){
        int num_to_find = money - cost_icecreams[i];
        for(int j = i + 1; j < cost_icecreams.size(); j++){
            if(cost_icecreams[j] == num_to_find){
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
    }
    return result;
}*/

// O(n) solution
std::vector<int> cost2(int money, int flavours, std::vector<int> cost_icecreams){//, std::map<int, int> hashmap){
    std::map<int, int> hashmap;
    std::vector<int> result;
    
    for(int i = 0; i < cost_icecreams.size(); i++){
        int sum_needed = money - cost_icecreams[i];
        // If not in hashmap, add it
        if(hashmap.find(sum_needed) == hashmap.end()){
            std::cout << sum_needed << std::endl;
            hashmap[cost_icecreams[i]] = i;
        }
        // If in hashmap
        else{
            result.push_back(hashmap[sum_needed] + 1); 
            result.push_back(i + 1);
        }
    }
    return result;
}
int main(){
    int trips;

    std::cout << "Enter number of trips:";
    std::cin >> trips;

    for(int i = 0; i < trips; i++){
        int money;
        int flavours;
        std::vector<int> cost_icecreams;
        std::vector<int> ans;
        std::map<int, int> hashmap;
        
        std::cout << "Enter money available:";
        std::cin >> money;

        std::cout << "Enter number of flavours:";
        std::cin >> flavours;

        std::cout << "Enter the cost of ice-creams:";
        for(int i = 0; i < flavours; i++){
            int cost;
            std::cin >> cost;
            cost_icecreams.push_back(cost);
        }

        //ans = cost(money, flavours, cost_icecreams);
        ans = cost2(money, flavours, cost_icecreams);//, hashmap);

        std::vector<int>::iterator it;
        for(it = ans.begin(); it != ans.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}