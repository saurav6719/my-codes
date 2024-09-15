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
int dp[55][10][2];  

int f(int i, int last, bool apna, string &str, int n){
    //base case {}

    debug(i);
    debug(last);
    debug(apna);

    if(i== n){
        if(apna) return 0;
        return 1;
    }   

    if(dp[i][last][apna] != -1) return dp[i][last][apna];

    int sum = str[i] - '0';
    debug(sum);
    sum += last;

    debug(sum);

    bool newapna = true;
    if(apna == false) newapna = false;
    int sum_copy = sum;

    debug(sum);
    debug(sum % 2);
    debug((sum & 1));
    int xx = sum%2;
    debug(xx);
    if(xx != 0){
        // cout<<"gaya"<<endl;
        debug(sum);
        debug(sum % 2);
        debug((sum & 1));
        debug(sum);
        
        // cout<<sum<<"is "<<"odd"<<endl;
        int xx = sum/2;
        if(xx == str[i]- '0' and apna == true) newapna = true;
        else newapna = false; 

        
        int aa =  f(i+1, xx , newapna, str, n) ;

        int yy = sum/2+1;
        if(yy == str[i]- '0' and apna == true) newapna = true;
        else newapna = false; 

        int bb = f(i+1, yy , newapna, str, n) ;

        return dp[i][last][apna] = aa + bb;
    }
    else{
        int xx = sum/2;
        if(xx == str[i]- '0' and apna == true) newapna = true;
        else newapna = false;
        int aa =  f(i+1, xx , newapna, str, n) ;
        return dp[i][last][apna] = aa;
    }
    
}
void solve(){
    string str;
    cin>>str;

    memset(dp, -1,sizeof dp);
    int ans = 0;

    int first = str[0] - '0';
    for(int i = 0; i<=9; i++){
        if(i==first){
            ans += f(1,i,true,str,str.size());
        }
        else{
            ans += f(1,i,false,str,str.size());
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

