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
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        input[i].second = i;
    }

    sort(input.begin(), input.end());

    int cnt = 0;

    for(int i = 1; i<n; i++){
        cnt += ((n-i) * (input[i].first -input[i-1].first));
    }
    //cnt++;
    cnt+=n;
    //debug(cnt);

    vector<int> ans;
    ans.push_back(cnt);
    for(int i = 1; i<n; i++){
        int xx = lower_bound(input.begin(), input.end(), input[i]) - input.begin();
        
        int yy = upper_bound(input.begin(), input.end(), input[i-1]) - input.begin();
        yy--;
        xx = n-xx;
        //debug(xx);
        yy = yy+1;
        //debug(yy);
        int last = ans[ans.size() - 1];
        xx *= (input[i].first - input[i-1].first);
        yy *= (input[i].first - input[i-1].first);
        last -= xx;
        last += yy;
        ans.push_back(last);
    }

    //print(ans);

    vector<int> final(n);

    for(int i = 0; i<n; i++){
        final[input[i].second] = ans[i];
    }

    for(int i = 0; i<n; i++){
        cout<<final[i]<<" ";
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

