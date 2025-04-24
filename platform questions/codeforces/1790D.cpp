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
    map<int,int> freq;
    for(int i = 0; i<n; i++){
        freq[input[i]]++;
    }

    int cnt = 0;
    int mini;
    int last;
    for(auto ele : freq){
        int val = ele.second;
        cnt += val;
        mini = ele.second;
        last = ele.first;
        break;
    }
    debug(cnt);
    debug(mini);
    
    bool ff = true;
    for(auto ele : freq){
        if(ff){
            ff = false;
            continue;
        }
        int val = ele.second;
        int key = ele.first;
        debug(key);
        debug(val);
        debug(mini);
        debug(last);
        if(key != last + 1){
            cnt += val;
            mini = val;
            last = key;
            continue;
        }
        if(val <= mini){
            mini = min(mini, val);
            last = key;
            continue;
        }

        else{
            cnt += val - mini;
            mini = val;
            last = key;
            continue;
        }
    }

    cout<<cnt<<endl;


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

