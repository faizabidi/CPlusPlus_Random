// https://www.pramp.com/challenge/61ojWAjLJbhob2nP2q1O
/*
The deletion distance of two strings is the minimum number of characters you need to delete in the two strings in order to get the same string. For instance, the deletion distance between "heat" and "hit" is 3.
*/

#include <iostream>
#include <vector>

/**************************************/
// Helper functions
template<typename T>
void print_matrix(std::vector<std::vector<T>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void printArray(std::vector<std::string> array){
	for(auto value : array)
		std::cout << value << std::endl;
}

void printLCS(std::string str1, std::string str2, 
							std::vector<std::vector<int>> matrix){

	int rows = matrix.size() - 1;
	int cols = matrix[0].size() - 1;
	std::string lcs = "";

	while(rows > 0 && cols > 0){
		if(str1[cols-1] == str2[rows-1]){
			lcs.push_back(str1[cols-1]);
			rows--, cols--;
		}
		else if(matrix[rows-1][cols] > matrix[rows][cols-1])
			rows--;
		else
			cols--;
	}
	std::reverse(lcs.begin(), lcs.end());
	std::cout << "LCS is " << lcs << std::endl;
}
/**************************************/
// Recursively
// O(n*2^m)
void subseq(std::string str, std::string temp, int index, 
							std::vector<std::string> &all_subseq){

	if(index == str.size()){
		all_subseq.push_back(temp);
		return;
	}

	// Include the character
	subseq(str, temp + str[index], index+1, all_subseq);

	// Exclude the character
	subseq(str, temp, index+1, all_subseq);
}

int deletionDistance(const std::string& str1, const std::string& str2){
  std::vector<std::string> str1_subseq, str2_subseq;
  std::string longest_subeq = "";

  subseq(str1, "", 0, str1_subseq);
  subseq(str2, "", 0, str2_subseq);
  for(int i = 0; i < str1_subseq.size(); i++){
    std::string temp = str1_subseq[i];
    // If found
    if(find(str2_subseq.begin(), str2_subseq.end(), temp) != 
    		str2_subseq.end() && temp.size() > longest_subeq.size())
        longest_subeq = temp;
  }

  return str1.size() + str2.size() - 2*longest_subeq.size();
}
/**************************************/
// LCS using DP
// O(n^2)
int LCS(std::string str1, std::string str2){
	int rows = str2.size() + 1;
	int cols = str1.size() + 1;
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == 0 || j == 0)
				matrix[i][j] = 0;
			else if(str2[i - 1] == str1[j - 1])
				matrix[i][j] += matrix[i-1][j-1] + 1;
			else if(str2[i - 1] != str1[j - 1])
				matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
		}
	}

	// Print the LCS
	printLCS(str1, str2, matrix);
	
	// Return the last value
	return matrix[rows-1][cols-1];
}

int deletionDistance2(const std::string& str1, const std::string& str2){
	int lcs_length = LCS(str1, str2);
	return str1.size() + str2.size() - 2*lcs_length;
}
/**************************************/

int main(){
	std::string str1 = "AGGTAB", str2 = "GTAB";

	std::cout << "Deletion distance is: " 
						<< deletionDistance(str1, str2) << std::endl;
	std::cout << "Deletion distance is: "
						<< deletionDistance2(str1, str2) << std::endl;


	return 0;
}
