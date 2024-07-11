#include<iostream>
#include<vector>
using namespace std;

// v is to be passed by value!!!!
int solve(vector<int>v, int index, int& ans, int k){
  if(v.size() == 1){
    ans = v[0];
    return ans;
  }

  index=(index+k)%v.size();

  v.erase(v.begin()+index);

  solve(v, index, ans, k);
  return ans;
}

int main(){
  int n, k;

  cout<<"Enter the value of n:"<<endl;
  cin>>n;

  vector<int> v(n);
  for(int i = 0; i < v.size(); i++){
    v[i]=i+1;
  }

  cout<<"Enter the value of k:"<<endl;
  cin>>k;
  k-=1; // because counting starts from the index itself;

  int index = 0;

  int ans = -1;

  cout<<solve(v, index, n, k);

  return 0;
}