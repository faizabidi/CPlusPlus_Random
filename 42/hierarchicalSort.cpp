#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Read file and save its contents in a vector
vector<string> getFileContents(string fileName){
	vector<string> fileContent;
	ifstream inputFile(fileName);

	string buffer;
	// Read file line by line and store it in a new vector
    while(getline(inputFile, buffer))
        fileContent.push_back(buffer);
    
    return fileContent;
}

// Tokenize based on "|" delimeter
vector<string> tokenize(string str){
	char delimeter = '|';
	string buffer;
	stringstream ss(str);
	vector<string> tokens;
	while(getline(ss, buffer, delimeter))
		tokens.push_back(buffer);
	return tokens;
}

void printVector(vector<string> array){
	for(auto value : array)
		cout << value << endl;
}

void printVector2(vector<vector<string>> matrix){
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

bool compare(vector<string> array1, vector<string> array2){
	int sales1 = stoi(array1[array1.size()-1]);
	int sales2 = stoi(array2[array2.size()-1]);
	if(sales1 > sales2)
		return false;
	return true;

}

struct groups{
	vector<vector<string>> group;
};

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Please enter the name of the file with unsorted data.\n";
		cout << "For example, run it as: ./a.out fileName\n";
		return 0;
	}
	string fileName = argv[1];
	vector<string> fileContent = getFileContents(fileName);
	// Store it in a vector of vectors
	vector<vector<string>> allItems;
	for(int i = 1; i < fileContent.size(); i++){
		vector<string> tokens = tokenize(fileContent[i]);
		allItems.push_back(tokens); 
	}
	// Sort all items. This will make it sorted by group type 
	sort(allItems.begin(), allItems.end());

	// Make groups bases on property 0
	int k = 1;
	for(int i = 1; i < allItems.size(); i++){
		for(int j = 0; j < allItems.size(); j++){
			
		}
	}


	printVector2(allItems);
	return 0;
}