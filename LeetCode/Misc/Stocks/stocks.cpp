// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

class Solution{
public:
    // n x n solution
    int maxProfit_n2(std::vector<int> &prices){
        size_t length = prices.size() - 1;
        int max = 0;

        for(int i = length; i >= 0; i--){
        	for(int j = i - 1; j >=0; j--){
        		int diff = prices[i] - prices[j];
        		if(diff > max)
        			max = diff;
        	}
        }
        return max;
    }

    // Better solution
    int maxProfit_n1(std::vector<int> &prices){
        size_t length = prices.size();
        int max = 0;
        int min = INT_MAX;
        for(int i = 0; i < length; i++){
        	// Find the minimum price
        	if(prices[i] < min)
        		min = prices[i];
        	if(prices[i] - min > max)
        		max = prices[i] - min;
        }
        return max;
    }

    // Another optimized solution
    // REF: https://helloacm.com/cc-coding-exercise-best-time-to-buy-and-sell-stock/
    int maxProfit_n2(std::vector<int> &prices){
        int ans = 0;
        int tempProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            tempProfit += prices[i] - prices[i - 1];
            if(tempProfit < 0)
                tempProfit = 0;
            if(tempProfit > ans)
                ans = tempProfit;
        }
        return ans;
    }
};

int main(){
	int num;
	std::vector<int> array;
	Solution obj1;

	std::cout << "Enter array of stock prices (x to stop):";
	while(!std::cin.fail()){
		std::cin >> num;
		array.push_back(num);
	}

	std::cout << obj1.maxProfit_n1(array);

	return 0;
}