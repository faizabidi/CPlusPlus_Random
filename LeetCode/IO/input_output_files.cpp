#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    string filename = "inputFile.text";
    vector<string> output;

    ifstream inputFile(filename);

    string buffer;
    // Read file line by line and store it in a new vector
    while(getline(inputFile, buffer))
        output.push_back(buffer);
    
    // Store this output in a new file
    ofstream outputFile;
    outputFile.open("outputFile.txt");

    for(int i = 0; i < output.size(); i++)
        outputFile << "Hello, " + output[i] << endl;
    
    return 0;
}
