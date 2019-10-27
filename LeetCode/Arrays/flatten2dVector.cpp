// https://leetcode.com/problems/flatten-2d-vector/

class Vector2D{
public:
    // Default constructor
    Vector2D(vector<vector<int>>& v){
        matrix = v;
        i = 0, j = -1;
    }
    
    int next(){
        j++;
        // If reached end of the row, reset column and increment row till we don't
        // find the next non-emty array
        if(j == matrix[i].size()){
            int k = i+1;
            while(matrix[k].size() <= 0)
                k++;
            i = k, j = 0;
        }
        // Return the current value
        return matrix[i][j];
    }
    bool hasNext(){
        // Edge case
        if(matrix.size() == 0)
            return false;
        // Check the same row
        if(j+1 < matrix[i].size())
            return true;
        // Check if there exists another non-empty vector in the matrix
        int k = i+1;
        while(k < matrix.size() && matrix[k].size() == 0)
            k++;
        if(k < matrix.size())
            return true;
        // Else, return false
        return false;
    }
private:
    int i, j;
    unordered_set<vector<int>> hashset;
    vector<vector<int>> matrix;
    // Print matrix
    void print(vector<vector<int>> matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(auto value : matrix[i])
                cout << value << " ";
            cout << endl;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */