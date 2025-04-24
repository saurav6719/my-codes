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

vector<int> twopower(31);

int power(int a, int x, int p = mod){
    //finding a to the power x
    int res = 1;
    a = a % p;
    while(x>0){
        if(x & 1){
            res = (res * a) % p;
        }
        x = x >> 1;
        a = (a * a) % p;
    }
    return res;

}

void solve(){
    int n,q;
    cin>>n>>q;
    set<int> st;
    vector<int> input1(n);
    vector<int> input2(q);
    vector<int> ff;
    for(int i = 0; i<n; i++){
        cin>> input1[i];
    }
    
    for(int i= 0; i<q; i++){
        cin>>input2[i];
        if(!st.count(input2[i])){
            ff.push_back(input2[i]);
        }
        st.insert(input2[i]);
    }
    print(input1);
    print(input2);
    print(ff);

    for(int i = 0; i<n; i++){
        int ele = input1[i];
        //debug(ele);
        for(int i = 0; i<ff.size(); i++){
            int pow = twopower[ff[i]];
            if(ele % pow == 0){
                ele += twopower[ff[i]-1];
                debug(ele);
            }
        }
        input1[i] = ele;
    }

    for(int i = 0; i<n; i++){
        cout<<input1[i]<<" ";
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
    
    twopower[0] = 1;
    for(int i = 1; i<=30; i++){
        twopower[i] = power(2,i);
    }
    
    while(t--){
        solve();
    }
return 0;
}

