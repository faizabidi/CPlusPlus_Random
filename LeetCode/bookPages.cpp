// https://www.hackerrank.com/challenges/drawing-book

#include <iostream>
#include <vector>


int solve(int n, int p){

    int front_count = 0, back_count = 0;

    for(int i = 1; i <= n; i += 2){
    	if(p <= i)
    		break;
    	front_count++;
    }

    if(n % 2 != 0){
	    for(int i = n - 1; i >= 1; i -= 2){
	    	if(p >= i)
	    		break;
	    	back_count++;
	    }
	}

	else if(n % 2 == 0){
		for(int i = n; i >= 1; i -= 2){
	    	if(p >= i)
	    		break;
	    	back_count++;
	    }
	}

    return std::min(front_count, back_count);
}

int main() {
    int n;
    std::cin >> n;
    int p;
    std::cin >> p;
    int result = solve(n, p);
    std::cout << result << std::endl;
    return 0;
}
