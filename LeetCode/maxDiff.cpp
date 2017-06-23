// https://leetcode.com/contest/leetcode-weekly-contest-37/problems/maximum-distance-in-arrays/

class Solution{
public:
    void print(vector<int> array){
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        std::cout << std::endl;
    }
    int maxDistance(vector<vector<int>> &arrays){
        vector<int> smallest, largest;
        int ans = 0;
        
        // Store smallest and largest
        for(int i = 0; i < arrays.size(); i++){
            vector<int> temp = arrays[i];
            smallest.push_back(temp[0]);
            largest.push_back(temp[temp.size() - 1]);
        }
        
        //print(smallest);
        //print(largest);
        
        for(int i = 0; i < smallest.size(); i++){
            for(int j = 0; j < smallest.size(); j++){
                int diff = std::abs(smallest[i] - largest[j]);
                //std::cout << "Diff = " << diff << endl;
                if(diff > ans && i != j)
                    ans = diff;
                //std::cout << "Ans = " << ans << endl;
            }
        }
        // Find the max difference between the smallest and the largest array
        //int smallest_index = std::min_element(smallest.begin(), smallest.end());
        //int min = *std::min_element(smallest.begin(), smallest.end());
        
        //int largest_index = std::max_element(largest.begin(), largest.end());
        //int max = *std::max_element(largest.begin(), largest.end());

        
        /*for(int i = 0; i < arrays.size(); i++){
            vector<int> temp1 = arrays[i];
            for(int j = i + 1; j < arrays.size(); j++){
                vector<int> temp2 = arrays[j];
                //Compare the two arrays
                int min1 = temp1[0], min2 = temp2[0];
                int max1 = temp1[temp1.size() - 1], max2 = temp2[temp2.size() - 1];
                ans = std::max(std::max(std::abs(max1 - min2), std::abs(max2 - min1)), ans);
            }
        }*/
        
        return ans;
    }
};