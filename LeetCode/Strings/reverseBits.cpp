// https://leetcode.com/problems/reverse-bits/description/

#include <cmath>
#include <iostream>
using namespace std;

string dec2bin(uint32_t n){
    string binary_num = "";
    while(n > 1){
        uint32_t remainder = n % 2;
        binary_num += remainder + '0';
        n /= 2;
    }
    if(n == 1)
        binary_num += 1 + '0';
    // Since it is a 32 bit integer, let's add extra zeros at the end
    uint32_t zeros_needed = 32 - binary_num.size();
    for(uint32_t i = 0; i < zeros_needed; i++)
    	binary_num += 0 + '0';
    reverse(binary_num.begin(), binary_num.end());
    return binary_num;
}
uint32_t bin2dec(string binary){
    uint32_t ans = 0;
    uint32_t size = binary.size() - 1;
    uint32_t power = size;
    for(uint32_t i = 0; i <= size; i++){
        ans += ((binary[i] - '0')*pow(2, power));
        power--;
    }
    return ans;
}

void reverseBits(uint32_t n){
    string binary_num = dec2bin(n);
    cout << "Binary is " << binary_num << endl;
    cout << "Decimal is " << bin2dec(binary_num) << endl;
    reverse(binary_num.begin(), binary_num.end());
    cout << "Reverse binary is " << binary_num << endl;
    cout << "Decimal is " << bin2dec(binary_num) << endl;
}

int main(){
	uint32_t num = 2147483648;
	reverseBits(num);
	return 0;
}