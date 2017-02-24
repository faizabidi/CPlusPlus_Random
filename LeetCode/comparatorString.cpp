// https://www.hackerrank.com/challenges/ctci-comparator-sorting

#include <iostream>
#include <vector>

struct Player{
    std::string name;
    int score;
}; 

// Refer: http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool compare(Player p1, Player p2){
   // Sort first by score
   if (p1.score != p2.score) 
       return (p1.score > p2.score);
   // If scores are same, sort by name
   return (p1.name < p2.name);
}

std::vector<Player> comparator(std::vector<Player> players){
    // The third parameter in the sort function is an operator called "compare"
    std::sort(players.begin(), players.end(), compare);
    return players;
}

int main(){
    
    int n;
    std::cin >> n;

    std::vector<Player> players;
    std::string name;
    int score;

    for(int i = 0; i < n; i++){
        std::cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    std::vector<Player> answer = comparator(players);

    for(int i = 0; i < answer.size(); i++)
        std::cout << answer[i].name << " " << answer[i].score << std::endl;
    
    return 0;
}
