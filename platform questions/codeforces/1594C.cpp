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
    char ch;
    cin>>ch;
    string str;
    cin>>str;
    set<int> st;
    bool allodd = true;
    for(int i = 0; i<n; i++){
        if(str[i] != ch) {
            st.insert(i);
            if(i&1) allodd = false;
        }
        
    }
    if(st.size() == 0){
        cout<<0<<endl;
        return;
    }

    if(st.size() == 1){
        int that = -1;
        for(auto ele : st){
            that = ele;
        }
        if(that >1 ){
            cout<<1<<endl;
            cout<<that<<endl;
            return;
        }
        else if(that == 1){
            cout<<1<<endl;
            cout<<3<<endl;
            return;
        }
        else{
            cout<<1<<endl;
            cout<<2<<endl;
            return;
        }
    }
    if(st.size() > 1){
        if(str[n-1] == ch){
            cout<<1<<endl;
            cout<<n<<endl;
            return;
        }
        else if(str[n-2] == ch){
            cout<<1<<endl;
            cout<<n-1<<endl;
            return;
        }
        
        else{
            char last = str[n-1];
            char slast = str[n-2];
            int idx = -1;
            for(int i = n-3;i>=0;i--){
                if(str[i] != ch) continue;
                idx = i;
                break;
            } 
            if(idx == -1){
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
                return;
            }     
            else{
                for(int i = n-1; i>=0; i--){
                    if(str[i] == ch) break;
                    if(((i+1) % (idx+1)) == 0){
                        cout<<2<<endl;
                        cout<<n-1<<" "<<n<<endl;
                        return;
                    }
                }
                cout<<1<<endl;
                cout<<idx+1<<endl;
                return;
            }       
            
        }
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

