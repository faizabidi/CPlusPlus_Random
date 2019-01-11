#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

// O(n) time
std::vector<int> findPrimeFactors2(int n){
	vector<int> factors;
	while(n % 2 == 0){
		factors.push_back(2);
		n /= 2;
	}
	for(int i = 3; i <= sqrt(n); i += 2){
		while(n % i == 0){
			factors.push_back(i);
			n /= i;
		}
	}
	if(n > 2)
		factors.push_back(n);
	return factors;
}

int main(){
	int n;
	std::cin >> n;

	std::cout << "Prime factors are: ";
	std::vector<int> factor1 = findPrimeFactors(n);
	printVector(factor1);
	std::vector<int> factor2 = findPrimeFactors2(n);
	printVector(factor2);
	return 0;
}
