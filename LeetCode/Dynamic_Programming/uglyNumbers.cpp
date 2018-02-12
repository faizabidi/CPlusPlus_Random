// https://www.geeksforgeeks.org/ugly-numbers/

#include <iostream>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
// Brute force
// O(nxn) time && O(1) space
// Ugly is a number who's only prime factors are 2, 3, and 5
bool check_uglyNumber(int n){
    if(n == 0)
        return false;
    // Keep dividing by 2, 3, and 5. If you get 1 at the end, the number is ugly
    while(n % 2 == 0){
        n = n / 2;
    }
    while(n % 3 == 0){
        n = n / 3;
    }
    while(n % 5 == 0){
        n = n / 5;
    }
    if(n == 1)
        return true;
    return false;
}

int uglyNumber1(int n){
    int count = 0;
    int ugly = 0;
    while(count < n){
        if(check_uglyNumber(ugly))
            count++;
        if(count == n)
            break;
        ugly++;
    }
    return ugly; 
}
///////////////////////////////////////////////////////////////////////////////
// DP solution
// O(n) time and O(n) space
// https://leetcode.com/problems/ugly-number-ii/description/
int uglyNumber(int n){
    if(n <= 0)
        return 0;
    std::vector<int> ans;
    ans.push_back(1);
    int a = 0, b = 0, c = 0;
    for(int i = 1; i < n; i++){
        ans.push_back(std::min(ans[a] * 2, 
            std::min(ans[b] * 3, ans[c] * 5)));
        if(ans[i] == ans[a] * 2)
            a++;
        if(ans[i] == ans[b] * 3)
            b++;
        if(ans[i] == ans[c] * 5)
            c++;
    }
    return ans.back();
}
///////////////////////////////////////////////////////////////////////////////
int main(){
    int n;
    std::cin >> n;
    std::cout << uglyNumber(n) << std::endl;

    return 0;
}
