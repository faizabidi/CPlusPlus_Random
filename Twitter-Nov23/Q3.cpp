// https://www.hackerrank.com/tests/2mqjt0bagl4/questions/7jld8b9cf3e

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// THIS IS THE ONLY FUNCTION THAT NEEDED TO BE COMPLETED. REST OF ALL THE CODE WAS PROVIDED.
// O(nxn)
int maxLength(vector <int> a, int k){
	int ans = 0;
	// If there are no elements
	if(a.size() == 0)
		return 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] <= k){
			int count = 1, temp_sum = a[i];
			int j = i + 1;
			// Keep going forward till <= k
			while(temp_sum <= k && j < a.size()){
				temp_sum += a[j];
				if(temp_sum <= k)
					count++;
				j++;
			}
			if(count > ans)
				ans = count;
			// If you actually reach the end of string while doing this then it means that there can be no longer combination to be found		
			if(j == a.size() - 1 && count > ans)
				return ans;
		}
	}
	return ans;
}

// O(n) solution
int maxLength2(vector <int> a, int k){
	int ans = 0, sum = 0, index = 0, count = 0;

	for(int i = 0; i < a.size(); i++){
		sum += a[i];
		if(sum <= k)
			count++;
		if(sum > k){
			sum -= a[index];
			index++;
		}
		ans = std::max(ans, count);
	}
	return ans;
}

int main() {
    int res;
    
    int _a_size = 0;
    cin >> _a_size;
  
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    int _k;
    cin >> _k;
    
    
    res = maxLength2(_a, _k);
    cout << res << endl;
    
    return 0;
}
