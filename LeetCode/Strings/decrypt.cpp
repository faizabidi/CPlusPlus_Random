// https://www.pramp.com/challenge/8noLWxLP6JUZJ2bA2rnx
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> array){
  for(auto value : array)
    std::cout << value << " ";
  std::cout << std::endl;
}

string decrypt( const string& word ){
  vector<int> array;
  std::string ans = ""; 

  if(word.size() < 1)
    return ans;

  for(int i = 0; i < word.size(); i++)
    array.push_back(int(word[i]));

  for(int i = 1; i < array.size(); i++){
    while(array[i] - array[i-1] < 97)
      array[i] += 26;
  }
  
  vector<int> temp = array;
  array[0] -= 1;
  
  for(int i = 1; i < temp.size(); i++)
    array[i] -= temp[i-1];
  
  for(int i = 0; i < array.size(); i++)
    ans += char(array[i]);
  
  return ans;
}

int main() {
  std::string str = "dnotq"; // Ans = crime

  std::cout << decrypt(str) << std::endl;

  return 0;
}
