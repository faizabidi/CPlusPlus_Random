// https://leetcode.com/problems/target-sum/?tab=Description

#include <iostream>
#include <vector>

// Without dynamic programming
// Recursive solution
// Refer: http://www.liuchuo.net/archives/3098
void findTargetSumWays_dfs(int sum, int count, std::vector<int> array, int target, int &result){
	// We need to increase answer count only when we have checked all the
	// elements in the array
	if(count == array.size()){
		if(sum == target)
			result++;
		return;
	}
	findTargetSumWays_dfs(sum + array[count], count + 1, array, target, result);
	findTargetSumWays_dfs(sum - array[count], count + 1, array, target, result);
}

int findTargetSumWays(std::vector<int> array, int target){
	int answer = 0;
	findTargetSumWays_dfs(0, 0, array, target, answer);
	return answer;
}



int main(){
	int n;
	std::cout << "Number of elements in the array:";
	std::cin >> n;
	
	std::vector<int> array(n);
	std::cout << "Enter the array\n";
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	int target;
	std::cout << "Enter target sum:";
	std::cin >> target;

	std::cout << "Number of ways = " << findTargetSumWays(array, target);
	std::cout << std::endl;

	return 0;
}