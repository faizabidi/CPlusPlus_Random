// https://leetcode.com/contest/weekly-contest-94/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // The value of speed would be between low and high
        int low = 0, finalSpeed = INT_MAX;
        int high = *std::max_element(piles.begin(), piles.end());
        // Binary search
        while(low <= high){
            int speed = (low + high) / 2;
            // Make sure speed is not zero
            if(speed == 0)
                return 1;
            int sum = 0;
            // Find out if this speed will work for the monkey
            for(int i = 0; i < piles.size(); i++)
                // We use ceil because we want 1.2 = 2
                sum += std::ceil(double(piles[i]) / speed);
            // We want sum to remain less than equal to H
            if(sum <= H && speed < finalSpeed)
                finalSpeed = speed;   
            // Increase speed
            if(sum > H)
                low = speed + 1;
            // Decrease speed
            else
                high = speed - 1;
        }
        return finalSpeed;
    }
};