#include <iostream>
#include <vector>

void StairCase(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			std::cout << " ";
		}
		for(int k = 1; k <= i + 1; k++)
			std::cout << "#";
		std::cout << std::endl;
	}
}

int sum(std::vector<int> numbers){
    int n = numbers[0];
    int sum = 0;
    for(int i = 1; i < n; i++)
    	sum = sum + numbers[i];
    return sum;
}

int main(){
	int n;
	std::cin >> n;
	StairCase(n);
	std::cout << std::endl;
}