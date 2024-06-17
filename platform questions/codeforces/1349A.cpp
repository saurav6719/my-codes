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
#define pp pair<int,int> 
using namespace std;

/* write core logic here */

vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    
    // Check for the number of 2s that divide n
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count > 0) {
        factors.push_back(make_pair(2, count));
    }

    // Check for odd factors from 3 onwards
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            factors.push_back(make_pair(i, count));
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(make_pair(n, 1));
    }

    return factors;
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++)
        cin>>input[i];
    
    vector<vector<pp> > pf(n);
    
    for(int i = 0; i<n; i++){
        pf[i] = primeFactorization(input[i]);
    } 

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<pf[i].size(); j++){
    //         cout<<pf[i][j].first<<" "<<pf[i][j].second<<endl;
    //     }
    //     cout<<endl;
    // }

    vector<vector<int> > occr(200005);
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<pf[i].size(); j++){
            pp ele = pf[i][j];
            mp[ele.first]++;
            occr[ele.first].push_back(ele.second);
        }
    }

    for(int i = 0; i<occr.size(); i++){
        sort(occr[i].begin(), occr[i].end());
    }

    set<int> st;

    for(auto ele : mp){
        if(ele.second == n or ele.second == n-1) st.insert(ele.first);
    }

    // for(int i = 2; i<=11; i++){
    //     for(int j = 0; j<occr[i].size(); j++){
    //         cout<<occr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(auto ele : st){
    //     cout<<ele<<" ";
    // }

    

    // cout<<endl<<endl;

    vector<pp> ans;

    // for(auto ele : mp){
    //     cout<<mp[]
    // }

    for(auto ele : st){
        if(mp[ele] == n){
            ans.push_back({ele, occr[ele][1]});
        }
        else{
            ans.push_back({ele, occr[ele][0]});
        }
    }

    int answer = 1;
    for(auto ele : ans){
        int x  = ele.first;
        int y = ele.second;
        for(int i = 0; i<y; i++){
            answer *= x;
        }
    }

    cout<<answer<<endl;


    
    
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

