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
void solve(){
    int n;

    cin>>n;
    vector<int> input(n+1);
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        cin>>input[i+1];
        mp[input[i+1]] = i+1;
    }

    if(mp[1] == 1){
        cout<<mp[2]<<" "<<n<<endl;
        return;
    }

    else{
        if(mp[2] == 1){
            cout<<mp[1]<<" "<<n<<endl;
            return;
        }

        if(mp[1] == n){
            cout<<mp[2]<<" "<<1<<endl;
            return;
        }

        if(mp[2] == n){
            cout<<mp[1]<<" "<<1<<endl;
            return;
        }

        int pos1 = mp[1];
        int pos2 = mp[2];

        int mini = min(pos1, pos2);
        int maxi = max(pos1, pos2);
        
        if(mp[n] > mini and mp[n] < maxi){
            cout<<mp[1]<<" "<<mp[1]<<endl;
            return;
        }

        int a = mp[1];
        int b = mp[2];
        int c = mp[n];

        if(c < a and a < b){
            cout<<c<<" "<<a<<endl;
            return;
        }
        if(c > b and b > a){
            cout<<b<<" "<<c<<endl;
            return;
        }
        if(c > a and a > b){
            cout<<c<<" "<<a<<endl;
            return;
        }

        if(c < b and b < a){
            cout<<b<<" "<<c<<endl;
            return;
        }
    }
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

