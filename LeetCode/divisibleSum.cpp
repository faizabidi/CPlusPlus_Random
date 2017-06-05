//https://www.hackerrank.com/challenges/divisible-sum-pairs


#include <iostream>
#include <vector>

using namespace std;

int calculate(int n, int k, std::vector<int> array){
	int count = 0;
	for(int i = 0; i < array.size(); i++){
		for(int j = i + 1; j < array.size(); j++){
			if((array[i] + array[j]) % k == 0)
				count++;
		}
	}
	return count;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    std::cout << calculate(n, k, a);
    return 0;
}
