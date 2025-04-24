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
        int a = 0;
        int b = 1;
        char last;
        char next;
        vector<char> alphabets;

        for(int i = 0; i<26; i++){
            alphabets.push_back(i+'a');
        }
        print(alphabets);
        while(b<n){
            if(a>0) last = str[a-1];
            if(b<n-1) next = str[b+1];
            set<char> st;
            if(str[a] == str[b]){
                if(a>0) st.insert(last);
                if(b<n-1) st.insert(next);
                st.insert(str[a]);
                for(int i = 0; i<26; i++){
                    if(st.count(alphabets[i]) == 0){
                        str[b] = alphabets[i];
                        break;
                    } 
                }
            }
            a++;
            b++;
        }

        cout<<str;
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

