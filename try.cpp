#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
  int n;
    cin>>n;

    vector<int> input(n);

    map<int,int> mp;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        mp[input[i]]++;
    }
    if(mp.size() ==1 and input[0] == 0){
        cout<<"YES";
        return 0;
    }

    vector<pair<int,int> > v(mp.begin(), mp.end());

    if(mp.size() == 2 and v[0].first == 0){
        int x = v[0].second;
        int y = v[1].second;
        if(3*x == n or 3*y == n){
            cout<<"YES";
            return 0;
        }
    } 

    if(n%3 != 0  or mp.size() != 3) {
        
        cout<<"NO";
        return 0;
    }
    int first = -1;
    int second = -1;
    int third = -1;

    

    if(v[0].second != v[1].second or v[1].second != v[2].second){
        cout<<"NO";
        return 0;
    }

    for(auto ele : mp){
        if(first == -1) {
            first = ele.first;
            continue;
        }
        if(second == -1){
            second = ele.first;
            continue;
        }
        third = ele.first;
    }
    
    if((first ^ second ^ third)== 0){
        cout<<"YES";
    }
    else cout<<"NO";
    

  return 0;

}