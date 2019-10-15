// https://leetcode.com/problems/largest-number/

// Time: O(nlogn)
class Solution{
public:
    string largestNumber(vector<int>& nums) {
        // Custom sort nums
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        bool flag = false;
        for(auto value : nums){
            if(value !=  0)
                flag = true;
            ans += to_string(value);
        }
        if(!flag)
            return "0";
        return ans;
    }
private:
    static bool compare(int a, int b){
        string combination1 = to_string(a) + to_string(b);
        string combination2 = to_string(b) + to_string(a);
        //long a_long = stol(combination1);
        //long b_long = stol(combination2);
        return combination1 > combination2;
        
    }
    void print(vector<int> array){
        for(auto value : array)
            cout << value << " ";
        cout << endl;
    }
};
