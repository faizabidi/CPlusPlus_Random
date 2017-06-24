#include <iostream>
#include <vector>

class Solution{
public:

	static bool compare(int a, int b){
	    std::string a_str = std::to_string(a);
	    std::string b_str = std::to_string(b);
	    
	    int sum_a = 0, sum_b = 0;
	    
	    for(int i = 0; i < a_str.size(); i++)
	        sum_a += (a_str[i] - '0');
	    
	    for(int i = 0; i < b_str.size(); i++)
	        sum_b += (b_str[i] - '0');
	    
	    if(sum_a == sum_b)
	        return a < b;
	    else
	        return sum_a < sum_b;
	}
	        
	std::vector<int> digitRootSort(std::vector<int> a){
	    std::sort(a.begin(), a.end(), compare);
	    return a;
	}
};


int main(){
	Solution obj1;

	std::vector<int> array = {13, 99, 4, 20, 7, 36};
	array = obj1.digitRootSort(array);

	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	return 0;
}