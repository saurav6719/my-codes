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
    return a.first > b.first;
}


void solve(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
    }


    if(k==1){
        cout<<input[n-1] - input[0] +1 ;
        return;
    }

    if(k==n){
        cout<<n<<endl;
        return;
    }

    vector<pair<int, int> >diff;
    for(int i = 1; i<n; i++){
        diff.push_back({input[i] - input[i-1] , i-1});
    }


    

    sort(diff.begin(), diff.end(), cmp);

    
    set<int> st;

    for(int i = 0; i<k-1; i++){
        st.insert(diff[i].second);
    }

    int ans = 0;
    int last = 0;

    for(auto ele : st){
        debug(ele);
        if(ele == 0){
            ans++;
            last = 1;
            continue;
        }

        ans += input[ele] - input[last]+1;
        last = ele + 1;
        debug(ans);
    }

    if(last != n){
        ans += input[n-1] - input[last]+1;
    }
    cout<<ans;

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

