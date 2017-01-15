// https://www.hackerrank.com/challenges/30-more-exceptions

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>

class Calculator{
public:
	//Calculator(){};
	int power(int n, int p){
		if (n < 0 || p < 0)
			throw std::invalid_argument("n and p should be non-negative");
		else
			return pow(n, p);
	}
};

int main()
{
	Calculator myCalculator = Calculator();
	int T, n, p;

	std::cin>>T;

	while(T-- > 0){
		if(std::cin >> n && std::cin >> p){
			try{
				int ans = myCalculator.power(n,p);
				std::cout << ans << std::endl; 
			}
			catch(std::exception& e){
				std::cout << e.what() << std::endl;
			}
		}
	}
}