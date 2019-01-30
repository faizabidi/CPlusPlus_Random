#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

bool compare(const vector<string> &array1, const vector<string> &array2){
	int val1 = stoi(array1[array1.size()-1]);
	int val2 = stoi(array2[array2.size()-1]);
	if(val1 < val2)
		return array1 < array2;
	//return array1 > array2;
	//return array1[array1.size() - 1] < array2[2];
}

void printVector2(vector<vector<string>> matrix){
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main(){
	vector<vector<string>> matrix;
	//vector<string> array1 = {"bar","$total","-200"};
	//vector<string> array2 = {"foo","sauce","300"};
	//vector<string> array3 = {"$total","$total","200"};
	//vector<string> array4 = {"bar","sup","-400"};
	//vector<string> array5 = {"foo","$total","400"};
	//vector<string> array6 = {"foo","$total","400"};

	vector<string> array1 = {"bar","$total","30"};
	vector<string> array2 = {"1","2","50"};
	vector<string> array3 = {"1","2","20"};
	vector<string> array4 = {"1","2","-5"};



//bar|bro|200
//foo|bacon|100
	matrix.push_back(array1);
	matrix.push_back(array2);
	matrix.push_back(array3);
	matrix.push_back(array4);
	//matrix.push_back(array4);
	//matrix.push_back(array5);
	//matrix.push_back(array6);
	printVector2(matrix);
	sort(matrix.begin(), matrix.end());
	cout << "*******************\n";
	printVector2(matrix);

	return 0;
}