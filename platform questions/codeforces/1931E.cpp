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
int maxlz(int n){
    int cnt = 0;
    while(n!=0){
        if(n%10 == 0) cnt++;
        else break;
        n/=10;
    }
    return cnt;
}

int f(int n){
    int cnt = 0;
    while(n!=0){
        cnt++;
        n/=10;
    }
    return cnt;
}

void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> input(n);
    vector<int> lz;
    int t = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        int xx = maxlz(input[i]);
        //debug(xx);
        if(xx!= 0) lz.push_back(xx);
        t+= f(input[i]);
    }
    //print(lz);

    sort(lz.begin(), lz.end(), greater<int> ());

    int cnt = 0;

    for(int i = 0; i<lz.size(); i+=2){
        cnt += lz[i];
    }

    if(t-cnt >= m+1) {
        cout<<"Sasha"<<endl;
    }
    else cout<<"Anna"<<endl;



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

