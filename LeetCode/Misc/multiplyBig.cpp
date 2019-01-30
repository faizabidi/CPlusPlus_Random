#include <vector>
#include <iostream>

using namespace std;

string add(string n1, string n2){
    string ans = "";
    int carry = 0;
    int i = n1.size() - 1, j = n2.size() - 1;
    while(i >= 0 && j >= 0){
        int sum = (n1[i] - '0') + (n2[j] - '0') + carry;
        if (sum > 9){
            carry = 1;
            ans += to_string(carry % 10);
        }
        else{
            ans += to_string(sum);
            carry = 0;
        }
        i--, j--;
    }
    while(i >= 0){
        int sum = (n1[i] - '0') + carry;
        if (sum > 9){
            carry = 1;
            ans += to_string(carry % 10);
        }
        else{
            ans += to_string(sum);
            carry = 0;
        }
        i--;
    }
    while(j >= 0){
        int sum = (n2[j] - '0') + carry;
        if (sum > 9){
            carry = 1;
            ans += to_string(carry % 10);
        }
        else{
            ans += to_string(sum);
            carry = 0;
        }
        j--;
    }
    if(carry != 0)
        ans += to_string(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string n1, string n2){
    string ans = "";
    vector<string> sumObtained;
    for(int i = n2.size() - 1; i >= 0; i--){
        int carry = 0;
        string currProduct = "";
        for(int j = n1.size() - 1; j >= 0; j--){
            int temp = (n2[i] - '0') * (n1[j] - '0') + carry;
            if(temp > 9){
                carry = temp / 10;
                currProduct += to_string(temp % 10);
            }
            else{
                carry = 0;
                currProduct += to_string(temp);
            }
        }
        if(carry != 0)
            currProduct += to_string(carry);
        reverse(currProduct.begin(), currProduct.end());
        sumObtained.push_back(currProduct);
    }
    // Add the two numbers in sumObtained
    ans = add(sumObtained[0], sumObtained[1]);
    return ans;
}

int main() {
    cout << multiply("10", "5") << endl; //100000000000
    return 0;
}
