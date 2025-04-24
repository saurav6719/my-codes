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

struct type{
    int left;
    int right;
    int index;
};

bool cmp(type x1, type x2) {
    if (x1.left == x2.left) {
        return x1.right > x2.right;
    }
    return x1.left < x2.left;
}


void solve(){
    int n;
    cin>>n;
    vector<type> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].left>>input[i].right;
        input[i].index = i+1;
    }
    sort(input.begin(), input.end(), cmp);

    // for(int i = 0; i<input.size(); i++){
    //     cout<<input[i].left<<" "<<input[i].right<<" "<<input[i].index<<endl;
    // }
    vector<bool> contained(n+5,false);
    vector<bool> contains(n+5,false);
    int maxR = 0;
    int minR = INT_MAX;

    for(int i = 0; i<n; i++){
        debug(maxR);
        if(maxR >= input[i].right){
            contained[input[i].index] = true;
            debug(input[i].index);
        }
        maxR = max(maxR, input[i].right);
    }

    for(int i = n-1; i>=0; i--){
        if(minR <= input[i].right){
            contains[input[i].index] = true;
        }
        minR = min(minR, input[i].right);
    }

    for(int i = 1; i<=n; i++){
        if(contains[i] == true) cout<<"1"<<" ";
        else cout<<"0"<<" ";
    }
    cout<<endl;

    for(int i = 1; i<=n; i++){
        if(contained[i] == true) cout<<1<<" ";
        else cout<<0<<" ";
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

