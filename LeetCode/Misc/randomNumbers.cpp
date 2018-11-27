#include <iostream>
#include <ctime>

using namespace std;

// Generate random numbers between low and high
void generateNumbers(int low, int high){
    for(int i = low; i <= high; i++){
        cout << rand() % 10 << endl;
    }
}

int main(){
    // Seed with time to get different random numbers on each run
    srand(time(NULL));
    generateNumbers(0, 10);

    return 0;
}