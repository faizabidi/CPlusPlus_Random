// https://leetcode.com/problems/all-paths-from-source-to-target/description/


// O(2^n * nxn) time and O(2^n * n) space
class Solution {
public:
    void dfs(vector<vector<int>> graph, int src, int dest, vector<int> temp, vector<vector<int>> &allPaths){
        // Base cases
        if(src == dest){
            temp.push_back(dest);
            allPaths.push_back(temp);
            return;
        }
        // Check all the neighbours of source
        temp.push_back(src);
        for(int i = 0; i < graph[src].size(); i++)
            dfs(graph, graph[src][i], dest, temp, allPaths);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        if(graph.size() == 0)
            return {{}};
        int source = 0, destination = graph.size() - 1;
        vector<vector<int>> allPaths;
        dfs(graph, source, destination, {}, allPaths);
        return allPaths;
    }
};