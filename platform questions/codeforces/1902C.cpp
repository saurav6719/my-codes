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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    set<int> st;
    int maxi  = INT_MIN;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        st.insert(input[i]);
        maxi = max(maxi, input[i]);
    }

    if(n==1) {
        cout<<1<<endl;
        return;
    }

    vector<int> diff;

    for(int i = 1; i<n; i++){
        diff.push_back(abs(input[i] - input[i-1]));
    }

    print(diff);

    int gc = diff[0];
    for(int i = 0 ; i<diff.size(); i++){
        gc= gcd(gc, diff[i]);
    }

    debug(gc);

    int ans;

    int ff = maxi + gc;
    debug(ff);
    int cost1 = 0;
    int cost2 = 0;
    for(int i = 0; i<n; i++){
        cost1 += ((ff - input[i])/gc); 
    }
    debug(cost1);
    int ss = maxi - gc;
    while(true){
        if(st.count(ss) == 0){
            break;
        }
        ss-=gc;
    }

    debug(ss);

    cost2 += (maxi - ss)/gc;
    debug(cost2);
    debug(maxi);
    for(int i = 0; i<n; i++){
        cost2 += (maxi - input[i])/gc;
        debug(cost2);
    }

    ans = min(cost1, cost2);
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

