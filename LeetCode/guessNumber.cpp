// https://leetcode.com/problems/guess-number-higher-or-lower/

int guess(int num);

class Solution {
public:
    int guessNumber(int N){
        int low = 1;
        std::cout << "N = " << N << std::endl;
        while(low <= N){
            long mid = (N - low) / 2 + low;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
                N = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};