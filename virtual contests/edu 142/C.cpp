/**
 *    author: Saurav
 *    created: 2025.02.20 16:57:56
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
    int n,q;
    cin>>n>>q;
    vector<int> input(n);
    deque<int> dq;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        dq.push_back(input[i]);
    }

    vector<vector<int> > winningrounds(n+1);
    map<int,int> mp;

    int fightcnt = 0;
    while(dq.front() != n){
        fightcnt++;
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        if(a>b){
            mp[a]++;
            dq.push_front(a);
            dq.push_back(b);
            winningrounds[a].push_back(fightcnt);
        }
        else{
            mp[b]++;
            dq.push_front(b);
            dq.push_back(a);
            winningrounds[b].push_back(fightcnt);
        }
    }

    print2d(winningrounds);
    printmap(mp);

    debug(fightcnt);
    while(q--){
        int i,k;
        cin>>i>>k;
        i--;
        if(k < fightcnt){
            int ele =input[i];
            int ans = lower_bound(winningrounds[ele].begin(), winningrounds[ele].end(), k) - winningrounds[ele].begin();
            if(ans == 0){
                if(winningrounds[ele].empty()){
                    cout<<0<<endl;
                    continue;
                }
            }

            if(ans == winningrounds[ele].size()){
                cout<<winningrounds[ele].size()<<endl;
                continue;
            }

            if(winningrounds[ele][ans] == k){
                cout<<ans+1<<endl;
            }
            else{
                cout<<ans<<endl;
            }
            continue;
        }
        if(input[i] != n){
            cout<<mp[input[i]]<<endl;
            continue;
        }

        if(fightcnt == 0){
            cout<<k<<endl;
            continue;
        }

        cout<<1 + (k - fightcnt)<<endl;
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

