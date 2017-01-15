// https://www.hackerrank.com/challenges/30-scope

#include <iostream>
#include <vector>

class Difference{
private:
   	std::vector<int> elements;
public:
	Difference(std::vector<int> array){
		elements = array;
		//for(int i = 0; i < array.size(); i++)
		//	elements.push_back(array[i]);
	}
	int computeDifference(){
		int max = INT_MIN;
		std::sort(elements.begin(), elements.end());
		max = elements.back() - elements[0];
		return max;
	}

}; // End of Difference class

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> array;
    
    for(int i = 0; i < N; i++){
        int e;
        std::cin >> e;
        array.push_back(e);
    }
    
    Difference d(array);
    
    d.computeDifference();
    
    std::cout << d.computeDifference();
    
    return 0;
}