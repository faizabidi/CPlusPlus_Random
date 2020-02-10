#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Trie{
public:
    struct TrieNode{
        map<char, TrieNode*> children;
        bool endOfWord;
        // Default constructor
        TrieNode(){
            children = {};
            endOfWord = false;
        }
    };
    /** Initialize your data structure here. */
    Trie(){
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word){
        TrieNode *temp = root;
        for(int i = 0; i < word.size(); i++){
            // If not a child
            if(!temp->children.count(word[i]))
                temp->children[word[i]] = new TrieNode();
            temp = temp->children[word[i]];
        }
        // When we reach at the end, mark that endOfWord as true
        temp->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word){
        TrieNode *temp = root;
        for(int i = 0; i < word.size(); i++){
            // Check if this character exists in the map
            if(temp->children.count(word[i]))
                temp = temp->children[word[i]];
            else
                return false;
        }
        if(temp->endOfWord)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix){
        TrieNode *temp = root;
        for(int i = 0; i < prefix.size(); i++){
            // Check if this character exists in the map
            if(temp->children.count(prefix[i]))
                temp = temp->children[prefix[i]];
            else
                return false;
        }
        return true;
    }
private:
    TrieNode *root;
};

int main(){
    Trie obj1;
    obj1.insert("abc");
    obj1.insert("abcd");
    obj1.insert("def");

    if(obj1.search("abcde"))
        cout << "abcde exists in the trie\n";
    else
        cout << "abcde does not exist in the trie\n";

    if(obj1.search("def"))
        cout << "def exists in the trie\n";
    else
        cout << "def does not exist in the trie\n";

    if(obj1.startsWith("ab"))
        cout << "ab prefix exists in the trie\n";
    else
        cout << "ab prefix does not exist in the trie\n";


    return 0;
}