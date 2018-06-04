// http://ysonggit.github.io/coding/2014/12/16/split-a-string-using-c.html

#include <iostream>
#include <vector>
#include <sstream>

template<typename T>
void printVector(std::vector<T> array){
	for(auto value : array)
		std::cout << value << std::endl;
}

std::vector<std::string> split(std::string str){
	std::vector<std::string> array;
	std::stringstream ss(str);
	std::string buffer;
	
	// Split on white spaces. Could have been any other delimeter as well
	while(std::getline(ss, buffer, ' '))
		array.push_back(buffer);
	return array;
}

int main(){
	std::string str = "Faiz Abbas Abidi is a, boy.";
	std::vector<std::string> array = split(str);
	printVector(array);

	return 0;
}