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

    int k = 0;

    int n;
    cin>>n;
    int curr = n;

    vector<int> ans(n);

    while(k==0){
        vector<int> query(n, curr);
        query[n-1] = 1;
        cout<<"?";
        for(int i =0; i<n;i++){
            cout<<" "<<query[i];
        }

        cout<<endl;
        cout<<flush;
        cin>>k;

        if(k!=0){
            ans[n-1] = query[0];
            ans[k-1] = 1;
            break;
        }
        curr--;

        if(curr == 0){
            ans[n-1] = 1;
            break;
        }
    }

    int last = ans[n-1];

    int now = 2;
    while(now <= n){
        if(now == last){
            now ++;
            continue;
        }
        vector<int> query(n);
        for(int i = 0; i<n-1; i++){
            query[i] = n+1-now;
        }

        query[n-1] = n+1-last;

        cout<<"?";
        for(int i =0; i<n;i++){
            cout<<" "<<query[i];
        }

        cout<<endl;
        cout<<flush;
        cin>>k;
        ans[k-1] = now;
        now++;
    }

    cout<<"!";

    for(auto ele : ans){
        cout<<" "<<ele;
    }
    cout<<endl;
    cout<<flush;

}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

