#include <iostream>

long calculate(std::string str){
	std::string opponent;
	opponent += 'R';
	opponent += 'R';

	for(int i = 2; i < str.size(); i++){
		if(str[i - 2] == str[i - 1]){
			if(str[i - 2] == 'R')
				opponent += 'P';
			else if(str[i - 2] == 'P')
				opponent += 'S';
			else if(str[i - 2] == 'S')
				opponent += 'R';
		}
		else if(str[i - 2] != str[i - 1]){
			if(str[i - 2] == 'R' && str[i - 1] == 'P')
				opponent += 'R';
			else if(str[i - 2] == 'R' && str[i - 1] == 'S')
				opponent += 'S';
			else if(str[i - 2] == 'P' && str[i - 1] == 'R')
				opponent += 'R';
			else if(str[i - 2] == 'P' && str[i - 1] == 'S')
				opponent += 'P';
			else if(str[i - 2] == 'S' && str[i - 1] == 'R')
				opponent += 'S';
			else if(str[i - 2] == 'S' && str[i - 1] == 'P')
				opponent += 'P';
		}
	}

	std::cout << str << std::endl << opponent << std::endl;

	long count = 0;

	// Now check and compare
	for(int i = 0; i < str.size(); i++){
		if(str[i] == 'R' && opponent[i] == 'P')
			count++;
		else if(str[i] == 'P' && opponent[i] == 'S')
			count++;
		else if(str[i] == 'S' && opponent[i] == 'R')
			count++; 
	}
	return count;
}

int main(){
	std::string str;
	std::cin >> str;
	std::cout << calculate(str);
	return 0;
}