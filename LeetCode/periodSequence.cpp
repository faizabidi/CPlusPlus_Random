// https://codefights.com/skill-test/mX38GyNcEyQBvRQjh

#include <iostream>
#include <vector>

void printVector(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int periodicSequence(int s0, int a, int b, int m){
    std::vector<int> sequence;
    // Push s0
    sequence.push_back(s0);
    int repeat_begin = 0;
    int index = 0;
    int index2 = 0;

    while(1){
    	int num = (a * s0 + b) % m;
    	index2++;
    	// If not in sequence, add it
    	if(std::find(sequence.begin(), sequence.end(), num) == sequence.end())
    		sequence.push_back(num);
    	else{
    		// Add it and break
    		repeat_begin = num;
    		break;
    	}
    	s0 = num;
    	//std::cout << "Hello from while\n";
    }
    //std::cout << "Hello1\n";
    // Find the index of from where the repetition begins
    //printVector(sequence);
    while(sequence[index] != repeat_begin)
    	index++;

    //std::cout << "Hello2\n";
    // Save the new sequence in a vector
    std::vector<int> ans;
    for(int i = index; i < sequence.size(); i++)
    	ans.push_back(sequence[i]);

    //std::cout << "Hello3\n";
    //printVector(ans);
    std::vector<int> ans2;

    for(int i = 0; i < ans.size(); i++){
    	// Value of the index to be found
    	int index = i + ans[i];
    	// Value of that index will be index % size of ans
    	int future_ans = ans[index % ans.size()];
    	if(ans[i] == future_ans && ans[i] != 0)
    		ans2.push_back(ans[i]);
    }
    //std::cout << "Hello4\n";
    std::sort(ans2.begin(), ans2.end());
    //std::cout << "Hello5\n";
    //printVector(ans2);
    //std::cout << "Hello6\n";
    //if(ans2.size() < 1)
    //	return 0;
    //return ans2.front();
    int index3 = 0;
    while(sequence[index3] != repeat_begin)
    	index3++;
    return index2 - index3;
}


int main(){

	//std::cout << periodicSequence(1, 2, 3, 5);
	//std::cout << periodicSequence(11, 2, 6, 12);
	std::cout << periodicSequence(2, 3, 4, 5);
	//std::cout << periodicSequence(99, 100, 100, 100);
	//std::cout << periodicSequence(99, 100, 100, 100)
	return 0;
}