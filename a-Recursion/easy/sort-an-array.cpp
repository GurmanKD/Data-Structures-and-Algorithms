// g++ -std=c++11 sort-an-array.cpp -o sort-an-array && ./sort-an-array
// error: non-aggregate type 'vector<int>' cannot be initialized with an initializer list

#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &nums, int temp){
  if(nums.size() == 0 || temp>=nums[nums.size()-1]){
     nums.push_back(temp);
     return; 
  }
  int temp2 = nums[nums.size()-1];
  nums.pop_back();
  insert (nums, temp);
  nums.push_back(temp2);
}

void sort(vector<int>&nums){
  if(nums.size() == 0)
    return;
  int temp = nums[nums.size()-1];
  nums.pop_back();
  sort(nums);
  insert(nums, temp);
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 5, 7, 6};

    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sort(nums);

    cout << "Sorted vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}