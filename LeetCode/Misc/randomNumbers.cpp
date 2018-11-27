#include <iostream>
#include <ctime>

using namespace std;

// Generate random numbers between low and high
void generateNumbers(int low, int high){
    for(int i = low; i <= high; i++){
        cout << (rand() % (high - low + 1)) + low << endl;
    }
}

int main(){
    // Seed with time to get different random numbers on each run
    srand(time(NULL));
    generateNumbers(95, 100);

    return 0;
}
