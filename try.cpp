/**
 *    author: Saurav
 *    created: 2024.11.15 14:44:36
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
    int n,k;
    cin>>n>>k;
    vector<int> x(k);
    vector<int> c(k);
    for(int i = 0; i<k; i++){
        cin>>x[i];
    }
    for(int i = 0; i<k; i++){
        cin>>c[i];

        
    }

    for(int i = 0; i<k; i++){
        if(c[i] > x[i]){
            debug(x[i]);
            debug(c[i]);
            debug(i);
            cout<<"NO"<<endl;
            return;
        }
    }

    for(int i = 1; i<k; i++){
        int diffa = x[i] - x[i-1];
        int diffb = c[i] - c[i-1];
        if(diffb > diffa){
            debug(x[i]);
            debug(x[i-1]);
            debug(c[i]);
            debug(c[i-1]);
            // cout<<"Kal se"<<endl;
            cout<<"NO"<<endl;
            return;
        }

    }

    vector<char> ans(n);
    string s = "abc";
    int ptr = 0;

    ans[0] = 'a';
    ans[1] = 'b';
    int curr = 2; // curr se fill krna hai 
    int fulfilled = 2;
    char ch = 'c';
    for(int i = 0; i<k;i++){
        int len = x[i] - curr;
        int required = c[i] - fulfilled;
        for(int j = 0; j<required; j++){
            ans[curr] = ch;
            curr++;
        }
        for(int j = 0; j<len-required; j++){
            ans[curr] = s[ptr%3];
            ptr++;
            curr++;
        }
        curr = x[i];
        fulfilled = c[i];
        ch++;
    }

    cout<<"YES"<<endl;

    for(auto x : ans){
        cout<<x;
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

