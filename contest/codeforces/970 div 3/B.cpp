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
bool isPerfectSquare(int num) {
    if (num < 0) return false; // Negative numbers can't be perfect squares.
    
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}
void solve(){
    
    int n;
    cin>>n;
    string str;
    cin>>str;

    if(isPerfectSquare(n) == 0){
        cout<<"No"<<endl;
        return;
    }

    int xx = sqrt(n);
    debug(xx);

    vector<vector<int>  > ans(xx , vector<int> (xx));

    for(int i = 0; i<xx; i++){
        for(int j = 0; j<xx; j++){
            if(i==0 or j==0 or i==xx-1 or j==xx-1){
                ans[i][j] = 1;
            }
            else ans[i][j] = 0;
        }
    }

    print2d(ans);


    string cmp= "";
    for(int i = 0; i<xx; i++){
        for(int j = 0; j<xx; j++){
            cmp += std::to_string(ans[i][j]);

        }
    }
    print(cmp);
    if(cmp == str){
        cout<<"Yes"<<endl;
        return;
    }

    cout<<"no"<<endl;
{
    
    
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

