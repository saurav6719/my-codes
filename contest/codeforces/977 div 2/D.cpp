/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav            |
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n+1);
    vector<int> b(m+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }

    // Corrected loop: Start from i=1 to i <=m
    map<int, int> firstoccr;
    for(int i = 1; i <= m; i++){
        int ele = b[i];
        if(firstoccr.find(ele) == firstoccr.end()){
            firstoccr[ele] = i;
        }
    }

    map<int, set<int>> mp;
    for(int i = 1; i <= m; i++){
        mp[b[i]].insert(i);
    }

    // Insert m+1 as a sentinel for elements not present in b
    for(int i = 1; i <= n; i++){
        if(mp[i].empty()){
            mp[i].insert(m+1);
        }
    }

    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        if(firstoccr.count(i)){
            v[i] = firstoccr[i];
        }
        else {
            v[i] = m + 1;
        }
    }

    int inversioncnt = 0;
    for(int i = 1; i < n; i++){
        if(v[i] > v[i+1]){
            inversioncnt++;
        }
    }

    print(v);

    if(inversioncnt > 0){
        cout << "TIDAK" << endl;
    }
    else{
        cout << "YA" << endl;
    }

    while(q--){
        int idx, newperson;
        cin >> idx >> newperson;
        
        // Store the old value at b[idx]
        int puranapresenter = b[idx];
        b[idx] = newperson;

        debug(inversioncnt);
        debug(puranapresenter);
        debug(newperson);

        // Decrement inversion count based on old value
        if(puranapresenter > 1){
            if(v[puranapresenter] < v[puranapresenter - 1]){
                inversioncnt--;
            }
        }
        if(puranapresenter < n){
            if(v[puranapresenter] > v[puranapresenter + 1]){
                inversioncnt--;
            }
        }

        // Decrement inversion count based on new person before update
        if(newperson + 1 <= n && v[newperson] > v[newperson + 1]){
            inversioncnt--;
        }
        if(newperson - 1 >= 1 && v[newperson] < v[newperson - 1]){
            inversioncnt--;
        }

        print(v);
        debug(inversioncnt);

        // Corrected map key check
        mp[puranapresenter].erase(idx);

        // Corrected condition to check mp[puranapresenter]
        if(mp[puranapresenter].empty()){
            mp[puranapresenter].insert(m + 1);
        }

        mp[newperson].insert(idx);

        // Update v[puranapresenter] and v[newperson]
        v[puranapresenter] = *mp[puranapresenter].begin();
        v[newperson] = *mp[newperson].begin();

        // Increment inversion count based on updated values
        if(puranapresenter > 1){
            if(v[puranapresenter] < v[puranapresenter - 1]){
                inversioncnt++;
            }
        }
        if(puranapresenter < n){
            if(v[puranapresenter] > v[puranapresenter + 1]){
                inversioncnt++;
            }
        }
        if(newperson + 1 <= n && v[newperson] > v[newperson + 1]){
            inversioncnt++;
        }
        if(newperson - 1 >= 1 && v[newperson] < v[newperson - 1]){
            inversioncnt++;
        }

        // Output the result based on inversion count
        if(inversioncnt > 0){
            cout << "TIDAK" << endl;
        }
        else{
            cout << "YA" << endl;
        }
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
    cin >> t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}
