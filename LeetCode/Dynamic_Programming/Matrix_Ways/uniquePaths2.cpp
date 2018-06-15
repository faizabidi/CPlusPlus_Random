// https://www.pramp.com/challenge/N5LYMbYzyOtbpovQoY7X

#include <iostream>
#include <map>

using namespace std;

int numOfPathsToDest_helper(int n, int i, int j, map<pair<int, int>, int> &hashmap){
  // Don't go diagonally up
  if(i > j)
    return 0;
  // Don't go out of the matrix
  if(i == n || j == n)
    return 0;
  
  // If you reach the destination
  if(i == n - 1 && j == n - 1)
    return 1;
  
  // Check if exists in the hashmap
  auto it = hashmap.find(make_pair(i, j));
  if(it != hashmap.end())
    return hashmap[make_pair(i, j)];
   
  // Else, calculate and add to hashmap
  int right = numOfPathsToDest_helper(n, i, j+1, hashmap);
  int top = numOfPathsToDest_helper(n, i+1, j, hashmap);
  hashmap[make_pair(i, j)] = right + top;
  
  return hashmap[make_pair(i, j)];
}

// Memoization
int numOfPathsToDest(int n){
  map<pair<int, int>, int> hashmap;
  int count = numOfPathsToDest_helper(n, 0, 0, hashmap);
  return count;
}

int main() {
  return 0;
}