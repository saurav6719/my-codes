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
    int n;
    cin>>n;
    string str;
    cin>>str;

    if(str[n-1] == '0'){
        cout<<"NO"<<endl;
        return;
    }

    if(str[0] == '0'){
        cout<<"NO"<<endl;
        return;
    }

    int cnto = 0;
    int cntz = 0;
    for(int i =0; i<n;i++){
        if(str[i] == '1') cnto++;
        else cntz++;
    }

    if(cnto&1 or cntz &1 ){
        cout<<"NO"<<endl;
        return;
    }

    vector<char> one(n);
    vector<char> two(n);
    int curro = 0;
    for(int i =0; i<n; i++){
        if(str[i] == '1'){
            if(curro < (cnto / 2)){
                one[i] = '(';
                two[i] = '(';
                curro++;
            }
            else{
                one[i] = ')';
                two[i] = ')';
                curro++;
            }
        }
    }
    int curr =0;

    for(int i =0; i<n; i++){
        if(str[i] == '0'){
            if(curr == 0){
                one[i] = '(';
                two[i] = ')';
                curr ^= 1;
            }
            else{
                one[i] = ')';
                two[i] = '(';
                curr ^= 1;
            }
        }
    }
    cout<<"YES"<<endl;

    for(int i = 0; i<n; i++){
        cout<<one[i];
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<two[i];
    }
    cout<<endl;
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

