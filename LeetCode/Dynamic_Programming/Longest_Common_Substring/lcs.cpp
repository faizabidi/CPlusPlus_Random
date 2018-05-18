#include <iostream>
#include <vector>

// O(nxmxm)
int lcs(std::string str1, std::string str2){
	int ans = 0;
	std::string str3 = "";
	for(int i = 0; i < str1.size(); i++){
		for(int j = 0; j < str2.size(); j++){
			std::string temp = "";
			if(str1[i] == str2[j]){
				temp += str1[i];
				int k = i+1, l=j+1;
				while(str1[k] == str2[l] && 
										k < str1.size() && l < str2.size()){

					temp += str1[k];
					k++, l++;
				}
			}
			if(temp.size() > ans){
				str3 = temp;
				ans = temp.size();
			}
		}
	}
	std::cout << str3 << std::endl;
	return ans;
}
/****************************/
// Helper functions
// Print the matrix
template<typename T>
void printMatrix(std::vector<std::vector<T>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

// Print the lcs
void printLCS(std::vector<std::vector<int>> matrix, 
										std::string str1, std::string str2){

	int max = 0, l = 0, m = 0;;
	std::string lcs = "";

	int rows = matrix.size();
	int cols = matrix[0].size();

	// Find out the l,m position of the max element
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j] > max){
				max = matrix[i][j];
				l = i;
				m = j;
			}
		}
	}

	// From l and m position, keep going diagonal till you hit a zero
	while(matrix[l][m] != 0){
		lcs += str1[l-1];
		l--, m--;
	}

	std::reverse(lcs.begin(), lcs.end());
	std::cout << lcs << std::endl;

}
/****************************/
// DP Solution
// O(nxm)
int lcs_dp(std::string str1, std::string str2){
	int ans = 0;
	int rows = str1.size() + 1;
	int cols = str2.size() + 1;
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == 0 || j == 0)
				matrix[i][j] = 0;
			else if(str1[i-1] != str2[j-1])
				matrix[i][j] = 0;
			else
				matrix[i][j] = 1 + matrix[i-1][j-1];
		}
	}
	//printMatrix(matrix);
	printLCS(matrix, str1, str2);
	// Iterate through the matrix to find the max element
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] > ans)
				ans = matrix[i][j];
		}
	}
	return ans;
}

int main(){
	//std::string str1 = "GeeksforGeeks";
	//std::string str2 = "GeeksQuiz";

	//std::string str1 = "faizz";
	//std::string str2 = "fxizzz";

	std::string str1 = "abcfxd";
	std::string str2 = "abclxd";

	std::cout << lcs(str1, str2) << std::endl;;
	std::cout << lcs_dp(str1, str2) << std::endl;;

	return 0;
}
