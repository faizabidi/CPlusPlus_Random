// https://www.hackerrank.com/challenges/sock-merchant

#include <iostream>
#include <vector>
#include <map>

void printMap(std::map<int, int> map){
    std::map<int, int>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ":" << it->second << std::endl;
}

int sockMerchant(int n, std::vector<int> array){
    std::map<int, int> map;
    int ans = 0;

    for(int i = 0; i < array.size(); i++)
        map[array[i]]++;
    
    std::map<int, int>::iterator it;

    for(it = map.begin(); it != map.end(); it++){
        int value = it->second;
        if(value >= 2){
            while(value >= 2){
                ans++;
                value -= 2;
            }
            std::cout << "Ans = " << ans << std::endl;
        }
    }

    printMap(map);

    return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> ar(n);

    for(int ar_i = 0; ar_i < n; ar_i++)
       std::cin >> ar[ar_i];
    
    int result = sockMerchant(n, ar);
    
    std::cout << result << std::endl;

    return 0;
}
