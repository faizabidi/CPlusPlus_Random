#include <iostream>     // std::cout
#include <sstream>      // std::istringstream

int main(){
	std::string stringvalues = "125 320 512 750 333";
	std::istringstream iss(stringvalues);

	// Print its contents
	std::cout << iss.str() << std::endl;

	for(int n = 0; n < stringvalues.size(); n++){
		int val;
		iss >> val;
		std::cout << val << std::endl;
	}

	return 0;
}