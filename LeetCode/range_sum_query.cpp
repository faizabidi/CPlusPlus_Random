#include <iostream>
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int> &nums) {
        
    }

    int sumRange(int i, int j) {
        
    }
};

int main(){
	int num;
	std::vector<int> array;
	NumArray obj1;

	std::cout << "Enter an array of numbers (x to stop):";
	while(!std::cin.fail()){
		std::cin >> num;
		array.push_back(num);
	}

	std::cout << obj1.NumArray(array) << std::endl;
	
	return 0;
}