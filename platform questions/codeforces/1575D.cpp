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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    string str;
    cin>>str;

    if(str[0] == '0' and str.size() == 1){
        cout<<1<<endl;
        return;
    }
 
    if(str[0] == '0'){
        cout<<0<<endl;
        return;
    }
    
 
    if(str.size() == 1 and (str[0] == '_' or str[0] == 'X')){
        cout<<1<<endl;
        return;
    }

    string lo= "";
    string hi = "";

    for(int i = 0; i<str.size(); i++){
        if(i==0) lo+='1';
        else lo += '0';
        hi += '9';
    }


    int xx = stoi(lo);
    int yy = stoi(hi);

    int ans = 0;

    

    for(int i = (str.size() == 2) ? 25 : xx; i<=yy; i+=25){
        char currx = 'a';
        string curr = to_string(i);
        bool poss = true;
        for(int j = 0; j<str.size(); j++){
            if(str[j] =='_')continue;
            if(str[j] >= '0' and str[j] <= '9'){
                if(curr[j] != str[j]) {
                    poss= false;
                    break;
                }
            }

            if(str[j] == 'X'){
                debug(currx);
                debug(curr[j]);
                
                if(currx == 'a'){
                    currx = curr[j];
                }
                
                if(curr[j] != currx){
                    poss = false;
                    debug(poss);
                    print(curr);
                    break;
                }
                
            }
        }
        if(poss) {
            ans++;  
            print(curr);
        }
    }

    cout<<ans<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

