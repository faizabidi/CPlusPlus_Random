#include <iostream>
#include <cmath>
#include <limits>

class Solution{
public:
    
    int reverse(int x){
    	// Convert int to string
    	std::string str = std::to_string(x);

    	// Find the size of the string    
    	size_t length = str.size() - 1;  

    	// String to store the reveresed number
    	std::string rev_str;

    	// To store the reversed number
    	int rev_num_int;

    	// Assuming no minus or plus sign in the input
    	if(str[0] != '-' || str[0] != '+'){
    		for(int i = length; i >=0; i--)
    			rev_str.push_back(str[i]);
    	}
    	
    	// Return 0 if out of range
    	try{
    		rev_num_int = std::stoi(rev_str);
    	}
    	catch (const std::out_of_range& oor){
    		return 0;
    		//std::cerr << "Out of Range error: " << oor.what() << '\n';
    	}

    	// If input is negative
    	if(str[0] == '-')
    		rev_num_int = rev_num_int * -1;
    	return rev_num_int;
	}	

	int reverse2(int x){
		long rev_num = 0;
		while(x){
			rev_num = rev_num * 10 + x % 10;
			x = x / 10;
		}
		return (rev_num > INT_MAX || rev_num < INT_MIN) ? 0 : rev_num;
	}
};

int main(){
	Solution obj1;
	int num;

	std::cout << "Enter a number:";
	std::cin >> num;

	std::cout << obj1.reverse2(num) << std::endl;

	return 0;
}