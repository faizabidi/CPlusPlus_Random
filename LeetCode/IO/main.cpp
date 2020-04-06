#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> readFile(string filename){
    vector<string> data;
    ifstream inputFile(filename);
    string buffer = "";
    while(getline(inputFile, buffer))
        data.push_back(buffer);
    return data;
}

void writeToFile(vector<string> data){
    ofstream outputFile; outputFile.open("output.txt");
    for(int i = 0; i < data.size(); i++){
        outputFile << "Hello, " << data[i] << "!" << endl;
    }
}

int main(){
    cout << "Enter a file name:";
    string filename = "";
    cin >> filename;
    vector<string> data = readFile(filename);
    writeToFile(data);
    cout << "Data has been written to file output.txt\n";
    
    return 0;
}