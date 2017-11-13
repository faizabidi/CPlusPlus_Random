#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(long long n){
	if(n == 2)
		return true;
	for(long long i = 2 ; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

void printVector(std::vector<long long> array){
	for(long long i = 0; i < array.size(); i++){
		if(i != array.size() - 1) 
			std::cout << array[i] << " x ";
		else
			std::cout << array[i];
	}
	std::cout << std::endl;
}

void findPrimeFactors(long long n){
	std::vector<long long> factors;
	while(n > 1){
		// If n is prime
		if(isPrime(n)){
			factors.push_back(n);
			break;
		}
		else{
			// Find the smallest prime number that fully divides n
			// Start with 2 and keep doing this till we get 0 or 1 in the end
			long long primeNum = 2;
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
	printVector(factors);
}

int main(){
	long long n;
	std::cin >> n;

	std::cout << "Prime factors are: ";
	findPrimeFactors(n);
	return 0;
}
