// https://www.hackerrank.com/challenges/weighted-uniform-string

#include <vector>
#include <iostream>

template <typename T>
void printVector(std::vector<T> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

int check(std::string str){
	int ans = 0;
	for(int i = 0; i < str.size(); i++)
		ans += str[i] - 0 - 96;

	return ans; 
}

std::vector<std::string> calculate(std::string str, std::vector<int> queries){
	std::vector<int> uniform_string_values;
	std::vector<std::string> ans;

	for(int i = 0; i < str.size(); i++){
		// If two or more consecutive characters are equal
		if(str[i] == str[i + 1] && i + 1 < str.size()){
			int j = i;
			std::string temp;
			int length = 0;
			while(str[j] == str[i] && j < str.size()){
				length++;
				temp += str[j];
				uniform_string_values.push_back((str[i] - 0 - 96) * length);
				j++;
			}
			i = j - 1;
		}
		else{
			std::string temp;
			temp += str[i];
			uniform_string_values.push_back(str[i] - 0 - 96);
		}
	}

	for(int i = 0; i < queries.size(); i++){
		if(std::find(uniform_string_values.begin(), uniform_string_values.end(),
			queries[i]) != uniform_string_values.end())
			ans.push_back("YES");
		else
			ans.push_back("NO");
	}

	return ans;
}

int main(){
	std::string str;
	std::cin >> str;

	int queries;
	std::cin >> queries;

	std::vector<int> q(queries);
	for(int i = 0; i < queries; i++)
		std::cin >> q[i];

	std::vector<std::string> ans = calculate(str, q);

	printVector(ans);

    return 0;
}
