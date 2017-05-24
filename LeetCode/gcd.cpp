#include <iostream>
#include <vector>

// Non-recursive
int gcd(int a, int b){
	while(true){
		int quotient = a / b;
		int remainder = a % b;
		
		if(remainder == 0)
			return b;
		else{
			a = b;
			b = remainder;
		}
	}
	return 0;
}

// Recursive
int gcd2(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	std::vector<int> array = {1,2,3,4,5};
	std::cout << "GCD of 48 and 18 is " << gcd2(48, 18) << std::endl;
	return 0;
}