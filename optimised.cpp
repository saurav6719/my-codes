/**
 *    author: Saurav
 *    created: 2025.04.19 00:19:45
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

bool cmp(int a, int b, map<int,int> &mp){
    return mp[a] < mp[b];
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    set<int> st;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        st.insert(input[i]);
    }

    vector<int> v;
    for(auto ele : st){
        v.push_back(ele);
    }

    int reqmex = -1;
    print(v);

    for(int i = n; i>=0; i--){
        int chhote = lower_bound(v.begin(), v.end(), i) - v.begin();
        chhote--;
        int chahiyeaur = i - chhote - 1;
        if(k>=chahiyeaur){
            reqmex = i;
            break;
        }
    }

    debug(reqmex);

    map<int,int> mp;
    for(auto ele : input){
        if(ele >= reqmex){
            mp[ele]++;
        }
    }

    vector<int> v2;
    for(auto ele : input){
        if(ele >= reqmex){
            v2.push_back(ele);
        }
    }

    sort(v2.begin(), v2.end(), [&](int a, int b){
        return cmp(a, b, mp);
    });

    print(v2);
    int i = 0;

    while(k-- and i<v2.size()){
        i++;
    }

    set<int> remaining;

    for(int j = i; j<v2.size(); j++){
        remaining.insert(v2[j]);
    }

    debug(remaining.size());

    int ans = remaining.size();

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

