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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
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
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    vector<int> final;
    vector<int> ans;
    for(int i =  0; i<n; i++){
        cin>>input[i];
    }
    if(k==1){
        for(int i = 0; i<n; i++){
            cout<<0<<" ";
        }
        return;
    }
    if(k==2){
        for(int i = 1 ; i<n; i++){
            int med = min(input[i-1], input[i]);
            int notmed = max(input[i-1], input[i]);
            int cost = notmed-med;
            cout<<cost<<" ";
        }
        return;
    }
    int leftsum = 0;
    int rightsum = 0;
    set<pair<int,int> > left;
    set<pair<int,int> > right;
    vector<pair<int,int> > sorted;
    for(int i = 0; i<k; i++){
        sorted.push_back({input[i],i});
    }
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i<(k/2) + (k%2); i++){
        left.insert(sorted[i]);
        leftsum += sorted[i].first;
    }
    for(int i = k/2 + (k%2) ; i<k; i++){
        right.insert(sorted[i]);
        rightsum += sorted[i].first;
    }

    auto t = left.rbegin();
    final.push_back(t->first);
    ans.push_back((t->first * left.size() - leftsum) + (rightsum - (t->first * right.size())));
    for(int i = 1; i<n-k+1; i++){
        
        if(left.count({input[i-1], i-1})){
            left.erase({input[i-1], i-1});
            leftsum -= input[i-1];
        }
        
        
        else {
            right.erase({input[i-1], i-1});
            rightsum-= input[i-1];
        }
        
        if(*(left.rbegin()) < make_pair(input[k-1+i], k-1+i)){
             right.insert({input[k-1+i], k-1+i});
             rightsum += input[k-1+i];
        }
        else {
            left.insert({input[k-1+i], k-1+i});
            leftsum += input[k-1+i];
        }
        while(left.size() < k/2 + (k%2)){
            pair<int,int> z = (*(right.begin()));
            left.insert(z);
            leftsum += z.first;
            right.erase(z);
            rightsum -= z.first;
        }
        while(left.size() > k/2 + (k%2)){
            pair<int,int> z = (*(left.rbegin()));
            right.insert(z);
            rightsum += z.first;
            left.erase(z);
            leftsum -= z.first;
            
        }
        ans.push_back(((left.rbegin()->first) * left.size() - leftsum) + (rightsum - ((left.rbegin()->first) * right.size())));
    }

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
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

