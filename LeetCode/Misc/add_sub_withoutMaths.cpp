
// https://leetcode.com/problems/sum-of-two-integers/description/

// https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/

#include <iostream>

int getSum(int a, int b){
    while(b != 0){
        // Do AND to get the carry
        int carry = a&b;
        // Do xor to get the sum
        a = a^b;
        // Shift the carry by 1 bit
        b = (carry << 1);
    }
    return a;
}

int getSub(int a, int b){
    while(b != 0){
            // Do AND to get the borrow
            int borrow = ~a&b;
            // Do xor to get the diff
            a = a^b;
            // Shift the borrow by 1 bit
            b = (borrow << 1);
        }
    return a;
}

int main(){
    int a = 10;
    int b = 7;
    
    std::cout << getSum(a, b) << std::endl;
    std::cout << getSub(a, b) << std::endl;

    return 0;
}