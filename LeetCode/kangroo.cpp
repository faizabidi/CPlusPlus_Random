// https://www.hackerrank.com/challenges/kangaroo

#include <iostream>

using namespace std;

void calculate(int x1, int v1, int x2, int v2){
	while(true){
		if(x1 == x2){
			std::cout << "YES\n";
			break;
		}
		x1 += v1;
		x2 += v2;

		if((x1 > x2 && v1 > v2) || (x2 > x1 && v2 > v1) || (x1 != x2 && v1 == v2)){
			std::cout << "NO\n";
			break;
		}
	}
}

int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

    calculate(x1, v1, x2, v2);

    return 0;
}