#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

int main(){
	std::ifstream t("test.txt");
	std::string str((std::istreambuf_iterator<char>(t)),
	                 std::istreambuf_iterator<char>());

	// str will store the entire contents of the file 
	// If there is a newline, it will treat that as a space
	std::cout << str << std::endl;
	std::cout << str.size();

	return 0;
}
