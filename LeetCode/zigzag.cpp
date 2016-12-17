// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include <vector>

class Solution{
public:
    std::string convert(std::string str, int numRows){
    	// Create an array of rows
    	// Using vectors since we don't know the size of the array
    	std::vector<std::string> array(numRows);

    	// Base condition when everything in the same row
    	if(s.size() <= numRows || numRows == 1)
    		return str;

    	bool down;
    	int row;
    	int length = str.size();
    	
    	// New string to store everything
    	std::string newStr;
    	
    	for(int i = 0; i < length; i++){
    		array[row].push_back(str[i]);
    		if(row == 0)
    			down = true;
    		else if (row == numRows - 1)
    			down = false;

    		if(down == true)
    			row++;
    		else
    			row--;
    	}

    	// Save the vector in a string
    	for(int i = 0; i < numRows; i++)
    		newStr.append(array[i]);
    	
    	return newStr;
    }
};

int main(){
	Solution obj1;
	std::string str;
	int rows;

	std::cout << "Enter a string:";
	std::getline(std::cin, str);
	std::cout << "Enter number of rows:";
	std::cin >> rows;

	std::cout << obj1.convert(str, rows);

	return 0;
}