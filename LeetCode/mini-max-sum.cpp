// https://www.hackerrank.com/challenges/mini-max-sum

#include <iostream>

void calculate(long a, long b, long c, long d, long e){
	long min = std::min(std::min(std::min(d,e), std::min(b, c)), a);
	long max = std::max(std::max(std::max(d,e), std::max(b, c)), a);
	long max_sum = a + b + c + d + e - min;
	long min_sum = a + b + c + d + e - max;
	std::cout << max_sum << " " << min_sum << std::endl;
}

int main(){
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    std::cin >> a >> b >> c >> d >> e;
    calculate(a, b, c, d, e);
    return 0;
}