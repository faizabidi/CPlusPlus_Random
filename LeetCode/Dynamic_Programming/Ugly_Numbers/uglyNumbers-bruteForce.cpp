// Ugly is a number who's only factors are 2, 3, and 5

#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n){
	if(n == 2)
		return true;
	for(int i = sqrt(n) ; i >= 2; i--){
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
		// If n is prime, there is no other factor than itself
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

// Without DP, print the nth ugly number
int uglyNumber(int n){
	if(n == 1)
		return 1;
	// Ugly is a number who's only prime factors are 2, 3, or 5. 1 is by default included as ugly
	int count = 1, i = 2;
	while(count <= n){
		std::vector<int> factors = findPrimeFactors(i);
		// If the factors have anything but 2, 3, 5 then it is not ugly
		bool flag = true;
		//std::cout << "Hello1\n";
		for(int j = 0; j < factors.size(); j++){
			if(factors[j] != 2 && factors[j] != 3 && factors[j] != 5){
				flag = false;
				break;
			}
		}
		if(flag)
			count++;
		// If number was ugly and count has reached the value of n
		if(flag && count == n)
			return i;
		i++;
	}
	return i;
}

int main(){
	int n;
	std::cin >> n;
	std::cout << uglyNumber(n);
	
	return 0;
}
