#include <iostream>
#include <vector>

int getMoneySpent(std::vector <int> keyboards, 
    std::vector <int> drives, int s){
    
    int ans = -1;

    for(int i = 0; i < keyboards.size(); i++){
        for(int j = 0; j < drives.size(); j++){
            int sum = keyboards[i] + drives[j];
            if(sum <= s && sum > ans){
                ans = sum;
                std::cout << "\nAns = " << ans << std::endl;
            }
        }
    }

    return ans;
}

int main() {
    int s;
    int n;
    int m;
    
    std::cin >> s >> n >> m;
    
    std::vector<int> keyboards(n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++)
       std::cin >> keyboards[keyboards_i];
    
    std::vector<int> drives(m);
    for(int drives_i = 0; drives_i < m; drives_i++)
       std::cin >> drives[drives_i];
    
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    
    std::cout << moneySpent << std::endl;
    
    return 0;
}
