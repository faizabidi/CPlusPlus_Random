#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n){
	if(n == 2)
		return true;
	for(int i = 2 ; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++){
		if(i != array.size() - 1) 
			std::cout << array[i] << " x ";
		else
			std::cout << array[i];
	}
	std::cout << std::endl;
}

std::vector<int> findPrimeFactors(int n){
	std::vector<int> factors;
	if(n == 1){
		factors.push_back(n);
		return factors;
	}
	while(n > 1){
		// If n is prime
		if(isPrime(n)){
			factors.push_back(n);
			return factors;
		}
		else{
			// Find the smallest prime number that fully divides n
			// Start with 2 and keep doing this till we get 0 or 1 in the end
			int primeNum = 2;
			while(primeNum < n){
				if(isPrime(primeNum) && n % primeNum == 0){
					factors.push_back(primeNum);
					n = n / primeNum;
					break;
				}
				else
					primeNum++;
			}		
		}
	}
	return factors;
}

int main(){
	int n;
	std::cin >> n;

	std::cout << "Prime factors are: ";
	std::vector<int> factor = findPrimeFactors(n);
	printVector(factor);
	return 0;
}
