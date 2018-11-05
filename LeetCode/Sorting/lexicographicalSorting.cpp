#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool compare(string a, string b){
	// Check each digit
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		// If different digits
		if(a[i] - '0' != b[j] - '0')
			return (a[i] - '0' < b[i] - '0');
		i++, j++;
	}
	// Different sizes
	return (a.size() < b.size());
}

int main(){
	vector<string> array = {"1","2","3","4","5","6","7","8","9","10","11","12"};
	sort(array.begin(), array.end(), compare);

	for(auto value : array)
		cout << value << " ";
	return 0;
}