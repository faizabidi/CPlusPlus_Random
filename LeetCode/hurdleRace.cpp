// https://www.hackerrank.com/challenges/the-hurdle-race

#include <iostream>
#include <algorithm>
#include <vector>

int hurdleRace(std::vector<int> array, int k){
	int max = *std::max_element(array.begin(), array.end());
	return k >= max ? 0 : max - k;
}

int main(){
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++)
       std::cin >> height[height_i];
    
    std::cout << hurdleRace(height, k);

    return 0;
}
