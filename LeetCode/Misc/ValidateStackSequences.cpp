// https://leetcode.com/contest/weekly-contest-112/problems/validate-stack-sequences/

class Solution {
public:
    void print(stack<int> s){
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    // O(n+m) time and O(n) space
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        int j = 0;
        stack<int> s;
        for(int i = 0; i < pushed.size(); i++){
            //cout << "j = " << j << endl;
            // Check if the item in the popped stack can be used
            while(!s.empty() && popped[j] == s.top()){
                    //cout << "Popping from stack " << s.top() << endl;
                    s.pop();
                    j++;
                    //print(s);
            }
            //cout << "Pushing to stack - " << pushed[i] << endl;
            s.push(pushed[i]);
            //print(s);
        }
        // Once all pushed items are done, check popped items
        if(j != popped.size() - 1){
            //cout << "Items still left the popped array\n";
            while(j != popped.size()){
                //cout << "Stack is \n";
                //print(s);
                cout << popped[j] << "," << s.top() << endl;
                if(!s.empty() && s.top() != popped[j])
                    return false;
                else{
                    //cout << "Popping from stack " << s.top() << endl;
                    s.pop();
                }
                j++;
            }
        }
        return true;
    }
};