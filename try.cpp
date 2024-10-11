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
struct cake{
    int a,b,c;
};

bool cmp(cake &a, cake &b , int x, int y, int z){
    return a.a*x + a.b*y + a.c*z > b.a*x + b.b*y + b.c*z;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<cake> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].a>>v[i].b>>v[i].c;
    }

    int ans = INT_MIN;

    for(int x = -1; x<=1; x+=2){
        for(int y = -1; y<=1; y+=2){
            for(int z = -1; z<=1; z++){
                sort(v.begin(),v.end(),[&](cake &a, cake &b){
                    return cmp(a,b,x,y,z);
                });

                int sum = 0;
                int sum1 = 0;
                int sum2 = 0;
                int sum3 = 0;
                for(int i=0;i<m;i++){
                    sum1 += v[i].a;
                    sum2 += v[i].b;
                    sum3 += v[i].c;
                }

                sum = abs(sum1) + abs(sum2) + abs(sum3);
                ans = max(ans,sum);
            }
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

