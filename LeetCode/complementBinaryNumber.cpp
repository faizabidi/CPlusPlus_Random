class Solution {
private:
    std::string convert2binary(int x){
        std::string binary;
        while(x > 0){
            binary += std::to_string(x % 2);
            x = x / 2;
        }
        // Reverse it
        std::reverse(binary.begin(), binary.end());
        return binary;
    }
public:
    int findComplement(int num) {
        std::string binary = convert2binary(num);
        int ans = 0;
        int size = binary.size() - 1;
        for(int i = 0; i < binary.size(); i++){
            if(binary[i] == '0')
                ans += 1 * pow(2, size);
            size--;
        }
        return ans;
    }
};