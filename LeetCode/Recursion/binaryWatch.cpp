// https://leetcode.com/problems/binary-watch/description/
// Not entirely sure on the time and space complexity

class Solution {
public:
    void printVector(vector<vector<int>> combinations){
        for(int i = 0; i < combinations.size(); i++){
            for(int j = 0; j < combinations[i].size(); j++)
                cout << combinations[i][j] << " ";
            cout << endl;
        }
    }
    // Create combinations of time - hours and minutes
    void findCombinations(int num, int flip, int i, vector<int> time, vector<vector<int>> &combinations){
        // Base cases
        if(flip == num){
            combinations.push_back(time);
            return;
        }
        if(i == 10)
            return;
        // Include
        time[i] = 1;
        findCombinations(num, flip+1, i+1, time, combinations);
        // Exclude
        time[i] = 0;
        findCombinations(num, flip, i+1, time, combinations);
    }
    // Convert combinations into time
    string convertTime(vector<int> time){
        int hours = 0, minutes = 0;
        string convertedTime = "";
        for(int i = 0; i < 4; i++){
            if(time[i] == 1)
                hours += pow(2,3-i);
        }
        // Check if valid hours
        if(hours > 11)
            return "";
        for(int i = 4; i < time.size(); i++){
            if(time[i] == 1)
                minutes += pow(2,5-i+4);
        }
        // Check if valid minutes
        if(minutes > 59)
            return "";
        convertedTime += to_string(hours) + ":";
        if(minutes < 10){
            convertedTime += '0' + to_string(minutes);
            return convertedTime;
        }
        convertedTime += to_string(minutes);
        return convertedTime;
    }
    // Main function
    vector<string> readBinaryWatch(int num){
        vector<string> ans;
        vector<int> time(10, 0); // 0 means off, 1 means on
        vector<vector<int>> combinations;
        // Find all possible combinations. Some will be invalid
        findCombinations(num, 0, 0, time, combinations);
        //cout << "All combinations are\n";
        //printVector(combinations);
        // Convert combinations into time
        for(int i = 0; i < combinations.size(); i++){
            vector<int> temp = combinations[i];
            if(convertTime(temp).size() != 0)
                ans.push_back(convertTime(temp));
        }
        return ans;
    }
};
