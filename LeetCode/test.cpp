#include <iostream>
#include <vector>

std::vector<int> Test(std::vector<int> array){
	array.push_back(1);
	return array;
}

int main(){
	std::vector<int> array;
	array.push_back(1);
	Test(array);
	return 0;	
}