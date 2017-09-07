#include <iostream>

int fib(int n){
	if(n < 3)
		return 1;
	return fib(n - 2) + fib(n - 1);
}

int main(){
	std::cout << fib(45) << std::endl; // Ans = 1134903170

	return 0;
}
