// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    // Function to check if it's a mutation
    bool check(std::string str1, std::string str2){
        int count = 0;
        if(str1 == str2)
            return false;
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] != str2[i])
                count++;
        }
        if(count > 1)
            return false;
        return true;
    }

    int minMutation(string start, string end, vector <string> bank){
        int distance = 0;
        std::queue<std::string> q;
        q.push(start);
        bool flag = false;

        std::map<std::string, bool> visited;
        // Initialize all as false
        for(int i = 0; i < bank.size(); i++)
            visited[bank[i]] = false;

        // Mark first string as visited
        visited[start] = true;

        while(!q.empty()){
            int size = q.size();
            distance++;
            while(size > 0){
                std::string temp = q.front();
                q.pop();
                for(int i = 0; i < bank.size(); i++){
                    // If it's a mutation that has not already been added to the queue
                    if(check(temp, bank[i]) && !visited[bank[i]]){
                        q.push(bank[i]);
                        visited[bank[i]] = true;
                        // If END already found, return the distance
                        if(bank[i] == end){
                            flag = true;
                            return distance;
                        }
                    }
                }
                size--;
            }
        }
        return -1;
    }
};

