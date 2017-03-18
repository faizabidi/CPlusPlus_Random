#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string str){
    	int num = 0;
    	std::vector<int> array;
    	bool negative = false;
    	bool positive = false;
    	int i = 0;

    	// Find the first non-space character
    	while(str[i] == ' ')
    		i++;
    	
    	// Check if a minus sign is NOT followed by a digit
    	if( (str[i] == '-') && (int(str[i+1]) < 48 && int(str[i+1]) > 57) )
    		return 0;
    	// Check if a plus sign is NOT followed by a digit
    	if( (str[i] == '+') && (int(str[i+1]) < 48 && int(str[i+1]) > 57) )
    		return 0;

    	// If a minus sign is followed by a digit
    	if((str[i] == '-') && (int(str[i+1]) >= 48 && int(str[i+1]) <= 57) ){
    		negative = true;
    		int j = i + 1;
    		while( (int(str[j]) >= 48) && (int(str[j]) <= 57) ){
    			array.push_back(int(str[j]) - 48);
    			j++;
    		}
    	}

    	// If a plus sign is followed by a digit
    	if(str[i] == '+' && (int(str[i+1]) >= 48 && int(str[i+1]) <= 57)){
    		std::cout << "Found!";
    		positive = true;
    		int j = i + 1;
    		while( (int(str[j]) >= 48) && (int(str[j]) <= 57) ){
    			array.push_back(int(str[j]) - 48);
    			j++;
    		}
    	}

    	// If no minus or plus signs
    	if( (int(str[i]) >= 48 && int(str[i]) <= 57) ){
    		while( (int(str[i]) >= 48) && (int(str[i]) <= 57) ){
    			array.push_back(int(str[i]) - 48);
    			i++;
    		}
    	}

    	int array_length = array.size();
    	for(int i = 0; i < array_length; i++)
    		num = num + pow(10, (array_length - 1 - i)) * array[i];

    	if(num > INT_MAX)
    		return 2147483647;

    	if(num < INT_MIN)
    		return -2147483648;

    	if(negative)
    		return -num;

    	return num;
    }
};

int main(){
	std::string str;
	Solution obj1;

	std::cout << "Enter a string: ";
	getline(std::cin,str);

	std::cout << obj1.myAtoi(str) << std::endl;
	return 0;
}