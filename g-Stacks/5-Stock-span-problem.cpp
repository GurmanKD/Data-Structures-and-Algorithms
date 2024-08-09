/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.

The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
*/

// similar to nearest greater towards left === consecutive smaller or equal before it

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>calculateSpan(vector<int>stockPrices){
  vector<int>span={};
  stack<pair<int, int>>st={}; // stack stores left array of the ith element
  // <ngl, ith index>
  int n = stockPrices.size();
  for(int i=0; i<n; i++){
        if(st.empty()){
          span.push_back(-1);
        }
        else if(!st.empty() && st.top().first > stockPrices[i]){
          span.push_back(st.top().second);
        }
        else if(!st.empty() && st.top().first <= stockPrices[i]){
          while(!st.empty() && st.top().first <= stockPrices[i]){
            st.pop();
          }
          if(st.empty())
            span.push_back(-1);
          else
            span.push_back(st.top().second);
        }
      st.push({stockPrices[i], i});
  }
  for(int i = 0; i < span.size(); i++){
    span[i] = i-span[i];
  }
  return span;
}

int main(){
  vector<int> stockPrices = {100, 80, 60, 70, 60, 75, 85};
  vector<int> span = calculateSpan(stockPrices);
  for(int i = 0; i < span.size(); i++){
    cout<< span[i]<<" ";
  }
  return 0;
}