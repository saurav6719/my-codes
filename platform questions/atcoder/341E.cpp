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
void buildTree(vector<int> &arr, int i, int lo, int hi){
    if(lo==hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i] = (st[2*i+1] & st[2*i+2]);
}

void update(vector<int> &arr, int i, int lo, int hi, int idx, int value){
    arr[idx] = value; // updating in original array
    if(idx == lo and idx == hi){
        st[i] = value;
        return;
    }
    int mid = lo+(hi-lo)/2;
    if(mid >= idx) update(arr,2*i+1,lo,mid,idx,value);
    if(mid < idx) update(arr,2*i+2,mid+1,hi,idx,value);
    st[i] = (st[2*i+1] & st[2*i+2]);
}

int getAnd(int i, int lo, int hi, int l, int r){ // we are finding max in l to r
    // out of range 
    if(l>hi or r<lo) return 1;
    //subset
    if(lo>=l and hi <=r) return st[i];
    int mid = lo + (hi-lo)/2;
    int left = getAnd(2*i+1,lo,mid,l,r);
    int right = getAnd(2*i+2,mid+1,hi,l,r);
    return (left & right);
}


void solve(){
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;

    if(n==1){
        while(q--){
            int type;
            cin>>type;
            if(type==1){
                int l,r;
                cin>>l>>r;
                // cout<<"YES"<<endl;

            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<"Yes"<<endl;
            }
        }
        return;
    }

    vector<int> dp(n-1,0);

    for(int i = 0; i<n-1; i++){
        dp[i] = (str[i] - '0') ^ (str[i+1] - '0');
    }



    print(dp);

    st.resize(4*n);

    buildTree(dp,0,0,n-2);

    print(st);

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            print(dp);

            int l,r;
            cin>>l>>r;
            l--,r--;
            if(l-1>=0) update(dp,0,0,n-2,l-1,(dp[l-1] ^ 1));
            if(r<n-1) update(dp,0,0,n-2,r,(dp[r] ^ 1));
            print(dp);

        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            int xx = getAnd(0,0,n-2,l,r-1);
            debug(l);
            debug(r);
            debug(xx);

            if(xx) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

