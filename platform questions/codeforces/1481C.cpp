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
    int n,m;
    cin>>n>>m;
    vector<int> initial(n);
    for(int i = 0; i<n; i++){
        cin>>initial[i];
    }
    vector<int> final(n);
    for(int i = 0; i<n; i++){
        cin>>final[i];
    }

    vector<int> painters(m);
    for(int i =0; i<m; i++){
        cin>>painters[i];
    }
    map<int,int> differences;
    for(int i = 0; i<n; i++){
        if(initial[i] != final[i]){
            differences[final[i]]++;
        }
    }

    int initialsize = differences.size();

    map<int,int> paints;
    for(int i = 0; i<m; i++){
        paints[painters[i]]++;
    }

    int cntt = 0;

    for(auto ele : differences){
        cntt++;
        int xx = ele.second;
        int yy = paints[ele.first];

        if(yy < xx){
            cout<<"NO"<<endl;
            return;
        }

        paints[ele.second] -= xx;
        if(paints[ele.second] == 0){
            paints.erase(ele.first);
        }
        differences.erase(ele.first);
    }

    if(differences.size() > 0){
        cout<<"NO"<<endl;
        return;
    }

    if(cntt == 0){
        set<int> finals;
        for(int i =0; i<n; i++){
            finals.insert(final[i]);
        }
        bool check = false;

        for(auto ele : paints){
            if(finals.count(ele.first) != 0){
                check = true;
            }
        }

        if(!check) {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

    


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

