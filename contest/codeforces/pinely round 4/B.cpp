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
    int n_copy = n;
    n_copy --;
    vector<int> input(n_copy);
    for(int i = 0; i<n_copy; i++){
        cin>>input[i];
    }

    debug(n);
    n--;

    // print(input);

    vector<int> ans(n+1);
    ans[n] = input[n-1];

    ans[0] = input[0];

    for(int j = 1; j<=n; j++){
        

        //pichla ka and n bigarte hue best 

        int pichla = input[j-1];
        // debug(pichla);
        int pichlaliya = ans[j-1];
        int agla = 0;

        for(int i= 0; i<32; i++){
            if(pichla & (1<<i)){
                // debug(i);
                agla += (1<<i);
            }
            else{
                if(input[j] & (1<<i)){
                    // debug(i);
                    agla += (1<<i);
                }
            }
        }

        ans[j] = agla;
    }

    // n++;

    // debug(ans.size());
    for(int i = 1; i<ans.size(); i++){
        if((ans[i] & ans[i-1]) != input[i-1]){

            debug(i);
            debug(ans[i]);
            debug(ans[i-1]);
            debug(input[i-1]);
            cout<<-1<<endl;
            return;
        }
    }

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    print(ans);
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

