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

vector<vector<int> > st;
void build(int i, int lo, int hi, vector<int> &arr, vector<int> &v){
    if(lo == hi){
        st[i].push_back(arr[lo]);
        return;
    }
    int mid = lo + (hi - lo)/2;
    build(2*i+1, lo, mid, arr, v);
    build(2*i+2, mid +1 , hi, arr, v);
    int sz = st[2*i+1].size();
    sz += st[2*i+2].size();
    
    int a = 0;
    int j = 0;
    while(a<st[2*i+1].size() and j < st[2*i+2].size()){
        if(st[2*i+1][a] <= st[2*i+2][j]){
            st[i].push_back(st[2*i+1][a]);
            a++;
        }
        else{
            st[i].push_back(st[2*i+2][j]);
            j++;
        }
    }

    while(a<st[2*i+1].size()){
        st[i].push_back(st[2*i+1][a]);
        a++;
    }

    while(j < st[2*i+2].size()){
        st[i].push_back(st[2*i+2][j]);
        j++;
    }
}

int get (vector<int> &v, int k){
    int xx = lower_bound(v.begin(), v.end(), k) - v.begin();
    return xx;
}

int answer(int i, int lo, int hi , int l, int r, int k){
    if(l> hi or r<lo) return 0;
    if(lo>=l and hi <= r) return get(st[i] , k);

    int mid = lo + (hi-lo)/2;
    int left = answer(2*i+1, lo, mid, l,r,k);
    int right = answer(2*i+2, mid+1, hi, l, r, k);
    return left + right;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    st.resize(4*n , vector<int> ());
    
    map<int,int> mp1;
    vector<int> iii(n);
    for(int i = 0; i<n; i++){
        mp1[input[i]]++;
        iii[i] = mp1[input[i]];
    }


    map<int,int> mp2;
    vector<int> jjj(n);
    for(int i = n-1; i>=0; i--){
        mp2[input[i]]++;
        jjj[i] = mp2[input[i]];
    }

    
    print(jjj);
    vector<int> v;
    build(0,0,n-1, jjj, v);

    // for(int i = 0; i<(4*n); i++){
    //     cout<<i<<" -> ";
    //     for(int j = 0; j<st[i].size(); j++){
    //         cout<<st[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> ans(n);
    print(iii);
    for(int i = 0; i<n; i++){
        ans[i] = answer(0,0,n-1, i+1, n-1, iii[i]);
    }

    print(ans);

    int res = 0;
    for(auto ele: ans){
        res += ele;
    }
    cout<<res;




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

