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
    string str;

    cin>>str;
    int n = str.size();
    int idx;
    cin>>idx;

    if(idx<=n){
        cout<<str[idx-1];
        return;
    }

    map<int,char> mp;

    for(int i = 0; i<str.size(); i++){
        mp[i] = str[i];
    }

    int req = 0;

    int curr = str.size();
    int a = 1;
    while(idx > (curr + (n - a))){
        debug(curr);
        req++;
        curr += n - a;
        a++;
    }

    debug(req);

    int rem = idx- curr;
    debug(rem);

    vector<int> remove;

    stack<pair<int,char> > st;

    for(int i = 0; i<n; i++){
        if(st.empty()){
            st.push({i, str[i]});
            continue;
        }
        while(!st.empty() and st.top().second > str[i]){
            remove.push_back({st.top().first});
            st.pop();
        }
        st.push({i, str[i]});
    }


    while(!st.empty()){
        remove.push_back({st.top().first});
        st.pop();
    }

    print(remove);

    set<int> setti;
    for(int i = 0; i<=req; i++){
        setti.insert(remove[i]);
    }

    string ans = "";
    for(int i = 0; i<n; i++){
        if(setti.count(i) == 0){
            ans += str[i];
        }
    }

    print(ans);

    int chota = 0;
    int agla = remove[req];
    for(auto ele : setti){
        if(ele < agla) chota++;
    }

    debug(chota);


    cout<<ans[rem-1];





    // if(remove[req]){

    // }






    


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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

