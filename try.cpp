/**
 *    author: Saurav
 *    created: 2024.11.18 13:54:43
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
    int n;
    cin>>n;
    bool odd = false;
    if(n%2) odd = true;
    n/=2;
    vector<int> input(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>input[i];
        mp[input[i]]++;
    }

    if(odd){
        cout<<-1<<endl;
        return;
    }

    for(auto ele : mp){
        if(ele.second > 1){
            cout<<-1<<endl;
            return;
        }
    }

    set<int> st;
    for(int i = 1; i<=2*n; i++){
        if(mp[i] == 0) st.insert(i);
    }

    vector<int> ans;
    
    for(int i = n-1; i>=0; i--){
        int ele = input[i];
        debug(ele);
        auto idx = st.upper_bound(ele);
        if(idx == st.end()){
            ans.push_back(*st.rbegin());
            st.erase(*st.rbegin());
        }
        else if(idx == st.begin()){
            cout<<-1<<endl;
            return;
        }
        else{
            idx--;
            ans.push_back(*idx);
            st.erase(*idx);
        }
    }

    reverse(ans.begin(),ans.end());

    int i = 0;
    while(i<n){
        cout<<ans[i]<<" ";
        cout<<input[i]<<" ";
        i++;
    }
    cout<<endl;

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

