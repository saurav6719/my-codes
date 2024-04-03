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
#define ff 1e10
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

struct Compare {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        // Compare the second element of pairs
        return lhs.first > rhs.first;
    }
};
void solve(){
    
    int n;
    cin>>n;
    int size = n*(n-1)/2;
    vector<int> input(size);
    map<int,int> mp;
    for(int i = 0; i<size; i++){
        cin>>input[i];
        mp[input[i]]++;
    }

    if(n==2){
        cout<<input[0]<<" "<<input[0]<<endl;
        return;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for(auto ele : mp){
        pq.push({ele.first, ele.second});
    }

    vector<int> ans(n,ff);
    int i = n-1;
    int maxi = INT_MIN;

    while(!pq.empty()){
        int cnt = 0;
        pair<int,int>  freq = pq.top();
        // debug(freq.first);
        // debug(freq.second);
        maxi = max(maxi, freq.first);
        
        bool broke = false;
        int j = i;
        while(freq.second !=0) {
            if(ans[j] != ff) {
                break;
                cout<<"dfa"<<endl;
                broke = true;
            }
            ans[j] = freq.first;
            debug(j);
            debug(ans[j]);
            int temp = j;
            j = freq.second - temp;
            if(j>= temp) j = temp - 1;
            freq.second -= temp; 
            debug(freq.first);
            debug(freq.second);
        }
        if(!broke) pq.pop();
        while(ans[i] != ff) i--;
    }
    debug(i);
    debug(maxi);

    while(i>=0){
        ans[i] = maxi;
        i--;
    }

    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
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

