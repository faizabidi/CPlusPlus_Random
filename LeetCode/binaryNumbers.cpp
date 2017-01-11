// https://www.hackerrank.com/challenges/30-binary-numbers
#include <iostream>
#include <algorithm>
#include <map>

int countConsecutiveOnes(int n){
	std::string binaryNumber;
	int max = 0, count = 0;
	while(n > 0){
		int remainder = n % 2;
		n = n / 2;
		if(remainder == 1){
			count++;
			if(count > max)
				max = count;
		}
		else
			count = 0;
	}	
	return count;
}

int main(){
	int n;
	std::cout << "Enter a number:";
	std::cin >> n;
	std::cout << "The number of consecutive binary ones is:" << countConsecutiveOnes(n);
	std::cout << std::endl;
}