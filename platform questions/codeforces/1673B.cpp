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
    string str;
    cin>>str;
    int n = str.size();
    map<char,int> st;
    map<char,int> fre;
    for(int i = 0; i<n; i++){
        if(st[str[i]] == 0){
            st[str[i]] = i;  
            fre[str[i]]++;
        }
        else{
            int mini = INT_MAX;
                int maxi = INT_MIN;
            for(auto ele : st){
                if(ele.second < st[str[i]] and ele.first != str[i]){
                    debug(i);
                    cout<<"NO"<<endl;
                    return;
                }
                

                
            }
        st[str[i]] = i;
        fre[str[i]]++;
        for(auto ele : fre){
            if(ele.second > maxi ) maxi = ele.second;
            if(ele.second < mini) mini = ele.second;
        }
        if(maxi - mini > 1){
            cout<<"NO"<<endl;
            return;
        }
        }
    }
    cout<<"YES"<<endl;
    return;
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

