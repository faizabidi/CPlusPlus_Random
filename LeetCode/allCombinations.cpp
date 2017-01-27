#include <iostream>

void printCombinations(int n){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			std::cout << i << "," << j << std::endl;
		}
	}
}

int main(){
	int n;
	std::cin >> n;
	printCombinations(n);
}