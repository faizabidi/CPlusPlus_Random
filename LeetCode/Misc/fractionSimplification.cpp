#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<int> array){
	for(auto value : array)
		cout << value << " ";
	cout << endl;
}

// Find prime factors
vector<int> findPrimesFactors(int a){
	vector<int> factors;
	while(a % 2 == 0){
		factors.push_back(2);
		a /= 2;
	}
	for(int i = 3; i < sqrt(a); i += 2){
		if(a % i == 0){
			factors.push_back(i);
			a /= i;
		}

	}
	if(a > 2)
		factors.push_back(a);
	return factors;
}

// Find GCD
int findGCD(vector<int> array1, vector<int> array2){
	int i = 0, j = 0, gcd = 1;
	while(i < array1.size() && j < array2.size()){
		if(array1[i] == array2[j]){
			gcd *= array1[i];
			i++, j++;
		}
		else if(array1[i] > array2[j])
			j++;
		else
			i++;
	}
	return gcd;
}

int main(){
	int a, b;
	cin >> a >> b;

	vector<int> primeFactorsA = findPrimesFactors(a);
	vector<int> primeFactorsB = findPrimesFactors(b);

	printVector(primeFactorsA);
	printVector(primeFactorsB);

	int gcd = findGCD(primeFactorsA, primeFactorsB);
	cout << "GCD of " << a << " and " << b << " = " << gcd << endl;

	cout << "Simplied a/b = " << a/gcd << "/" << b/gcd << endl;

	return 0;

}