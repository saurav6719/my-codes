/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
 **/

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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    if(a==1){
        if(n % b == 1){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
        return;
    }

    set<int> st;
    int curr = 1;
    set<int> mods;
    while(curr <= n){
        st.insert(curr);
        mods.insert(curr % b);
        curr *= a;
    }
    vector<int> visited(1e6, 0);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int tp = q.front();
        q.pop();
        visited[tp] = 1;
        
        if(tp * a < 1e6 and visited[tp * a] == 0) q.push(tp*a);
        if(tp + b < 1e6 and visited[tp + b] == 0) q.push(tp+b);
    }

    vector<int> pahucha;

    for(int i = 1; i<1e6; i++){
        if(visited[i] == 1) pahucha.push_back(i);
    }

    int cnt = 0;

    for(auto x : pahucha){
        bool poss = false;
        for(auto ele : st){
            int diff = x - ele;
            if(diff % b == 0){
                cnt++;
                poss = true;
                break;
            }
        }

        if(!poss){
            cout<<x<<endl;
            return;
            break;
        }
    }

    cout<<"Yes"<<endl;
    
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

