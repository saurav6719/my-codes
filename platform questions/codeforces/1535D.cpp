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
    int n;
    cin>>n;
    int k = pow(2, (n-1)) - 1;
    n = pow(2, n);
    string str;
    cin>>str;

    vector<int> parents(n+5);
    vector<int> leftchild(n+5, -1);
    vector<int> rightchild(n+5, -1);

    int i = 0; 
    int j = k+1;

    while(i<n-2){
        parents[i] = j;
        parents[i+1] = j;
        i+= 2;
        j++;
    }
    parents[n-2] = -1;

    for(int i = 0; i<n-2; i+=2){
        int par = parents[i];
        leftchild[par] = i;
        rightchild[par] = i+1;
    }

    print(leftchild);
    print(rightchild);

    print(parents);

    vector<int> values(n);
    for(int i = 0; i<str.size(); i++){
        if(i<=k){
            if(str[i] == '0' or str[i] == '1') values[i] = 1;
            else values[i] = 2;
            continue;
        }

        if(str[i] == '0') values[i] = values[leftchild[i]];
        if(str[i] == '1') values[i] = values[rightchild[i]];
        if(str[i] == '?') values[i] = values[leftchild[i]] + values[rightchild[i]];
    }

    print(values);

    int q;
    cin>>q;
    while(q--){
        int idx;
        cin>>idx; idx--;
        char newval;
        cin>>newval;

        str[idx] = newval ;

        while(idx != -1){
            debug(idx);
            if(idx<=k){
                if(str[idx] == '0' or str[idx] == '1') values[idx] = 1;
                else values[idx] = 2;
                idx = parents[idx];
                continue;
            }
            if(str[idx] == '0') {
                values[idx] = values[leftchild[idx]];
                debug(leftchild[idx]);
            }
            if(str[idx] == '1') {
                values[idx] = values[rightchild[idx]];
                debug(rightchild[idx]);
            }
            if(str[idx] == '?') {
                values[idx] = values[leftchild[idx]] + values[rightchild[idx]];
                debug(leftchild[idx]);
                debug(rightchild[idx]);
            }
            
            
            idx = parents[idx];
        }

        cout<<values[n-2]<<endl;

        print(values);
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}