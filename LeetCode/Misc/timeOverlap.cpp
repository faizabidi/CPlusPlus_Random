// https://www.pramp.com/challenge/3QnxW6xoPLTNl5jX5Lg1

#include <iostream>
#include <vector>

using namespace std;


// O(n+m) time and O(1) space
vector<int> meetingPlanner(const vector<vector<int>>& slotsA, 
                                const vector<vector<int>>& slotsB, int dur){
  
  int i = 0, j = 0;
  while(i < slotsA.size() && j < slotsB.size()){
    vector<int> A = slotsA[i];
    vector<int> B = slotsB[j];
    int start = max(A[0], B[0]);
    int end = min(A[1], B[1]);
    
    if(start + dur <= end)
      return {start, start+dur};
    
    if(A[1] > B[1])
      j++;
    else
      i++;
  }
  return {};
}

int main() {
  return 0;
}