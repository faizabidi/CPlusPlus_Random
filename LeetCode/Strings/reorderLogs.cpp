// https://leetcode.com/problems/reorder-log-files/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(string str1, string str2){
        // Find the index of the first space
        int i = str1.find(' ');
        int j = str2.find(' ');
        // If strings are same, sort based on identifiers
        if(str1.substr(i+1) == str2.substr(j+1))
            return str1.substr(0, i-1) < str2.substr(0, j-1);
        // Else, sort based on strings
        return str1.substr(i+1) < str2.substr(j+1);
    }
    vector<string> reorderLogFiles(vector<string>& logs){
        vector<string> digit_logs, letter_logs;
        for(int i = 0; i < logs.size(); i++){
            int index = logs[i].find(' ');
            if(!isdigit(logs[i][index+1]))
                letter_logs.push_back(logs[i]);
            else
                digit_logs.push_back(logs[i]);
        }
        sort(letter_logs.begin(), letter_logs.end(), compare);
        letter_logs.insert(letter_logs.end(),digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
    void printVector(vector<string> array){
        for(auto value : array)
            cout << value << endl;
    }
};

int main(){
    Solution obj1;
    vector<string> logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    cout << "Before soting\n\n";
    obj1.printVector(logs);
    vector<string> sortedLogs = obj1.reorderLogFiles(logs);
    cout << "\nAfter sorting\n\n";
    obj1.printVector(sortedLogs);
    return 0;
}
