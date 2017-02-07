#include <iostream>
#include <vector>


// O(nxn)
std::vector<int> array_left_rotation2(std::vector<int> a, int n, int k){
    
    // We need to swap k times to get the answer
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n - 1; j++)
            std::swap(a[j], a[j+1]);
    }   

    return a;
}

// Better solution
std::vector<int> array_left_rotation(std::vector<int> a, int n, int k){
    std::vector<int> result;

    // Find the index from where to start the values
    int starting_index = k % n;

    //std::cout << starting_index << std::endl; 

    // Store all elements from starting index till the end
    for(int i = starting_index; i < n; i++)
        result.push_back(a[i]);

    // Add the rest of the elements
    for(int i = 0; i < starting_index; i++)
        result.push_back(a[i]);

    return result;
}


int main(){
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for(int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> output = array_left_rotation(a, n, k);
    
    for(int i = 0; i < n;i++)
        std::cout << output[i] << " ";

    std::cout << std::endl;
    return 0;
}