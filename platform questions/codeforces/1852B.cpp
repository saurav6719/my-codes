/**
 *    author: Saurav
 *    created: 2024.10.17 21:08:40
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
    vector<pp> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        input[i].second = i;
    }

    sort(input.begin(),input.end(), [&](pp a, pp b){
        return a.first < b.first;
    });

    deque<pp> dq;
    for(auto x : input){
        dq.push_back(x);
    }

    vector<int> ans(n);
    int sz = n;

    int l = 0;
    int r = n-1;

    while(!dq.empty()){
        int ff = dq.front().first;
        int ll = dq.back().first;

        if((n-l == ll) ^ (n-1-r == ff)){
            if((n-l == ll)){
                ans[dq.back().second] = sz;
                sz--;
                dq.pop_back();
                r--;
            }
            else{
                ans[dq.front().second] = -sz;
                sz--;
                dq.pop_front();
                l++;
            }
        }
        else{
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
    for(auto x : ans){
        cout<<x<<" ";
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

