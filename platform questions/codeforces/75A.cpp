#include<iostream>
#include<vector>
using namespace std;
int convert(int num){
  string t1 = to_string(num);
  string temp = "";
  for(int i=0; i<t1.length(); i++){
    if(t1[i] != '0') temp.push_back(t1[i]);
  }
  int ans = stoi(temp);
  return ans;
}
int main(){
    int a, b;
  cin >> a >> b;
 
  int c = a+b;
 
  if(convert(a)+convert(b) == convert(c)){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
    return 0;
}



 