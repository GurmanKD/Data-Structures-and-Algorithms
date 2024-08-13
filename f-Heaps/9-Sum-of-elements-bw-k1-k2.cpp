/*
Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.

Example :
Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
Output : 26          
         3rd smallest element is 10. 6th smallest element 
         is 20. Sum of all element between k1 & k2 is
         12 + 14 = 26 . 
*/

/*
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Example:
Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7 . 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findKthSmallest(vector<int> v, int k){
  priority_queue<int>maxHeap;
  for(int i = 0; i < v.size(); i++){
    maxHeap.push(v[i]);
    if(maxHeap.size() > k){
      maxHeap.pop();
    }
  }
  return maxHeap.top();
}

int main(){
  vector<int> v = {4,5,2,6,3,7,0,8};
  int k1 = 3;
  int num1 = findKthSmallest(v, k1);
  int k2 = 6;
  int num2 = findKthSmallest(v, k2);
  int sum = 0;
  for(int i = 0; i < v.size(); i++){
    if(v[i]>num1 && v[i]<num2){
      sum+=v[i];
    }
  }
  cout<<sum;
  return 0;
}