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
using namespace __gnu_pbds;
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

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct person{
    int arrival;
    int departure;
    int roomalc;
    int index;
};


struct custom_compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Compare based on the first element (less priority)
        return a.first > b.first;
    }
};
void display(priority_queue<pair<int,int> >  pq){
    while(!pq.empty()){
        pair<int,int> pp = pq.top();
        cout<<pp.first<<" ,"<<pp.second<<"  ";
    }
}
bool cmp(person x, person y){
    return x.arrival<y.arrival;
}
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<person> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].arrival>>input[i].departure;
        input[i].index = i;
    }
    sort(input.begin(), input.end(), cmp);
    //cout<<input[0].arrival<<" "<<input[0].departure;
    int curr = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, custom_compare> pq;
    vector<int> ans(n);
    for(int i = 0; i<input.size(); i++){
        //debug(curr);
        int ele = input[i].arrival;
        int ele2 = input[i].departure;
        int idx = input[i].index;
        //debug(ele);
        if(pq.empty()){
            ans[idx] = curr;
            pq.push({ele2,curr});
            curr++;
            continue;
        }
        pair<int,int>  ff = pq.top();
        int f = ff.first;
        // debug(ele);
        // debug(pq.size());
        // debug(f);
        if(f<ele){
            pq.pop();
            ans[idx] = ff.second;
            pq.push({ele2, ff.second});
        }
        else{
            ans[idx] = curr;
            pq.push({ele2,curr});
            curr++;
        }
        //debug(pq.size());
    } 
    //debug(curr);
    cout<<curr-1<<endl;
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

