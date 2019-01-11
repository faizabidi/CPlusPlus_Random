#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> array){
	for(auto value : array)
		cout << value << " ";
	cout << endl;
}

void shuffleCards(vector<int> &cards){
	srand (time(0));
	for(int i = 0; i < 52; i++){
		// Get a random number between 0 to 51
		int random_number = rand() % 51;
		swap(cards[i], cards[random_number]);
	}
}

int main(){
	vector<int> cards(52);

	for(int i = 0; i < 52; i++)
		cards[i] = i+1;

	cout << "Unshuffled cards:\n";
	printVector(cards);

	shuffleCards(cards);
	cout << "Shuffled cards:\n";
	printVector(cards);

	return 0;
	
}