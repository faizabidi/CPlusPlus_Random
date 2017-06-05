// https://www.hackerrank.com/challenges/mars-exploration

#include <vector>
#include <iostream>

class Solution{
public:
	int calculate(std::string str){
		std::string temp = "SOS";
		int ans = 0;
		int j = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] != temp[j])
				ans++;
			j++;
			if(j == 3)
				j = 0;			
		}
		return ans;
	}
};

int main(){
	std::string str;
	std::cin >> str;

	Solution obj1;
	std::cout << obj1.calculate(str);

    return 0;
}
