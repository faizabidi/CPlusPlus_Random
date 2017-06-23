// https://www.hackerrank.com/challenges/counting-valleys

#include <vector>
#include <iostream>
#include <algorithm>

int valleys_count(std::vector<char> array){
	int prev = 0, curr = 0, ans = 0;

	for(int i = 0; i < array.size(); i++){
		prev = curr;
		if(array[i] == 'D')
			curr--;
		if(array[i] == 'U')
			curr++;
		if(curr == 0 && prev < 0)
			ans++;
	}

	return ans;
}

int main(){
	int n;
	std::cin >> n;

	std::vector<char> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	std::cout << valleys_count(array) << std::endl;

    return 0;
}
