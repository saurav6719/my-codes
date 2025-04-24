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
bool compare(vector<int> &a, vector<int> &b){
    return a.size() > b.size();
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > input(n, vector<int> ());
    for(int i = 0; i<n; i++){
        int k ;
        cin>>k;
        for(int j = 0; j<k; j++){
            int ele ;
            cin>>ele;
            input[i].push_back(ele);
        }
    }

    sort(input.begin(), input.end() , compare);

    // print(input[0]);
    // print(input[1]);
    // print(input[2]);

    map<int,int> mp;
    set<int> st;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<input[i].size(); j++){
            mp[input[i][j]]++;
        }
    }
    for(int i = 0; i<input.size(); i++){
        bool check = true;
        for(int j = 0; j<input[i].size(); j++){
            if(mp[input[i][j]] <=1){
                check = false;
            }
        }
        if(check){
            cout<<"Yes"<<endl;
            return; 
        }
    }

    cout<<"No"<<endl;

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

