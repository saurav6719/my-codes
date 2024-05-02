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
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int pb;
    cin>>pb;
    int ps;
    cin>>ps;
    vector<int> perm(n+1);
    for(int i = 1; i<=n; i++){
        cin>>perm[i];
    }
    vector<int> score(n+1);
    for(int i = 1; i<=n; i++){
        cin>>score[i];
    }

    int scores = 0;
    int scoreb = 0;
    
    int fs = -1;
    int fb = -1;

    for(int i = 1; i<=min(n,k); i++){
        scores += score[ps];
        fs = max(fs, scores + (score[ps]*(k-i)));
        ps = perm[ps];

        scoreb += score[pb];
        fb = max(fb, scoreb + (score[pb]*(k-i)));
        pb = perm[pb];
    }

    if(fs > fb){
        cout<<"Sasha"<<endl;
        return;
    }
    if(fs == fb){
        cout<<"Draw"<<endl;
        return;
    }
    cout<<"Bodya"<<endl;
    return;
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
    while(t--){
        solve();
    }
return 0;
}

