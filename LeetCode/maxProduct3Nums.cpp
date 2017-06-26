#include <iostream>
#include <vector>

class Solution{
public:
    void printVector(std::vector<int> array){
        for(int i = 0; i < array.size(); i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    }

    int maximumProduct(std::vector<int> nums){
        std::sort(nums.begin(), nums.end());
        int j = -1;
        int size = nums.size();

        // Find the index where the negative numbers start in the array
        for(int i = 0; i < size; i++){
            if(nums[i] < 0)
                j++;
            else
                break;
        }

        // All negative 
        if(j == size - 1)
            return nums[j] * nums[j - 1] * nums[j - 2];

        // Check if there are more than 2 positive numbers and still the product of two negative numbers is more
        if(nums[0] * nums[1] > nums[size - 3] * nums[size - 2])
            return nums[0] * nums[1] * nums[size - 1];
        
        else
            return nums[size - 3] * nums[size - 2] * nums[size - 1];
    }
};

int main(){
    Solution obj1;
    //std::vector<int> array = {-4,-3,-2,-1,60};
    std::vector<int> array = {722,634,-504,-379,163,-613,-842,-578,750,951,-158,30,-238,-392,-487,-797,-157,-374,999,-5,-521,-879,-858,382,626,803,-347,903,-205,57,-342,186,-736,17,83,726,-960,343,-984,937,-758,-122,577,-595,-544,-559,903,-183,192,825,368,-674,57,-959,884,29,-681,-339,582,969,-95,-455,-275,205,-548,79,258,35,233,203,20,-936,878,-868,-458,-882,867,-664,-892,-687,322,844,-745,447,-909,-586,69,-88,88,445,-553,-666,130,-640,-918,-7,-420,-368,250,-786}; // Ans = 943695360
    std::cout << obj1.maximumProduct(array);

    return 0;
}