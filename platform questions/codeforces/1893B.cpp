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
    int n;int m;
    cin>>n>>m;
    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(m);

    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    set<int> st;
    for(auto ele : a){
        st.insert(ele);
    }

    map<int,vector<int> > mp;

    for(int i = 0; i<n; i++){
        mp[a[i]].push_back(i);
    }

    map<int,vector<int> > mp2;

    for(int i = 0; i<n; i++){
        mp2[i].push_back(a[i]);
    }



    for(int i= 0; i<m; i++){
        int ele = b[i];
        debug(ele);

        auto it = st.lower_bound(ele);
        
        if(it == st.end()){
            //at begining
            debug(ele);
            st.insert(ele);
            mp2[0].push_back(ele);
            
            mp[ele].push_back(0);
        }
        else{
            int justupper = *it;
            debug(justupper);
            int lastposition = mp[justupper].back();
            debug(lastposition);
            mp[ele].push_back(lastposition) ;
            mp2[lastposition].push_back(ele);
            st.insert(ele);
        }
    }

    for(auto ele : mp2){
        vector<int> &v = ele.second;
        sort(v.begin(), v.end(), greater<int> ());
        for(auto ele2 : v){
            cout<<ele2<<" ";
        }
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

