// https://www.hackerrank.com/challenges/birthday-cake-candles

#include <iostream>
#include <vector>
#include <algorithm>

int calculate(std::vector<int> height){
	int ans = 0;
	int max_height = *std::max_element(height.begin(), height.end());
	for(int i = 0; i < height.size(); i++)
		if(height[i] == max_height)
			ans++;
	return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> height(n);
    for(int i = 0; i < n; i++)
       std::cin >> height[i];
    
    std::cout << calculate(height);
    return 0;
}