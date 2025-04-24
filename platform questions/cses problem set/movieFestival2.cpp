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
                        cout << v[i].first << " "<< v[i].second<<endl; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }
    sort(input.begin(), input.end(), cmp);
    print(input);

    multiset<int> st;
    int free = k;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        debug(cnt);
        int req = input[i].first;
        debug(req);
        bool watched = false;
        auto it = st.lower_bound(req);
        if((it == st.begin() and st.size() > 0)){
            //cout<<"FUivhasRST"<<endl;
            int ele = *it;
            if(ele == input[i].first){
                watched = true;
                cnt++;
                st.erase(ele);
                st.insert(input[i].second);
            }
        } 
        
        if(!watched and (it == st.begin() or it== st.end()) and free > 0){
            //cout<<"FURST"<<endl;
            free--;
            st.insert(input[i].second);
            cnt++;
            watched = true;
        }
        else if(!watched and it != st.begin() and it != st.end()){
            //cout<<"FUfqadeRST"<<endl;
            cnt++;
            watched = true;
            --it;
            st.erase(it);
            st.insert(input[i].second);
        }
        else if( !watched and it == st.end()){
            auto it = st.rbegin();
            cnt++;
            st.erase(*it);
            st.insert(input[i].second);
        }
    }
    cout<<cnt;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

