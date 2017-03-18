// https://www.hackerrank.com/challenges/a-very-big-sum

#include <iostream>
#include <vector>

long long calculate(std::vector<long long> array){
	long long ans = 0;
	for(int i = 0; i < array.size(); i++)
		ans = ans + array[i];
	return ans;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<long long> arr(n);

	for(int i = 0; i < n; i++)
	   std::cin >> arr[i];
	
	long long ans = calculate(arr);

	std::cout << ans << std::endl;
	return 0;
}
