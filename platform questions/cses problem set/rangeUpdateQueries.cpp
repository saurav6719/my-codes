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
vector<int> st;
vector<int> lazy;

void build(int i, int lo, int hi , vector<int> &input){
    if(lo==hi){
        st[i] = input[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*i+1, lo, mid, input);
    build(2*i+2, mid+1, hi, input);
    st[i] = st[2*i+1] + st[2*i+2];
}

void update(int i, int lo, int hi, int l, int r, int val){
    if(lazy[i] != 0){
        int range = hi - lo +1;
        st[i] += range * lazy[i];
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
            
        }
        lazy[i] = 0;
    }

    if(l>hi or r<lo){
        return;
    }

    if(lo >=l and hi <= r){
        int range = hi - lo +1;
        st[i] += (range * val);
        if(lo != hi){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        
        return ;
    }

    int mid = (lo + hi) / 2;

    update(2*i+1, lo, mid, l, r, val);
    update(2*i+2, mid+1, hi, l, r, val);
    st[i] = st[2*i+1] + st[2*i+2];
}

int getsum(int i, int lo, int hi, int l , int r){
    if(lazy[i] != 0){
        int range = hi - lo +1;
        st[i] += range * lazy[i];
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
            
        }
        lazy[i] = 0;
    }
    if(l>hi or r<lo){
        return 0;
    }
    if(lo >=l and hi <= r){
        return st[i];
    }
    int mid =(hi + lo)/2;
    int left = getsum(2*i+1, lo, mid, l,r);
    int rightsum = getsum(2*i+2, mid+1, hi, l, r);

    return left + rightsum;
    
}
void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    st.resize(4*n);
    lazy.resize(4*n, 0);
    build(0, 0, n - 1, input);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int l,r,val;
            cin>>l>>r>>val;
            l--;
            r--;
            update(0, 0, n-1, l, r,val);
        }
        else{
            int k;
            cin>>k;
            k--;
            int xx = getsum(0, 0,n-1, k, k);
            cout<<xx<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

