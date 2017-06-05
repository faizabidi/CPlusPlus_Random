// https://www.hackerrank.com/challenges/hackerrank-in-a-string

#include <vector>
#include <iostream>

bool check(std::string str){
	std::string temp = "hackerrank";
	int j = 0;
	for(int i = 0; i < str.size(); i++){
		if(temp[j] == str[i])
			j++;
	}
	if(j == temp.size())
		return true;
	return false;
}

void calculate(std::vector<std::string> array){
	for(int i = 0; i < array.size(); i++){
		std::string str = array[i];
		if(check(str))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}

int main(){
	int n;
	std::cin >> n;
	std::vector<std::string> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	calculate(array);
    return 0;
}
