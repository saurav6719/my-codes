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

bool poss(int mid , vector<pair<int,int> > &input){
    int curr;
    int curr2 = 0;
    int cnt = mid;
    int cnt2 = 0;
    for(int i = 0;i<input.size(); i++){
        curr = min(cnt, input[i].second);
        if(input[i].first > (curr)) return false;
        cnt = curr;
        cnt += mid;
        //if(mid == 7) debug(curr);
        curr2 = max(cnt2, input[i].first);
        if(input[i].second < curr2) return false;
        cnt2 = curr2;
        cnt2 -= mid;
        //if(mid == 7) debug(curr2);
    }
    return true;
}



bool overlapping(int l1, int r1, int l2, int r2){
    if(l1<=r2 and r1>=l2) return true;
    return false;
}

void solvee(){
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }
    
    for(int i = 0; i<n; i++){
        cout<<input[i].first<<"f"<<input[i].second<<"g";
    }

}



void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }

    int mx = abs(input[0].first);

    for(int i = 0; i<input.size() -1; i++){

        int mini = INT_MAX;
        int a = input[i].first;
        int b = input[i].second;
        int c = input[i+1].first;
        int d = input[i+1].second;
        if(overlapping(a,b,c,d)) continue;
        int aa = abs(a-c);
        int bb = abs(a-d);
        int cc = abs(b-c);
        int dd = abs(b-d);
        mini = mn(mini,bb,cc);
        mini = mn(mini,aa,dd);
        mx = max(mx,mini);

        
    }

    debug(mx);

    int lo = 0;
    int hi = 1e9+5;
    int res = -1;
    while(lo<=hi){
        
        int mid = (lo+hi)/2;

        //debug(mid);
        if(poss(mid, input)){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid+1;
    }

    cout<<res<<endl;


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
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

