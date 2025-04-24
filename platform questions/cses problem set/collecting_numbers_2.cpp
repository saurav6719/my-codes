#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> values(n+1);
    vector<int> position(n+1);
    for(int i = 1; i<=n; i++){
        cin>>values[i];
        position[values[i]] = i;
    }
    int answer = 1;
    for(int i = 1;i<n; i++){
        if(position[i] > position[i+1]){
            answer++;
        }
    }
    int l,r;
    set<pair<int ,int > > updatedPairs;
    while(q--){
        cin>>l>>r;
        if(values[l]+1 <=n){
            updatedPairs.insert({values[l] , values[l]+1});
        }
        if(values[l]-1 >=1){
            updatedPairs.insert({values[l]-1 , values[l]});
        }
        if(values[r]+1 <=n){
            updatedPairs.insert({values[r] , values[r]+1});
        }
        if(values[r]-1 >=1){
            updatedPairs.insert({values[r]-1 , values[r]});
        }
        //check krlo kya chota bala ka position jyada tha bda bala se
        //agar jyada tha to swap k baad kam ho jayega so answer--
        for(auto pairs : updatedPairs){
            if(position[pairs.first] > position[pairs.second]){
                answer--;
            }
        }
        swap(values[l], values[r]);
        position[values[l]] = l;
        position[values[r]] = r;
        //swap hone k baad check krlo position 
        //agar inversion hai tto answer++
        for(auto pairs : updatedPairs){
            if(position[pairs.first] > position[pairs.second]){
                answer++;
            }
        }
        cout<<answer<<endl;
        updatedPairs.clear();
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}