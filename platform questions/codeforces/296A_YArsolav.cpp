#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    for(int i = 0; i<n; i++){
        mp[input[i]]++;
    }

    bool flag = true;

    for(auto ele: mp){
        if(n%2 != 0 and ele.second > n/2 + 1) {
            flag = false;
            break;
        }
        else if(n%2 == 0 and ele.second > n/2){
            flag = false;
            break;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";

    return 0;
}