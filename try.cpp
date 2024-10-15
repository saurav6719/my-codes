/**
 *    author: Saurav
 *    created: 2024.10.15 19:57:08
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
    vector<int>  storage(n);
    vector<int> importance(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>storage[i];
        sum += storage[i];
    }
    for(int i = 0; i<n; i++){
        cin>>importance[i];
    }

    if(m > sum){
        cout<<-1<<endl;
        return ;
    }

    vector<int> one;
    vector<int> two;
    for(int i = 0; i<n; i++){
        if(importance[i] == 1){
            one.push_back(storage[i]);
        }
        else{
            two.push_back(storage[i]);
        }
    }

    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());

    vector<int> prefixone(one.size()+1,0);
    vector<int> prefixtwo(two.size()+1,0);

    for(int i = 1; i<=one.size(); i++){
        prefixone[i] = prefixone[i-1] + one[i-1];
    }
    for(int i = 1; i<=two.size(); i++){
        prefixtwo[i] = prefixtwo[i-1] + two[i-1];
    }
    int ans = 1e15;
    for(int i  = 0; i<=one.size(); i++){
        // i took i one 
        int totalonetaken = prefixone[i];
        int remaining = m - totalonetaken;
        // how many twos required now 
        if(remaining <= 0){
            ans = min(ans, i);
            continue;
        }
        int twoindex = lower_bound(prefixtwo.begin(), prefixtwo.end(), remaining) - prefixtwo.begin();

        if(twoindex == two.size() + 1){
            continue;
        }

        debug(i);
        debug(twoindex);

        ans = min(ans , i + 2*twoindex);
    }

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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

