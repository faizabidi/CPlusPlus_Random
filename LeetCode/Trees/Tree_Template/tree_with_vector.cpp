#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

struct Movies{
    string name;
    string genre;
};

struct TreeNode{
    int year;
    vector<Movies> movies_and_genre;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createNode(int year, Movies movie){
    TreeNode *newNode = new TreeNode;
    newNode->left = NULL, newNode->right = NULL;
    newNode->year = year;
    newNode->movies_and_genre.push_back(movie);
    return newNode;
}

TreeNode *addNode(TreeNode *root, int year, Movies movie){
    if(!root){
        root = createNode(year, movie);
        return root;
    }
    // Find where to insert node
    TreeNode *curr = root, *prev = NULL;
    while(curr){
        prev = curr;
        if(curr->year > year)
            curr = curr->left;
        else if(curr->year < year)
            curr = curr->right;
        else
            break;
    }
    if(prev->year > year){
        TreeNode *newNode = createNode(year, movie);
        prev->left = newNode;
    }
    else if(prev->year < year){
        TreeNode *newNode = createNode(year, movie);
        prev->right = newNode;
    }
    else
        prev->movies_and_genre.push_back(movie);
    return root;
}

// In-order
void DFS(TreeNode *root){
    if(!root)
        return;
    if(root->left)
        DFS(root->left);
    cout << root->year << endl;
    for(int i = 0; i < root->movies_and_genre.size(); i++)
        cout << root->movies_and_genre[i].name << ", " << root->movies_and_genre[i].genre << endl;
    if(root->right)
        DFS(root->right);
}

// Tokenize based on comma
vector<string> tokenize(string str){
    vector<string> tokens;
    stringstream ss(str);
    char delimeter = ',';
    string buffer;
    while(getline(ss, buffer, delimeter))
        tokens.push_back(buffer);
    return tokens;
}

// Read data from file
vector<vector<string>> getFileContents(string fileName){
    fstream inputFile(fileName);
    string buffer;
    vector<vector<string>> fileContents;
    while(getline(inputFile, buffer)){
        vector<string> temp = tokenize(buffer);
        fileContents.push_back(temp);
    }
    return fileContents;
}

int main(){
    string fileName;
    cout << "Enter the filename: ";
    cin >> fileName;
    vector<vector<string>> fileContents = getFileContents(fileName);
    TreeNode *root = NULL;
    for(int i = 0; i < fileContents.size(); i++){
        vector<string> curr_row = fileContents[i];
        int year = stoi(curr_row[2]);
        string name = curr_row[0];
        string genre = curr_row[1];
        Movies movie = {name, genre};
        root = addNode(root, year, movie);
    }
    DFS(root);
    return 0;
}
