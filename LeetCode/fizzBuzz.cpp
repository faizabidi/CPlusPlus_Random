#include <iostream>

// Without recursion
void calculate1(int n){
	for(int i = 1; i <= n; i++){
		if(i % 3 == 0 && i % 5 == 0)
			std::cout << "FizzBuzz\n";
		else if(i % 3 == 0)
			std::cout << "Fizz\n";
		else if(i % 5 == 0)
			std::cout << "Buzz\n";
		else
			std::cout << i << std::endl;
	}
}

// With recursion
void calculate2(int n){
	// Base condition
	if(n == 0)
		return;

	if(n > 0)
		calculate2(n - 1);	
	
	if(n % 3 == 0 && n % 5 == 0)
		std::cout << "FizzBuzz\n";
	else if(n % 3 == 0)
		std::cout << "Fizz\n";
	else if(n % 5 == 0)
		std::cout << "Buzz\n";
	else
		std::cout << n << std::endl;
}

int main(){
	int n;
	std::cout << "Enter n:";
	std::cin >> n;

	calculate2(n);

	return 0;
}