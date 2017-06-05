// https://www.hackerrank.com/challenges/separate-the-numbers

#include <iostream>
#include <vector>
#include <cstdlib>

template <typename T>
void printVector(std::vector<T> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

// REF: https://www.hackerrank.com/challenges/separate-the-numbers/forum

std::vector<std::string> calculate(std::vector<std::string> array){
	std::vector<std::string> ans;
	for(int i = 0; i < array.size(); i++){
		if(array[i] == "0")
			ans.push_back("NO");
		else{
			std::string str = array[i];
			std::string temp;
			long long smallest, temp_value;
			for(int j = 1; j <= str.size() / 2; j++){
				temp = str.substr(0, j);
				smallest = temp_value = std::stoll(temp);
				while(temp.size() < str.size()){
					temp_value++;
					temp += std::to_string(temp_value);
				}
				if(temp == str)
					break;
			}
			if(temp == str){
				std::string temp1 = "YES " + std::to_string(smallest);
				ans.push_back(temp1);
			}
			else
				ans.push_back("NO");
		}
	}
	return ans;
}

int main(){
	int q;
	std::cin >> q;

	std::vector<std::string> array(q);
	for(int i = 0; i < q; i++)
		std::cin >> array[i];

	std::vector<std::string> ans = calculate(array);
	printVector(ans);

	return 0;
}