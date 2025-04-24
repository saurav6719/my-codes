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

int f(vector<int> &v){
    int n = v.size();
    vector<bool> ok(n);
    int cntfalse = 0;
    for(int i =0; i<n; i++){
        if(v[i] <= v[(i+1) % n]) ok[i] = true;
        else {
            ok[i] = false;
            cntfalse++;
        }
    }

    if( cntfalse == 0 ) return 0;
    if(cntfalse >= 2) return 1e15;


    for(int i = 0; i<n; i++){
        if(ok[i] == false){
            return n-i-1;
        }
    }
}

int f2(vector<int> &v){
    int n = v.size();
    vector<bool> ok(n);
    int cntfalse = 0;
    for(int i =0; i<n; i++){
        if(v[i] >= v[(i+1) % n]) ok[i] = true;
        else {
            ok[i] = false;
            cntfalse++;
        }
    }

    if( cntfalse == 0 ) return 0;
    if(cntfalse >= 2) return 1e15;


    for(int i = 0; i<n; i++){
        if(ok[i] == false){
            return n-i-1;
        }
    }
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }


    int xx = f(input);
    int zz = f2(input);
    reverse(input.begin(), input.end());

    int yy = f(input);



    int ans = min(xx, 1+yy);

    
    int ww = f2(input);
    ans = mn(ans, ww+2, zz+1);
    debug(xx);
    debug(yy);
    debug(ww);
    debug(zz);
    if(ans>1e14) {
        cout<<-1<<endl;
        return;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

