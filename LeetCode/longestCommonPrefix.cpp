#include <iostream>
#include <vector>

std::string calculate(std::vector<std::string> array){
	if(array.size() == 0)
		return 0;
	std::string prefix = array[0];
	std::string ans;
	for(int i = 1; i < array.size(); i++){
		// Compare the first two strings
		std::string temp = array[i];
		int j = 0;
		while(temp[j] == prefix[j] && j < temp.size() && j < prefix.size()){
			ans += temp[j];
			j++;
		}
		prefix = ans;
		ans = "";
	}
	return prefix;
}

int main(){
	std::cout << "Number of strings:";
	int n;
	std::cin >> n;

	std::cout << "Enter the strings:\n";
	std::vector<std::string> array(n);
	std::cin.ignore();
	for(int i = 0; i < n; i++)
		getline(std::cin, array[i]);

	std::cout << calculate(array);

	return 0;
}