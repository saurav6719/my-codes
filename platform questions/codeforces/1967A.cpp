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
    int k;
    cin>>k;
    vector<int> input(n);

    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    if(n==1){
        cout<<input[0]+k<<endl;
        return;
    }

    sort(input.begin(), input.end());

    vector<int> diff;
    for(int i = 1; i<n; i++){
        diff.push_back(input[i] - input[i-1]);
    }

    int cnt = 1;
    for(int i = 0; i<diff.size(); i++){
        diff[i]*= cnt;
        cnt++;
    }

    for(int i = 1; i<diff.size(); i++){
        diff[i] += diff[i-1];
    }

    print(diff);

    int xx = lower_bound(diff.begin(), diff.end(), k) - diff.begin();
    if(xx<n-1 and diff[xx] == k) xx++;

    

    for(int i = 0; i<xx; i++){
        if(xx<n) input[i] = input[xx];
        else input[i] = input[n-1];
    }

    debug(xx);

    if(xx-1 <n-1 and xx-1 >=0) k -= diff[xx-1];
    else if(xx-1 == n-1) k -= diff[n-2];
    

    if(k>0){
        int fill = k / (xx+1);
        int rem = k % (xx+1);

        for(int i = 0;i<=min(xx, n-1); i++){
            input[i] += fill;
        }

        for(int i = 0; i < min(rem, n) ; i++){
            input[i] ++;
        }
    }

    
    sort(input.begin(), input.end());
    print(input);
    int cnt2 = 0;
    for(int i = 0; i<n; i++){
        if(input[i] ==  input[0]) cnt2++;
        else break;
    }

    debug(cnt2);

    int ans = 0;

    ans += ((n-cnt2) * input[0]);

    ans += input[0];

    ans += ((input[0]-1 ) * (cnt2-1));
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

