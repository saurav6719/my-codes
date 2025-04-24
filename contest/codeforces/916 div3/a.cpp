#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<int,int> mp;
    int t;
    cin>>t;
    vector<pair<char,int> > log(26);
    while(t--){
        mp.clear();
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i = 0; i<26; i++){
            log[i].first = 'A' + i;
            log[i].second = i+1;
        }
        for(int i = 0; i<n; i++){
            char a = s[i];
            int b = int(a);
            b = b - int('A');
            
            mp[b]++;
        }
        int count = 0;
        for(auto ele: mp){
            if(mp[ele.first] >= log[ele.first].second)  count++;
        }
       
        cout<<count<<endl;
    }
    return 0;
}