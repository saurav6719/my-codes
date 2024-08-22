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
    int q;
    cin>>q;
    vector<vector<int> > input(n,vector<int> (n, 0));
    for(int i = 0; i<n; i++){
        for(int j= 0; j<n; j++){
            char ch ;
            cin>>ch;
            if(ch == '*') input[i][j] = 1;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i>0) input[i][j] += input[i-1][j];
            if(j>0) input[i][j] += input[i][j-1];
            if(i > 0 and j > 0) input[i][j] -= input[i-1][j-1];
        }
    }

    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        y1--;
        x1--;
        y2--;
        x2--;

        int result = input[y2][x2];
        if(x1 > 0) result -= input[y2][x1-1];
        if(y1 > 0) result -= input[y1-1][x2];
        if(x1 > 0 && y1 > 0) result += input[y1-1][x1-1];

        cout << result << endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

