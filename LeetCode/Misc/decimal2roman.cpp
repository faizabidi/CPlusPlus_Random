#include <iostream>
#include <map>
#include <vector>

using namespace std;

int findClosest(int num){
    vector<int> array = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    // Do a binary search
    int low = 0, high = 12;
    while(low <= high){
        int mid = (low + high)/2;
        if(mid-1 >= 0 && num < array[mid] && num > array[mid-1])
            return array[mid-1];
        if(num == array[mid])
            return num;
        if(array[mid] < num)
            low = mid+1;
        else if(array[mid] > num)
            high = mid-1;
    }
    return 1000;
}

string decimal2roman(int num){
    map<int, string> hashmap = {
        {1,"I"},
        {4,"IV"},
        {5,"V"},
        {9,"IX"},
        {10,"X"},
        {40,"XL"},
        {50,"L"},
        {90,"XC"},
        {100,"C"},
        {400,"CD"},
        {500,"D"},
        {900,"CM"},
        {1000,"M"}
    };
    string roman = "";
    while(num > 0){
        // Look up in the hashmap
        auto it = hashmap.find(num);
        // If found
        if(it != hashmap.end()){
            roman += hashmap[num];
            num = 0;
        }
        else{
            // Look in the hashmap for a value closest to it
            int closestValue = findClosest(num);
            roman += hashmap[closestValue];
            num -= closestValue;
        }
    }
    return roman;
}

void testCases(){
    vector<int> testCases = {1,9,97,643,967};
    vector<string> expectedOutput = {"I", "IX", "XCVII", "DCXLIII", "CMLXVII"};
    for(int i = 0; i < testCases.size(); i++){
        if(decimal2roman(testCases[i]) != expectedOutput[i])
            cout << "Test case = " << testCases[i] << ". FAILED\n";
        else
            cout << "Test case = " << testCases[i] << ". PASSED\n";
    }
}

int main(){
    testCases();

    return 0;
}
