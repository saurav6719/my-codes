#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
  cin >> n;
 
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int minTime = INT_MAX;
  for(int i=0; i<n; i++){
    vector<int> t(v[i]);
    int totTime = 0;
    for(int i=0; i<t.size(); i++){
      cin >> t[i];
      totTime += t[i]*5;
    }
    totTime += 15*(t.size());
    minTime = min(minTime, totTime);
  } 
  cout << minTime << endl;
    return 0;
}