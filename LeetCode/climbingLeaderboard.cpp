// https://www.hackerrank.com/challenges/climbing-the-leaderboard

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>

void printMap(std::map<int, int> map){
    std::map<int, int>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ":" << it->second << std::endl;
}

void printVector(std::vector<int> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int findRanks1(std::vector<int> array, int num, int &end_index){
    bool flag = false;
    int rank = 1, i;

    if(num >= array[0])
        return rank;
    
    for(i = 1; i < end_index; i++){
        if(array[i] != array[i - 1])
            rank++;
        if(array[i] <= num){
            flag = true;
            end_index = i;
            return rank;
        } 
    }

    if(!flag){
        end_index = i + 1;
        return rank + 1;
    }

    return 0;
}

void findRanks2(std::map<int, int> map, std::vector<int> alice){
    std::vector<int> scores;
    std::map<int, int>::iterator it;
    printMap(map);
    // Store distinct results in a vector
    for(it = map.begin(); it != map.end(); it++)
        scores.push_back(it->first);
    std::reverse(scores.begin(), scores.end());
    // Find where to fit Alice's scores
    int end_index = scores.size();

    for(int i = 0; i < alice.size(); i++){
        int num = alice[i];
        int rank = 1;
        bool flag = false;
        for(int j = 0; j < end_index; j++){
            if(num >= scores[j]){
                std::cout << rank << std::endl;
                end_index = j + 1;
                flag = true;
                break;
            }
            else
                rank++;
        }
        if(!flag)
            std::cout << rank << std::endl;
    }
}

void findRanks3(std::map<int, int> map, std::vector<int> alice){
    std::vector<int> scores;

    // Store distinct results in a vector
    for(std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        scores.push_back(it->first);
    std::sort(scores.begin(), scores.end());
    printVector(scores);

    for(int i = 0; i < alice.size(); i++){
        int num = alice[i];
        std::vector<int>::iterator up;
        up = std::upper_bound(scores.begin(), scores.end(), num);
        std::cout << std::distance(up, scores.end()) + 1 << std::endl;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> scores(n);
    std::map<int, int> map;
    for(int scores_i = 0;scores_i < n;scores_i++){
       std::cin >> scores[scores_i];
       // Store it in a hashmap
       map[scores[scores_i]]++; 
    }
    
    int m, end_index = n, rank = 1;
    std::cin >> m;

    std::vector<int> alice(m);
    for(int alice_i = 0; alice_i < m;alice_i++)
        std::cin >> alice[alice_i];
    
    findRanks3(map, alice);

    return 0;
}
