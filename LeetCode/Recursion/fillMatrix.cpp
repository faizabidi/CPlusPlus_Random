// https://leetcode.com/problems/flood-fill/


// Time complexity: O(n*m) where n and m are rows and cols
// Space complexity: O(n*m) where n and m are rows and cols
class Solution{
public:
    void floodFillHelper(vector<vector<int>> &image, int sr, int sc, int newColor, map<pair<int, int>, bool> &visited){
        // Base conditions
        if(sr < 0 || sr == image.size())
            return;
        if(sc < 0 || sc == image[0].size())
            return;
        
        int origValue = image[sr][sc];
        image[sr][sc] = newColor;
        visited[make_pair(sr, sc)] = true;
        
        // Go up
        if(sr-1 >=0 && image[sr-1][sc] == origValue){
            auto it = visited.find(make_pair(sr-1, sc));
            if(it == visited.end()){
                visited[make_pair(sr-1, sc)] = true;
                floodFillHelper(image, sr-1, sc, newColor, visited);
            }
        }   
        
        // Go down
        if(sr+1 < image.size() && image[sr+1][sc] == origValue){
            auto it = visited.find(make_pair(sr+1, sc));
            if(it == visited.end()){
                visited[make_pair(sr+1, sc)] = true;
                floodFillHelper(image, sr+1, sc, newColor, visited);
            }
        }
        
        // Go left
        if(sc-1 >=0 && image[sr][sc-1] == origValue){
            auto it = visited.find(make_pair(sr, sc-1));
            if(it == visited.end()){
                visited[make_pair(sr, sc-1)] = true;
                floodFillHelper(image, sr, sc-1, newColor, visited);
            }
        }
        
        // Go right
        if(sc+1 < image[0].size() && image[sr][sc+1] == origValue){
            auto it = visited.find(make_pair(sr, sc+1));
            if(it == visited.end()){
                visited[make_pair(sr, sc+1)] = true;
                floodFillHelper(image, sr, sc+1, newColor, visited);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
        map<pair<int, int>, bool> visited;
        floodFillHelper(image, sr, sc, newColor, visited);
        return image;
    }
};
