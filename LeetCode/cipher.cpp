// https://www.hackerrank.com/challenges/caesar-cipher-1

#include <vector>
#include <iostream>

class Solution{
public:
	std::string calculate(std::string &str, int k){
		k = k % 26;
		for(int i = 0; i < str.size(); i++){
			// Check if a letter
			if((str[i] - 0 >= 65 && str[i] - 0 <= 90) || 
				(str[i] - 0 >= 97 && str[i] - 0 <= 122)){
				// Check if overflow from Z side
				if(str[i] - 0 <= 90 && str[i] - 0 + k > 90)
					str[i] = char(str[i] - 0 + k - 26);
				// Check if overflow from z side
				else if(str[i] - 0 >= 97 && str[i] - 0 + k > 122)
					str[i] = char(str[i] - 0 + k - 26);
				// Else, just add the k value
				else
					str[i] = char(str[i] - 0 + k);
			}
		}
		return str;
	}
};

int main(){
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	int k;
	std::cin >> k;

	Solution obj1;
	std::cout << obj1.calculate(str, k);
    return 0;
}
