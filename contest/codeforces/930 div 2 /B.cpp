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

        // take 2 binary strings as input 
        string a1,a2;
        cin>>a1>>a2;    

        string ans="";
        ans+=a1[0];
        int brk = n-1;
        bool f=false;
        int i=1,j=0;
        while(i<n && j<n){
            if(a1[i]=='1' && a2[j]=='0'){
                f=true;
                brk = j;
                break;
            }
            if(!f){
                ans+=a1[i];
                i++;
                j++;
            }
        }
        debug(brk);

        if(f) ans+=a2.substr(j,n-j);
        else ans += a2[n-1];
            
        //cout<<"ans->" <<ans<<endl;
        
        vector<string>v(n,"");

        for(int k=n-2;k>=0;k--){
            string s="";
            s+=a2[k+1];
            s+=v[k+1];
            v[k]+=s;
        }

        //print(v);

        vector<string>v1(n+1,"");

        for(int k=n-1;k>=0;k--){
            string s="";
            s+=ans[k+1];
            s+=v1[k+1];
            v1[k]+=s;
        } 

        //print(v1);
        int count=0;
        for(int i=0;i<brk;i++){
            if(a1[i+1]==a2[i]){
                if(v1[i+1]==v[i])
                    count++;
            }
        }
        cout<<ans<<endl;
        cout<<count+1<<endl;
        
    
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

