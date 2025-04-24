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


void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<char> > input(n, vector<char> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }

    queue<pair<int,int> > qu;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'M'){
                qu.push({i,j});
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'A'){
                qu.push({i,j});
            }
        }
    }


    while(!qu.empty()){
        pair<int,int> pp = qu.front();
        qu.pop();

        int x = pp.first;
        int y = pp.second;

        if(x+1 < n and input[x+1][y] == '.'){
            qu.push({x+1, y});
            if(input[x][y] == 'M'){
                input[x+1][y] = 'M';
            }
            else{
                input[x+1][y] = 'D';
            }
        }

        if(y+1 < m and input[x][y+1] == '.'){
            qu.push({x, y+1});
            if(input[x][y] == 'M'){
                input[x][y+1] = 'M';
            }
            else{
                input[x][y+1] = 'R';
            }
        }

        if(x-1 >= 0 and input[x-1][y] == '.'){
            qu.push({x-1, y});
            if(input[x][y] == 'M'){
                input[x-1][y] = 'M';
            }
            else{
                input[x-1][y] = 'U';
            }
        }

        if(y-1 >= 0 and input[x][y-1] == '.'){
            qu.push({x, y-1});
            if(input[x][y] == 'M'){
                input[x][y-1] = 'M';
            }
            else{
                input[x][y-1] = 'L';
            }
        }
    }

    int finali = -1;
    int finalj = -1;

    for(int i = 0; i<n; i++){
        if(input[i][0] != 'M' and input[i][0] != '.' and input[i][0] != '#'){
            finali = i;
            finalj = 0;
        }
    }

    for(int i = 0; i<n; i++){
        if(input[i][m-1] != 'M' and input[i][m-1] != '.' and input[i][m-1] != '#'){
            finali = i;
            finalj = m-1;
        }
    }

    for(int i = 0; i<m; i++){
        if(input[0][i] != 'M' and input[0][i] != '.' and input[0][i] != '#'){
            finali = 0;
            finalj = i;
        }
    }

    for(int i = 0; i<m; i++){
        if(input[n-1][i] != 'M' and input[n-1][i] != '.' and input[n-1][i] != '#'){
            finali = n-1;
            finalj = i;
        }
    }

    debug(finali);
    debug(finalj);

    debug(input[finali][finalj]);


    if(finali == -1){
        cout<<"NO"<<endl;
        return;
    }

    string ans;
    char it = input[finali][finalj];
    while(it != 'A'){
        it = input[finali][finalj];
        if(it == 'A') break;
        ans += it;
        if(it == 'R'){
            finalj--;
        }
        if(it == 'L'){
            finalj++;
        }
        if(it == 'D'){
            finali--;
        }  
        if(it == 'U'){
            finali++;
        }
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    cout<<ans;





    
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

