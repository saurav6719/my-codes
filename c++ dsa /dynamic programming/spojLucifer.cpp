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

/* write core logic here */
set<int> st;
int dp[20][2][100][100];
int f(string &s , int idx, bool smaller,int evensum, int oddsum){
    if((idx == s.size()) and st.count(evensum - oddsum)) return 1;
    if(idx == s.size()) return 0;
    if(dp[idx][smaller][evensum][oddsum] != -1) return dp[idx][smaller][evensum][oddsum];
    int loop;
    if(smaller){
        loop = 9;
    }
    else loop = s[idx] - '0';
    int ans = 0;
    for(int i = 0; i<=loop ; i++){
        bool newsmaller;
        if(smaller) newsmaller = true;
        else {
            if(i < s[idx] - '0') newsmaller = true;
            else newsmaller = false;
        }
        int newevensum = evensum;
        int newoddsum = oddsum;
        if((s.size() - idx) % 2 == 0){
            newevensum += i;
        }
        else{
            newoddsum += i;
        }
        ans += f(s, idx+1, newsmaller , newevensum , newoddsum ) ;
    }
    return dp[idx][smaller][evensum][oddsum] = ans;
}
void solve(){
    vector<int> v = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int i = 0; i<v.size(); i++){
        st.insert(v[i]);
    }
    int l,r;
    cin>>l>>r;
    string strr = to_string(r);
    string strl = to_string(l-1);
    memset(dp, -1, sizeof dp);
    int rightans = f(strr , 0, 0, 0, 0);
    memset(dp, -1, sizeof dp);
    int leftans = f(strl , 0, 0, 0, 0);
    cout<<rightans - leftans<<endl;
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

