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
    st[i] =(st[2*i+1]%mod * st[2*i+2]%mod) %mod;
}
int getSum(int i, int lo, int hi, int l, int r){ // we are finding max in l to r
    // out of range 
    if(l>hi or r<lo) return 1;
    //subset
    if(lo>=l and hi <=r) return st[i];
    int mid = lo + (hi-lo)/2;
    int left = getSum(2*i+1,lo,mid,l,r);
    int right = getSum(2*i+2,mid+1,hi,l,r);
    return (left%mod * right%mod)%mod;
}

void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end());
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        mp[input[i]]++;
    }

    vector<int> values;
    vector<int> freq;

    for(auto ele : mp){
        values.push_back(ele.first);
        freq.push_back(ele.second);
    }

    print(values);
    print(freq);

    n = freq.size();

    st.resize(4*n);
    buildTree(freq,0,0,n-1);

    print(st);

    int ans = 0;

    for(int i = 0; i<n; i++){
        if(i+m-1 < n){
            if(values[i+m-1] == values[i] + m-1){
                debug(input[i]);
                debug(input[i+m-1]);
                debug(i);
                debug(i+m-1);
                debug(getSum(0,0,n-1,i, i+m-1));
                ans += getSum(0,0,n-1,i, i+m-1);
                ans %= mod;
            }
        }
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

