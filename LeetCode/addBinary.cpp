#include <iostream>
#include <cmath>

class Solution {
public:
    int getSum(int a, int b) {
        std:: string binary_a = convert2Binary(a);
        std:: string binary_b = convert2Binary(b);
        makeSizeEqual(binary_a, binary_b);
        std::string sum = addBinary(binary_a, binary_b);
        int ans = convert2Decimal(sum);
        return ans;
    }
    int getSum(int a, int b){
        std:: string binary_a = convert2Binary(a);
        std:: string binary_b = convert2Binary(b);
        makeSizeEqual(binary_a, binary_b);
        std::string sum;
        for(int i = binary_a.size() - 1; i >= 0; i--){
            sum += binary_a ^ binary_b;
        }
    }
private:
    std::string convert2Binary(int a){
        std::string ans;
        while(a > 0){
            //std::cout << a % 2;
            ans += std::to_string(a % 2);
            a = a / 2;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    void makeSizeEqual(std::string &x_binary, std::string &y_binary){
        if(x_binary.size() > y_binary.size()){
            std::string y_binary_new;
            int size_diff = x_binary.size() - y_binary.size();
            
            for(int i = 0; i < size_diff; i++)
                y_binary_new += '0';
            y_binary_new += y_binary;
            y_binary = y_binary_new;
        }
        else if(y_binary.size() > x_binary.size()){
            std::string x_binary_new;
            int size_diff = y_binary.size() - x_binary.size();
            
            for(int i = 0; i < size_diff; i++)
                x_binary_new += '0';
            x_binary_new += x_binary;
            x_binary = x_binary_new;
        }
    }
    std::string addBinary(std::string a, std::string b){
        std::string sum;
        char carry = '0';
        for(int i = a.size() - 1; i >= 0; i--){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == '1')
                    sum += '1';
                else
                    sum += '0';
                carry = '1';
            }
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')){
                if(carry == '1'){
                    sum += '0';
                    carry = '1';
                }
                else{
                    sum += '1';
                    carry = '0';
                }
            }
            else if(a[i] == '0' && b[i] == '0'){
                if(carry == '1'){
                    sum += '1';
                    carry = '0';
                }
                else
                    sum += '0';
            }
        }
        if(carry == '1')
            sum += carry;
        std::reverse(sum.begin(), sum.end());
        return sum;
    }
    int convert2Decimal(std::string binary){
        int sum = 0;
        int size = binary.size() - 1;
        for(int i = 0; i < binary.size(); i++){
            if(binary[i] == '1')
                sum += pow(2, size);
            size--;
        }
        return sum;
    }
};

int main(){
    std::cout << "Enter two numbers:\n";
    int a, b;
    std::cin >> a >> b;
    Solution obj1;
    int sum = obj1.getSum(a, b);
    std::cout << sum << std::endl;

    return 0;
}