/**
 *    author: Saurav
 *    created: 2024.12.13 17:46:43
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
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    vector<int> a(n+1, 0);

    int cnt = 0;
    map<int,int> mpstart;

    int ans =0;

    for(int i = n-1; i>=k-1; i--){
        a[i] = a[i+1] - cnt;
        cnt -= mpstart[i+1];
        int check;
        if(a[i] >= b[i]) check = 0;
        else{
            int diff = b[i] - a[i];
            check = diff / k;
            if(diff % k) check++;
        }
        a[i] += check * k;
        cnt += check;
        mpstart[i-k+1] += check;
        ans += check;
    }

    for(int i = k-2; i>=0; i--){
        a[i] = a[i+1] - cnt;  
        cnt -= mpstart[i+1];
        int check;
        if(a[i] >= b[i]) check = 0;
        else{
            int diff = b[i] - a[i];
            check = diff / (i+1);
            if(diff % (i+1)) check++;
        }
        a[i] += check * (i+1);
        cnt += check;
        mpstart[0] += check;
        ans += check;
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

    t = 1;
    while(t--){
        solve();
    }
return 0;
}

