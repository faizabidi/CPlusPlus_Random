// https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    // Tokenize a string based on delimeter
    vector<string> tokenize(string str, char delimeter){
        stringstream ss(str);
        vector<string> tokens;
        string buffer;
        while(getline(ss, buffer, delimeter))
            tokens.push_back(buffer);
        return tokens;
    }
    // Filter a string 
    string filter(string str){
        string filtered_string = "";
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '+')
                break;
            if(str[i] == '.')
                continue;
            filtered_string += str[i];
        }
        return filtered_string;
    }
    int numUniqueEmails(vector<string>& emails){
        int count = 0;
        unordered_map<string, unordered_set<string>> hashmap;
        // Create a hashmap of unique email address by their domain name
        for(int i = 0; i < emails.size(); i++){
            vector<string> emailAddress = tokenize(emails[i], '@');
            hashmap[emailAddress[1]].insert(filter(emailAddress[0]));
        }
        // Count values in hashmap for every key
        for(auto it = hashmap.begin(); it != hashmap.end(); it++)
            count += (it->second).size();
        return count;
    }
};