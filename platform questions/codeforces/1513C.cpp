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

void precompute(vector<int> &v){
    v[0] = 2;
    v[1] = 2;
    vector<int> pichla(10, 0);
    pichla[0] = 1;
    pichla[1] = 1;

    for(int i = 1; i<=2e5+5; i++){
        int ans = 0;
        vector<int> agla(10, 0);
        for(int i = 0; i<10; i++){
            if(pichla[i] == 0) continue;
            if(i<9){
                agla[i+1] += pichla[i];
                agla[i+1] %= mod;
                
            }
            else{
                agla[0] += pichla[9];
                agla[0] %= mod;

                agla[1] += pichla[9];
                agla[1] %= mod;
                
            }
        }

        pichla = agla;
        // print(pichla);
        for(auto ele : pichla){
            ans += ele;
            ans %= mod;
        }
        v[i] = ans;
    }

}
void solve(vector<int> &v){
    int n,m;
    cin>>n>>m;

    vector<int> digits;
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    int ans = 0;

    for(auto ele : digits){
        int xx = 10-ele;
        int m_copy = m;
        m_copy -= xx;
        if(m_copy==0){
            ans += 2;
            ans %= mod;
            continue;
        }
        else if(m_copy < 0){
            ans ++;
            ans %= mod;
            continue;
        }

        else{
            ans += v[m_copy];
            ans %= mod;
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
    cin>>t;

    vector<int> v(2e5+5);

    precompute(v);
    // print(v);
    // t = 1;
    while(t--){
        solve(v);
    }
return 0;
}

