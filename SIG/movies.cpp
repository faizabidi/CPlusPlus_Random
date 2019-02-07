#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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

// Create hashmap of filecontent
map<int, vector<pair<string, string>>> getFileContent(string filename){
    map<int, vector<pair<string, string>>> moviesMap;
    fstream inputFile(filename);
    string buffer;
    while(getline(inputFile, buffer)){
        vector<string> temp = tokenize(buffer);
        pair<string, string> movie_and_genre = make_pair(temp[0], temp[1]);

        moviesMap[stoi(temp[2])].push_back(movie_and_genre);
    }
    return moviesMap;
}

// Print hashmap based on key
void printAllMovies(int year, map<int, 
                            vector<pair<string, string>>>  moviesMap){

    vector<pair<string, string>> movie_and_genre = moviesMap[year];
    for(int i = 0; i < movie_and_genre.size(); i++){
        cout << movie_and_genre[i].first << ", " << 
                            movie_and_genre[i].second << endl;
    }
    cout << endl;
}

int main(){
    string fileName;
    cout << "Enter filename: ";
    cin >> fileName;
    map<int, vector<pair<string, string>>>  moviesMap = 
                                                getFileContent(fileName);
    cout << "\nWhat year movies do you want to search? ";
    int year;
    cin >> year;
    cout << "\nAll the movies released that year are\n";
    printAllMovies(year, moviesMap);

}
