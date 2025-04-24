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
    string str;
    cin>>str;
    int n= str.size();
    int q;
    cin>>q;

    vector<vector<int> > v(n+5, vector<int> (26,0));

    for(int i = 0; i<n; i++){
        char ch = str[i];
        int idx = ch - 'a';

        v[i][idx]++;
    }

    for(int i = 1; i<n; i++){
        for(int j= 0; j<26; j++){
            v[i][j] += v[i-1][j];
        }
    }

    print2d(v);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;

        if(l==r) {
            cout<<"Yes"<<endl;
            continue;
        }
        map<int,int> mp;
        for(int i =0; i<26; i++){
            int ele = i;
            int val = v[r][i];
            mp[ele] = val;
        }

        if(l>0){
            for(int i =0; i<26; i++){
                int ele = i;
                int val = v[l-1][i];
                mp[ele] -= val;
                if(mp[ele] == 0) mp.erase(ele);
            }
        }

        for(int i = 0; i<26; i++){
            if(mp[i] == 0) mp.erase(i);
        }
        debug(mp.size());

        if(mp.size() == 1){
            cout<<"No"<<endl;
            continue;
        }
        else if(mp.size() > 2){
            cout<<"Yes"<<endl;
            continue;
        }
        else{
            if(str[l] == str[r]){
                cout<<"No"<<endl;
            }
            else cout<<"Yes"<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

