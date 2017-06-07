#include <iostream>
#include <vector>

std::string calculate(std::vector<int> array, int money){
	std::string ans;
	for(int i = 0; i < array.size(); i++){
		std::string ans = std::to_string(i);
		std::vector<int>::iterator it;
		it = std::find(array.begin() + i + 1, array.end(), money - array[i]);
		if(it != array.end()){
			ans += " " + std::to_string(it - array.begin());
			return ans;
		}
		else
			ans.clear();
	}
	return ans;
}

int main(){
	int trips;
	std::cin >> trips;

	for(int i = 0; i < trips; i++){
		int money, num_flavours;
		std::cin >> money >> num_flavours;
		
		std::vector<int> flavours(num_flavours);
		
		for(int j = 0; j < num_flavours; j++)
			std::cin >> flavours[j];

		std::cout << calculate(flavours, money) << std::endl;
	}
	return 0;
}