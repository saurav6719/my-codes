/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

void solvee(){
    int n;
    cin>>n;
    map<int, int> mp;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
        mp.insert({input[i], i});
    }
    cout<<n<<"f";
    for(int i = 0; i<n; i++){
        cout<<input[i]<<"f";
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    map<int, int> mp;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
        mp.insert({input[i], i});
    }
    int contrast = 0;


    for(int i = 1; i<n; i++){
        contrast += abs(input[i] - input[i-1]);
    }


    if(contrast == 0){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<2<<endl;
        return;
    }
    int cnt = 0;
    bool inc ;
    int i =0;
    while(i<n-1 and input[i] == input[i+1]) i++;
    if(i==n-1){
        cout<<1<<endl;
        return;
    }
    if(input[i] > input[i+1]) {
        inc = false;
    }
    else inc = true;
    debug(inc);
    i++;
    debug(i);
    cnt = 1;
    while(i<n-1){
        if(inc){
            if(input[i+1] < input[i]){
                cnt++;
                inc = false;
                i++;
                continue;
            }
            else {
                i++;
                continue;
            }
        }
        else{
            if(input[i+1] > input[i]){
                cnt++;
                inc = true;
                i++;
                continue;
            }
            else {
                i++;
                continue;
            }
        }
        
    }
    cout<<cnt+1<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

