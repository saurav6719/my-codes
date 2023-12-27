#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int main(){
    
    unordered_map<int, int> mp;
    int n;
    cin>>n;
    vector<int> first(n);
    vector<int> second(n);
    for(int i = 0; i< n ; i++){
        cin>>first[i];
        cin>>second[i];
    }
    for(int i = 0; i< n ; i++){
        mp[first[i]]++;
    }
    int count = 0;
    for(int i = 0; i< n ; i++){
        if(mp.find(second[i]) != mp.end()){
            count += mp[second[i]];
        }
    }

    cout<<count;

    

    return 0;

}
