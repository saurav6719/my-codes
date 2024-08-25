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
int sumFromLtoR(int l, int r) {
    int n = r - l + 1;
    return n * (l + r) / 2;
}

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > input(n);

    for(int i = 0; i<n; i++){
        int sz;
        cin>>sz;
        vector<int> v(sz);

        for(int i = 0; i<sz; i++){
            cin>>v[i];
        }

        input[i] = v;
    }



    vector<int> secondmex;

    for(int i = 0; i<n; i++){
        vector<int> &v = input[i];
        set<int> st;
        for(auto ele : v){
            st.insert(ele);
        }

        bool firstmex = true;
        for(int j = 0; j<=v.size()+5; j++){
            if(st.count(j) == 0){
                if(firstmex) {
                    firstmex = false;
                    continue;
                }
                else{
                    secondmex.push_back(j);
                    break;
                }
            }
        }
    }

    print(secondmex);

    sort(secondmex.begin(), secondmex.end());
    reverse(secondmex.begin(), secondmex.end());
    print(secondmex);

    int curr = secondmex.back();

    int currm = 0;
    int ans = 0;

    for(int i =0; i<secondmex.size(); i++){
        if(currm > m) break;
        if(currm < secondmex[i]){
            ans += secondmex[i];
        }
        else ans += currm;
        debug(currm);
        debug(ans);
        currm++;
    }    

    ans += sumFromLtoR( currm , m);
    cout<<ans<<endl;


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
    while(t--){
        solve();
    }
return 0;
}

