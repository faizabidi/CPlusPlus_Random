// https://leetcode.com/problems/roman-to-integer/description/

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int romanToInt(std::string str){
        //std::string ans;
        int ans = 0;
        for(int i = 0; i < str.size(); i++){
        	// Edge case of 4
        	if(str[i] == 'I' && i + 1 < str.size() && str[i+1] == 'V'){
        		ans += 4;
        		i++;
        	}
        	// Edge case of 9
        	else if(str[i] == 'I' && i + 1 < str.size() && str[i+1] == 'X'){
        		ans += 9;
        		i++;
        	}
        	// Edge case of 40
        	else if(str[i] == 'X' && i + 1 < str.size() && str[i+1] == 'L'){
        		ans += 40;
        		i++;
        	}
        	// Edge case of 90
        	else if(str[i] == 'X' && i + 1 < str.size() && str[i+1] == 'C'){
        		ans += 90;
        		i++;
        	}
        	// Edge case of 400
        	else if(str[i] == 'C' && i + 1 < str.size() && str[i+1] == 'D'){
        		ans += 400;
        		i++;
        	}
        	// Edge case of 900
        	else if(str[i] == 'C' && i + 1 < str.size() && str[i+1] == 'M'){
        		ans += 900;
        		i++;
        	}
        	else if(str[i] == 'I')
        		ans += 1;
        	else if(str[i] == 'V')
        		ans += 5;
        	else if(str[i] == 'X')
        		ans += 10;
        	else if(str[i] == 'L')
        		ans += 50;
        	else if(str[i] == 'C')
        		ans += 100;
        	else if(str[i] == 'D')
        		ans += 500;
        	else if(str[i] == 'M')
        		ans += 1000;
        	//std::cout << "Ans for " << str[i] << " = " << ans << std::endl;
        }
        return ans;
    }
    // Better, cleaner solution
    // Work from end of the string to the beginnning
    // Source: https://discuss.leetcode.com/topic/7784/clean-o-n-c-solution
    int romanToInt2(std::string str){
    	std::map<char, int> hashmap = {{'I', 1},
    									{'V', 5},
    									{'X', 10},
    									{'L', 50},
    									{'C', 100},
    									{'D', 500},
    									{'M', 1000}};
    	if(str.size() == 0)
    		return 0;
    	int ans = hashmap[str.back()];
    	for(int i = str.size() - 2; i >= 0; i--){
    		if(hashmap[str[i]] > hashmap[str[i + 1]])
    			ans += hashmap[str[i]];
    		else
    			ans -= hashmap[str[i]];
    	}
    	return ans;
    }
};

int main(){
	std::string str;
	std::cin >> str;
	Solution obj1;
	std::cout << obj1.romanToInt(str) << std::endl;
	std::cout << obj1.romanToInt2(str) << std::endl;
	return 0;
}