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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> closest(n);
    closest[0] = 1;
    closest[n-1] = n-2;
    for(int i = 1; i<n-1; i++){
        if(abs(input[i] - input[i-1]) < abs(input[i] - input[i+1])){
            closest[i] = i-1;
        }
        else closest[i] = i+1;
    }
    print(closest);


    vector<int> inccost;
    inccost.push_back(0);
    for(int i = 1; i<n; i++){
        if(closest[i-1] == i) inccost.push_back(1);
        else inccost.push_back(abs(input[i-1] - input[i]));
    }

    print(inccost);
    for(int i = 1; i<n; i++){
        inccost[i] = inccost[i-1] + inccost[i];
    }
    print(inccost);

    vector<int> deccost;
    deccost.push_back(0);
    for(int i = n-2; i>=0; i--){
        if(closest[i+1] == i) deccost.push_back(1);
        else deccost.push_back(abs(input[i+1] - input[i]));
    }
    
    reverse(deccost.begin(), deccost.end());

    print(deccost);
    for(int i = n-2; i>=0; i--){
        deccost[i] = deccost[i+1] + deccost[i];
    }
    print(deccost);

    int m;
    cin>>m;
    while(m--){
        int l ;
        cin>>l;
        int r;
        cin>>r;
        l--;
        r--;
        if(r>l){
            cout<<inccost[r] - inccost[l]<<endl;
        }
        else cout<<deccost[r] - deccost[l]<<endl;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

