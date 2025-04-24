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
    vector<set<int> >ans(n, set<int> ());
    sort(input.begin(), input.end());
    int last = input[n-1];
    //debug(last);
    for(int i = 0; i<n; i++){
        int ele = input[i];
        //debug(ele);
        if(last - ele <= 50){
            while(ele <= last + 25){
                ans[i].insert(ele);
                //debug(ele);
                if(ele % 10 == 0) break;
                ele += (ele%10);  
            }
        }
        else{
            ele += (ele%10);
            if(ele % 10 == 0){
                cout<<"No"<<endl;
                return;
            }
            int diff = last - ele;
            diff /= 20;
            ele += ((diff-1) * 20);
            while(ele <= last + 25){
                ans[i].insert(ele);
                ele += (ele%10);
            }
        }
    }

    map<int,int> mp;

    for(int i = 0; i<n; i++){
        for(auto ele : ans[i]){
            //debug(ele);
            mp[ele]++;
        }
    }

    for(auto ele : mp){
        if(ele.second == n){
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;
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

