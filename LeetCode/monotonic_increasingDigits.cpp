// https://leetcode.com/contest/weekly-contest-61/problems/monotone-increasing-digits/

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
	bool isMonotonic(int n){
		std::string num = std::to_string(n);
		if(num.size() == 1)
			return true;
		for(int i = 1; i < num.size(); i++){
			if(num[i] - num[i - 1] < 0)
				return false;
		}
		return true;
	}

	// O(nxn) in the worst case
    int monotoneIncreasingDigits(int n){
        for(int i = n; i >= 0; i--){
        	if(isMonotonic(i))
        		return i;
        }
        return 0;
    }
    
    // O(n)
    int monotoneIncreasingDigits2(int n){
	    std::string num = std::to_string(n);
	    int size = num.size();
	    std::string ans;
	    
	    // If single digit number
	    if(size == 1)
	    	return n;

	    // If the number itself is the ans
	    if(isMonotonic(n))
	    	return n;

	    // Find the first digit where inversion happens
	    int inversion_index = 0;
	    for(int i = 1; i < num.size(); i++){
	  		if(num[i] - num[i - 1] < 0){
	  			// Found our inversion
	  			// Still need to check if the previous numbers are also same
	  			inversion_index = i - 1;
	  			int j = inversion_index;
	  			while(num[j] == num[j - 1] && j - 1 >= 0)
	  				j--;
	  			inversion_index = j;
	  			num[inversion_index] = (num[inversion_index] - '0' - 1) + '0';
	  			break;
	  		}
	  	}

	  	// Add all 9's at the end now
	  	for(int i = inversion_index + 1; i < num.size(); i++)
	  		num[i] = '9';

	  	return stoi(num);
	}
};

int main(){
	int num;
	std::cin >> num;
	Solution obj1;
	std::cout << obj1.monotoneIncreasingDigits2(num);
	
	return 0;
}
