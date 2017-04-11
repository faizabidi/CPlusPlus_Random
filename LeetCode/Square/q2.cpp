#include <iostream>
#include <vector>

void calculateScore(std::vector<int> array){
	int score = 0;
	bool strike false, spare = false;
	for(int i = 0; array.size(); i++){
		// Check if it was a strike previously
		if(strike == true){
			score += array[i] + array[i+1] + array[i+2];
			// Check if a strike now
			if(array[i] == 10)
				strike = true;
			// Check if spare
			else if(array[i] + array[i+1] == 10)
				spare = true;
		}
		else if(spare == true)
	}
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	calculateScore(array);

	return 0;
}
