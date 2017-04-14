#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string str){
        // Check if empty string
        if(str.size() == 0)
            return 0;
            
        // Check if string starts with empty spaces
        int i = 0;
        while(str[i] == ' ')
            i++;
            
        // Check if the string starts with an alphabet other than + or -
        // 48 => 0; 57 => 9
        if( (int(str[i]) < 48 || int(str[i]) > 57) && str[i] != '+' && str[i] != '-')
            return 0;
        
        // Check if the first character is a '+'' or a '-''
        bool positive = false, negative = false;
        
        if(str[i] == '+'){
            std::cout << "Positive number\n";
            positive = true;
            i++;
        }
        else if(str[i] == '-'){
            std::cout << "Negative number\n";
            negative = true;
            i++;
        }
        
        // Else, parse the string. Stop if an alphabet is encountered
        std::string temp;
        while(int(str[i]) >= 48 && int(str[i]) <= 57 && i < str.size()){
            temp += str[i];
            i++;
        }

        long ans = 0;
        long tens = 1;
        for(int j = temp.size() - 1; j >= 0; j--){
            ans += (int(temp[j]) - 48) * tens;
            tens *= 10;
            if(ans > INT_MAX)
                break;
        }
        if(negative)
            ans = ans * -1;
        if(ans > INT_MAX)
            ans = INT_MAX;
        if(ans < INT_MIN)
            ans = INT_MIN;
        return ans;
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