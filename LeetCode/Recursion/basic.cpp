#include <iostream>
#include <string>
#include <vector>

// Non-recursive fibonacci
int fibonacci(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    int first = 0;
    int second = 1;
    int third;
    for(int i = 1; i < n; i++){
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

// Recursive fibonacci
int fibonacci2(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    else
        return fibonacci2(n -1) + fibonacci2(n - 2);
}

// Recursive - n to 1
void printNumbers1(int n){
    if(n == 0)
        return;
    if(n > 0){
        std::cout << n << std::endl;
        printNumbers1(n - 1);
    }
}

// Recursive - 1 to n
void printNumbers2(int n){
    if(n > 1)
        printNumbers2(n - 1);
    std::cout << n << std::endl;
}

// Recursive
int factorial(int n){
    if(n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(){
    int n;
    std::cin >> n;
    printNumbers2(n);
    
    std::cout << factorial(n) << std::endl;

    std::cout << fibonacci2(n) << std::endl;

	return 0;
}