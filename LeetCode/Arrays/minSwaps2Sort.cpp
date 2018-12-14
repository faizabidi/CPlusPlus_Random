// https://www.hackerrank.com/challenges/minimum-swaps-2/problem


// O(n) time
int minimumSwaps(vector<int> arr){
    int swaps = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]-1 != i){
          while(arr[i] - 1 != i){
            swap(arr[i], arr[arr[i]-1]);
            swaps++;
          }
        }
    }
    return swaps;
}