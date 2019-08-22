/*
Given a list of .csv strings containing an integer timestamp, stock name, and stock price on the previous trading day, examine the list and provide the optimal time to have bought and sold exactly one share of a specified stock, along with the profit.
- Can only buy a single share, one time (or zero times if there is no profit)
- Can only sell a single share, one time (or zero times if there is no profit)
- Must buy before selling
- Find maximum profit and report the stock, buy time, sell time, and profit
- each line has 3 fields, separated by a comma:
<integer timestamp>,<stock name>,<price>

Example output for the sample data below for "GOOG" might be:
GOOG: buytime=1559990007, selltime=1559990010, profit=4.0


price_lines = [
"1559990001,GOOG,104.25",
"1559990001,FB,100.00",
"1559990002,AAPL,100.00",
"1559990003,GOOG,105.00",
"1559990004,FB,99.00",
"1559990007,GOOG
50",
"1559990011,GOOG,99.00",
"1559990013,AAPL,102.00",
"1559990013,GOOG,102.50",
"1559990014,GOOG,102.50",
"1559990014,FB,97.00",
"1559990017,GOOG,102.75",
"1559990018,GOOG,102.00",
"1559990019,FB,95.00",
]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Helper function to find the max profit
// O(n) time
vector<string> maxProfit(vector<vector<string>> data){
  if(data.size() < 2)
    return {};
  vector<string> ans;
  int buyStockIndex = 0, sellStockIndex = 0;
  double finalProfit = 0;
  // Sliding window
  int i = 0, j = 1;
  while(i <= j && i < data.size() && j < data.size()){
    double profit = stod(data[j][2]) - stod(data[i][2]); 
    if(profit > finalProfit){
      buyStockIndex = i;
      sellStockIndex = j;
      finalProfit = profit;
    }
    // If negative profit, increment i
    if(profit < 0)
      i++;
    else
      j++;
  }
  ans.push_back(data[buyStockIndex][0]);
  ans.push_back(data[sellStockIndex][0]);
  ans.push_back(to_string(finalProfit));
  return ans;
}

// Create a map of stock names. Key is stock name and value is all string with that stock name
// O(n) time and O(n) space
unordered_map<string, vector<vector<string>>> parseDataToGetNames(vector<vector<string>> data){
  unordered_map<string, vector<vector<string>>> stockMap;
  for(int i = 0; i < data.size(); i++){
    vector<string> temp = data[i];
    stockMap[data[i][1]].push_back(temp);
  }
  return stockMap;
}

// O(n*m) time
vector<vector<string>> findMaxInAllDataForEachStock(vector<vector<string>> allData){

  vector<vector<string>> optimalBuySellStock; 

  // Get hashmap of stock
  unordered_map<string, vector<vector<string>>> dataMap = parseDataToGetNames(allData);
  // Iterate this hashmap and find optimal solution for each key
  for(auto it = dataMap.begin(); it != dataMap.end(); it++){
    vector<vector<string>> currStock = it->second;
    vector<string> currStockAns = maxProfit(currStock);
    // Add to final answer
    optimalBuySellStock.push_back(currStockAns);
  }
  return optimalBuySellStock;
}

// Show data
void print(vector<vector<string>> data){
  for(int i = 0; i < data.size(); i++){
    for(int j = 0; j < data[i].size(); j++)
      cout << data[i][j] << " ";
    cout << endl;
  }
}

int main(){
  vector<vector<string>> price_lines = {
    {"1559990001","GOOG","104.25"},
    {"1559990001","FB","100.00"},
    {"1559990002","AAPL","100.00"},
    {"1559990003","GOOG","105.00",},
    {"1559990004","FB","99.00",},
    {"1559990007","GOOG","50"},
    {"1559990011","GOOG","99.00",},
    {"1559990013","AAPL","102.00"},
    {"1559990013","GOOG","102.50"},
    {"1559990014","GOOG","102.50"},
    {"1559990014","FB","97.00"},
    {"1559990017","GOOG","102.75"},
    {"1559990018","GOOG","102.00"},
    {"1559990019","FB","95.00"},
  };
  
  vector<vector<string>> optimalBuySellStock = findMaxInAllDataForEachStock(price_lines);

  // Print the final answer
  print(optimalBuySellStock);

  return 0;
}
