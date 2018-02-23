/*
Given two arrays of integers of size M and N, write a function that returns the intersection of the two arrays in O(M + N) time. Do not use built in intersection functions or libraries
*/

#include <iostream>
#include <vector>
#include <map>

void printVector(std::vector<int> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

std::vector<int> find_intersection(std::vector<int> array1, 
    std::vector<int> array2){

    std::vector<int> intersection;
    std::map<int, int> map1, map2;

    
    // Store in hashmap
    for(int i = 0; i < array1.size(); i++)
        map1[array1[i]]++;
    for(int i = 0; i < array2.size(); i++)
        map2[array2[i]]++;

    std::map<int, int>::iterator it;

    for(it = map1.begin(); it != map1.end(); it++){
        if(map2.find(it->first) != map2.end())
            intersection.push_back(it->first);
    }

    return intersection;
}

int main(){
    std::vector<int> array1 = {1, 2, 6, 3, 3, 90, 78, 0};
    std::vector<int> array2 = {3, 4, 0, 6, 90};

    std::vector<int> intersection = find_intersection(array1, array2);

    printVector(intersection);

    return 0;
}
