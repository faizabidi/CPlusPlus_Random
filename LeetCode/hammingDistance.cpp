// https://leetcode.com/problems/hamming-distance/#/description

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
    int hammingDistance(int x, int y){
        int ans = 0;
        std::string x_binary = convert2binary(x);
        std::string y_binary = convert2binary(y);
        // Add zeros if needed
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
        // Compare the two
        for(int i = 0; i < x_binary.size(); i++){
            if(x_binary[i] != y_binary[i])
                ans++;
        }
        return ans;
    }
};