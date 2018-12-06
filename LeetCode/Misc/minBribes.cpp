// https://www.hackerrank.com/challenges/new-year-chaos/problem

#include <iostream>
#include <vector>
using namespace std;


// O(n) space and O(n^2) time
int minimumBribes(vector<int> q){
    int count = 0;
    vector<int> normalQ(q.size());
    // Fill it up 
    for(int i = 0; i < q.size(); i++)
        normalQ[i] = i+1;
    // Start comparing with the modified q
    for(int i = 0; i < q.size(); i++){
        if(q[i] != normalQ[i]){
            // Go to position from where to start swapping
            // Find it in normalQ
            auto it = find(normalQ.begin()+i, normalQ.end(), q[i]);
            int position = it - normalQ.begin();
            int max_count = 0;
            while(max_count < 2 && q[i] != normalQ[i]){
                swap(normalQ[position], normalQ[position-1]);
                max_count++, position--, count++;
            }
            // If the values are still not equal then combination not possible
            if(q[i] != normalQ[i]){
                cout << "Too chaotic\n";
                return -1;
            }
        }
    }
    return count;
}

// O(n) time and O(1) space
int minimumBribes2(std::vector<int> array){
	int count = 0;
	// Scan from end to the beginning
	for(int i = array.size() - 1; i >= 0; i--){
		if(array[i] != i+1){
			// The element at this position would either be on i-1 or i-2 position
			// If it's on i-1
			if(array[i-1] == i+1){
				swap(array[i], array[i-1]);
				count++;
			}
			else if(array[i-2] == i+1){
				swap(array[i-2], array[i-1]);
				swap(array[i-1], array[i]);
				count += 2;
			}
			else{
				cout << "Too chaotic\n";
				return -1;
			}
		}
	}
	return count;
}

int main(){
	vector<int> array = {1,2,5,3,7,8,6,4};
	cout << minimumBribes2(array) << endl;

	return 0;
}