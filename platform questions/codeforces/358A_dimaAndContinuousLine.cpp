#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define ll long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<pair<int, int> > pairs;

    for(int i = 1; i<n; i++){
        if(input[i-1] < input[i]) pairs.push_back({input[i-1], input[i]});
        else pairs.push_back({input[i], input[i-1]});
    }
    bool flag = true;
    for(int i = 0; i<pairs.size();i++){
        if(!flag) break;
        for(int j = 0; j<pairs.size();j++){
            if(!flag) break;
            int x1 = pairs[i].first;
            int x2 = pairs[i].second;
            int x3 = pairs[j].first; //x1 < x3 < x2 < x4     2). 3 < x1 < x4 < x2
            int x4 = pairs[j].second;  
            if(x1 < x3 and x3 < x2 and x2 < x4) flag = false;
            if(x3 < x1 and x1 < x4 and x4 < x2) flag = false; // 0 1000 2000 3000 1500
        }
    }
    
    if(!flag) cout<<"yes";
    else cout<<"no";
}


int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}