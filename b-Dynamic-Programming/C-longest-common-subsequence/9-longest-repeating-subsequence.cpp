// print the length of longest common subsequence
// subsequence need not be continuous

#include<iostream>
#include<string>

using namespace std;

int recLCS(string s1, int m, string s2, int n){
  if(m == 0 || n == 0)
    return 0;

  if(s1[m-1] == s2[n-1])
    return 1+recLCS(s1, m-1, s2, n-1);
  else
    return max(recLCS(s1, m, s2, n-1), recLCS(s1, m-1, s2, n));
}

int static t1[1001][1001];

int memoLCS(string s1, int m, string s2, int n){
  if(m == 0 || n == 0) 
    t1[m][n] = 0;

  if(t1[m][n] != -1)
    return t1[m][n];

  else{
    if(s1[m-1] == s2[n-1])
      return t1[m][n] = 1+recLCS(s1, m-1, s2, n-1);
    else
      return t1[m][n] = max(recLCS(s1, m, s2, n-1), recLCS(s1, m-1, s2, n));
  }

  return t1[m][n];
}

int static t2[1001][1001];

int topDownLCS(string s1, int m, string s2, int n){
  for(int i = 0; i <= m; i++){
    for(int j = 0; j <= n; j++){
      if(i == 0 || j == 0)
        t2[i][j] = 0;
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){   
      if(s1[i] == s2[j])
        t2[i][j] = 1 + t2[i-1][j-1];
      else
        t2[i][j] = max(t2[i-1][j], t2[i][j-1]);
    }
  }

  return t2[m][n];
}

int main(){
  string s1 = "abcdefg";
  int m = 7;
  string s2 = "aabbccdd";
  int n = 8;
  cout<<recLCS(s1, m, s2, n)<<endl;
  
  memset(t1, -1, sizeof(t1));
  cout<<memoLCS(s1, m, s2, n)<<endl;

  cout<<topDownLCS(s1, m, s2, n)<<endl;

  return 0;
}