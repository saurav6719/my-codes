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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
bool isPerfect(int n){
    int xx = sqrt(n);
    return ((xx * xx) == n);
}
void solve(vector<set<int>> &odds){
    int n;
    cin>>n;
    int maxi = 0;
    vector<int> input(n);
    for(int i =0; i<n; i++){
        cin>>input[i];
        maxi = max(maxi , input[i]);
    }
    vector<int> mp((4*(n+1)) + 5, 0);
    int ans = 0;
    vector<int> input_copy = input;
    for(int i = 0; i<n; i++){
        if(i>0) input_copy[i] = (input_copy[i] ^ input_copy[i-1]);
        debug(input_copy[i]);
        if(isPerfect(input_copy[i])) ans++;
        debug(ans);
        // for(auto ele : odds[input_copy[i]]){
        //     // if(mp[ele] > 0) debug(ele);
        //     ans += mp[ele];
        // }

        for(int j = 0; j*j <= (2*n) ; j++){
            int xx = input_copy[i];
            xx ^= (j*j);
            ans += mp[xx];
            // debug(mp[xx]);
        }
        debug(ans);
        debug(input_copy[i]);
        debug(mp[input_copy[i]]);
        mp[input_copy[i]]++;
        debug(mp[input_copy[i]]);
    }
    debug(ans);

    int total = n * (n+1) / 2;

    cout<<total - ans<<endl;
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
    // t = 1;

    vector<set<int> > odds(2e5+5);
    // for(int i = 0; i<=2e5; i++){
    //     int ele = i;
    //     for(int j = 0; j<=450; j++){
    //         odds[i].insert((ele ^ (j*j)));
    //     }
    // }

    while(t--){
        solve(odds);
    }
return 0;
}

