// https://www.hackerrank.com/challenges/gridland-metro

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// Without using matrix
long lampposts1(long rows, long cols, long num_tracks, 
	std::vector<long> trains){
	
	long ans = 0;
	std::vector<char> check(rows * cols);

	// Initialze all to false;
	for(long i = 0; i < rows * cols; i++)
		check[i] = '0'; 
    
    std::cout << "Size of check vector = " << check.size() << std::endl;
	//std::cout << "Size of trains = " << trains.size() << std::endl;
    
	// There can be overlapping trains
	for(long i = 0; i < trains.size(); i += 3){
		long start_row = trains[i] - 1;
		long start_station = trains[i + 1] - 1;
		long end_station = trains[i + 2] - 1;

   		//std::cout << "Hello\n";

		long start_j = (start_row * cols) + start_station;
		long end_j = (start_row * cols) + end_station;

		for(long j = start_j; j <= end_j; j++){
			if(check[j] == '0'){
				//std::cout << "Marking " << j << " as true\n";
				check[j] = '1';
			}
		}
	}
	
	// Iterate through the check vector and anything that is still false, add all to get the answer
	for(long i = 0; i < rows * cols; i++){
		if(check[i] == '0'){
			//std::cout << "Found false at " << i << std::endl;
			ans++;
		}
	}

	return ans;
}

// Using matrix
long lampposts2(long rows, long cols, long num_tracks, 
	std::vector<long> trains){

	long ans = 0;

	// Matrix to keep check of which stations are used by the trains
	std::vector<std::vector<char>> check(rows, std::vector<char> (cols));

	// Initialize all to 0
	for(long i = 0; i < check.size(); i++){
		for(long j = 0; j < check[i].size(); j++)
			check[i][j] = '0';
	}

	for(long i = 0; i < trains.size(); i += 3){
		// Need to subtract 1 since it starts from 1 in the question and we are starting from 0
		long start_row = trains[i] - 1;
		long start_station = trains[i + 1] - 1;
		long end_station = trains[i + 2] - 1;
		
		/*std::cout << "Row = " << start_row << std::endl;
		std::cout << "Start station = " << start_station << std::endl;
		std::cout << "End station = " << end_station << std::endl;*/

		for(long j = start_station; j <= end_station; j++){
			//std::cout << j << std::endl;
			if(check[start_row][j] == '0')
				check[start_row][j] = '1';
		}
	}

	// Check the "check" matrix and count the remaining zeros, if any
	for(long i = 0; i < rows; i++){
		for(long j = 0; j < cols; j++){
			if(check[i][j] == '0')
				ans++;
		}
	}

	return ans;
}

// Using hashmap
long lampposts3(long rows, long cols, long num_tracks, 
	std::vector<long> trains){
		std::map<int, std::pair<int, int>> hashmap;
		for(int i = 0; i < trains.size(); i += 3){
			hashmap[trains[i] - 1] = std::make_pair()
		}
}

int main(){
	long rows, cols, num_tracks;
	std::cin >> rows >> cols >> num_tracks;

	std::vector<long> trains;
	for(long i = 0; i < num_tracks; i++){
		long start_row, start_station, end_station;
		std::cin >> start_row >> start_station >> end_station;
		trains.push_back(start_row);
		trains.push_back(start_station);
		trains.push_back(end_station);

	}

	std::cout << lampposts1(rows, cols, num_tracks, trains) << std::endl;

    return 0;
}
