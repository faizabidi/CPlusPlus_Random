// https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <vector>
#include <map>

/*******************************************/
// Brute force
// O(2^n) time and O(n) space
int uniquePaths_helper(int m, int n, int i, int j){
	if(i == m - 1 && j == n - 1)
		return 1;
	if(i == m || j == n)
		return 0;
	int right = uniquePaths_helper(m, n, i, j+1);
	int bottom = uniquePaths_helper(m, n, i+1, j);
	return right + bottom;
}

int uniquePaths(int m, int n){
	int paths = uniquePaths_helper(m, n, 0, 0);
	return paths;
}
/*******************************************/
// DP solution
// Memoization
// O(nlog(n)) time and O(n) space
int uniquePaths_helper2(int m, int n, int i, int j, 
							std::map<std::pair<int, int>, int> &hashmap){

    if(i == m - 1 && j == n - 1)
        return 1;
    if(i == m || j == n)
        return 0;
    
    int right = 0, bottom = 0;
    // Check if in hashmap
    // Check right side
    auto it1 = hashmap.find(std::make_pair(i,j+1));
    if(it1 == hashmap.end()){
        right = uniquePaths_helper2(m, n, i, j+1, hashmap);
        hashmap[std::make_pair(i, j+1)] = right;
    }
    else
        right = hashmap[std::make_pair(i, j+1)];
    // Check bottom side
    auto it2 = hashmap.find(std::make_pair(i+1, j));
    if(it2 == hashmap.end()){
        bottom = uniquePaths_helper2(m, n, i+1, j, hashmap);
        hashmap[std::make_pair(i+1, j)] = bottom;
    }
    else
        bottom = hashmap[std::make_pair(i+1, j)];
    return right + bottom;
}

int uniquePaths2(int m, int n){
    std::map<std::pair<int, int>, int> hashmap;
    int paths = uniquePaths_helper2(m, n, 0, 0, hashmap);
    return paths;
}
/*******************************************/
// TODO: Tabulation

int main(){
	int m = 7, n = 3;
	std::cout << uniquePaths(m, n) << std::endl;
	std::cout << uniquePaths2(m, n) << std::endl;

	return 0;
}