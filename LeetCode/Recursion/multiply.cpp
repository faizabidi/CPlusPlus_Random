#include <iostream>

int multiply(int a, int b){
	if(b < a)
		return 1;
	return b * multiply(a, b - 1);
}

int main(){
	int a, b;
	std::cin >> a >> b;
	std::cout << multiply(a,b);

	return 0;
}