#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
int m,n;

struct helper{
    int t,z,y;
};

int blown(helper x, int time){
    int result = 0;
    result += x.z * (time /( x.t * x.z + x.y));
    int rem = time % ( x.t * x.z + x.y);
    if(rem >= (x.t * x.z)) result += x.z;
    else result += rem/x.t;
    return result;
}

bool poss(int m, int time, vector<helper> &h){
    int res = 0;
    for(auto x : h){
        res += blown(x,time);
    }
    return res >= m;
}

void solve(){
    
    cin>>m>>n;
    vector<helper> h(n);
    for (auto &x : h){
        cin>>x.t>>x.z>>x.y;
    }

    int lo = 0;
    int hi = 1e9;
    int res = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (poss(m,mid,h)){
            res = mid;
            hi = mid -1;
        }
        else lo = mid +1;
    }
    cout<<res<<endl;

    for(int i = 0; i<n; i++){
        if(i>0) cout<<" ";
        int x = blown(h[i],res);
        cout<<min(x,m);
        m-= min(m,x);
    }
    cout<<endl;
    
}
int32_t main(){
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