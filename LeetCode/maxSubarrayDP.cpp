// https://leetcode.com/problems/maximum-subarray/?tab=Description

#include <iostream>
#include <vector>

// O(nxn)
int maxSubArray(std::vector<int> array){
	if(array.size()  == 0){
		std::cout << "Nothing in array\n";
		return 0;
	}
	
	if(array.size()  == 1){
		std::cout << "Only 1 element in array\n";
	    return array[0];
	}

	int sum = INT_MIN;

	std::vector<int> temp;
	temp.push_back(array[0]);
	
	for(int i = 0; i < array.size(); i++){
		std::vector<int> temp;
		int tempSum = array[i];
		//std::cout << "Temp sum = " << tempSum << std::endl;
		temp.push_back(array[i]);
		for(int j = i + 1; j < array.size(); j++){
			temp.push_back(temp.back() + array[j]);
			//std::cout << "New temp sum = " << temp.back() << std::endl;
			if(tempSum < temp.back())
				tempSum = temp.back();
		}
		//std::cout << "Sum = " << sum << std::endl;
		if(tempSum > sum)
			sum = tempSum;
	}
	return sum;
}

// O(n)
int maxSubArray2(std::vector<int> array){
	int ans = INT_MIN;
	int max = 0;
	for(int i = 0; i < array.size(); i++){
		max += array[i];
		if(max > ans)
			ans = max;
		if(max < 0)
			max = 0;
		std::cout << "Max is " << ans << std::endl;
	}
	return ans;
}

// Using dynamic programming
int maxSubArray3(std::vector<int> array){
	if(array.size() == 1)
		return array[0];
	std::vector<int> dp_array;
	dp_array.push_back(array[0]);
	int sum = dp_array[0];
	for(int i = 1; i < array.size(); i++){
		dp_array.push_back(std::max(dp_array[i - 1] + array[i], array[i]));
		sum = std::max(sum, dp_array[i]);
	}
	return sum;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> array(n);

	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	std::cout << maxSubArray3(array);

	return 0;
}