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

struct Edge{
    int src;
    int des; 
    int wt;
};

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.first > p2.first;
}




void solve(){
    int n;
    cin>>n;
    vector<int> input(n+1);
    int sum = 0;
    for(int i = 1; i<=n; i++){
        cin>>input[i];
        sum += input[i];
    }

    vector<pair<int,int> > pp;
    

    


    

    
    vector<int> deg(n+5, 0);
    vector<vector<int> > graph(n+5);
    vector<Edge> v(n-1);
    for(int i = 0; i<n-1; i++){
        int ele1;
        cin>>ele1;
        int ele2;
        cin>>ele2;
        v[i].src = ele1;
        v[i].des = ele2;
        v[i].wt = input[ele1] + input[ele2];
        deg[ele1]++;
        deg[ele2]++;
    }

    for(int i = 1; i<=n; i++){
        pp.push_back({input[i], deg[i]});
    }

    sort(pp.begin(), pp.end(), cmp);



    // for(auto ele: pp){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }

    // cout<<endl;
    // cout<<endl;




    vector<int> ans;

    ans.push_back(sum);

    int i = 0;
    for(int k = 2; k<=n-1; k++){
        while(pp[i].second <= 1) i++;
        sum += pp[i].first;
        pp[i].second--;
        ans.push_back(sum);
    }

    for(auto ele : ans){
        cout<<ele<<" ";
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

