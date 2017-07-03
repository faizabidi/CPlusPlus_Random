// Hits a website receives in the last 1 minute

#include <iostream>
#include <vector>
#include <ctime>

class HitCounter{
private:
	std::vector<int> times, hits;

public:
	HitCounter(){
		times.resize(60);
		hits.resize(60);
	}
	
	void getHit(int timestamp){
		// Find the index and store it in the vector times
		int index = timestamp % 60;
		// If time is not in the vector
		if(times[index] != timestamp){
			times[index] = timestamp;
			// It means it would be the first hit
			hits[index] = 1;
		}
		else{
			// This means that this time has been recorded before and it is just that more hits occured in that instance
			hits[index]++;
		}
	}

	int hitCount(int timestamp){
		// Idea is to sum up all the values in the vector hits till we get to the current time
		int ans = 0;
		for(int i = 0; i < 60; i++){
			// We need to sum up the hits in the last 1 minute = 60 seconds
			if(timestamp - times[i] < 60)
				ans += hits[i];
		}

		return ans;
	}
};

int main(){
	HitCounter obj1;

	return 0;
}