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
    map<int,int> mpl;
    map<int,int> mpr;
    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        mini = min(mini, input[i]);
        mpr[input[i]] = i+1; 
        if(mpl.count(input[i]) == 0){
            mpl[input[i]] = i+1;
        }
    }

    // for(auto ele : mpl){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    // for(auto ele : mpr){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    
    vector<bool> exists(n,false);
    for(int i = 0; i<n; i++){
        exists[input[i]] = true;
    }
    int t = -1;
    
    for(int i = 0; i<n; i++){
        if(exists[i] == false){
            t= i;
            break;
        }
    }
    //debug(t);


    
    //print(mindx);
    if(mini != 0){
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<n<<endl;
        return;
    }
    if(t==-1){
        cout<<-1<<endl;
        return;
    }
    int aa = INT_MIN;
    for(int i = 0; i<t; i++){
        int xx = mpl[i];
        int yy = mpr[i];
        if(xx >= yy){
            cout<<-1<<endl;
            return;
        }
        aa = max(aa,xx);
    }
    for(int i = 0; i<t; i++){
        if(mpr[i] <= aa){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<1<<" "<<aa<<endl;
    cout<<aa+1<<" "<<n<<endl;


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

