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

bool cmp(pp &a, pp &b){
    return a.second < b.second;
}
void solve(){
    string str;
    cin>>str;
    int n = str.size();
    int k;
    cin>>k;
    vector<vector<int> >pos(10, vector<int> ());

    for(int i = 0; i<n; i++){
        pos[str[i] - '0'].push_back(i);
    }
    int idx =-1;
    for(int i = 0; i<n; i++){
        if(str[i] == '0'){
            idx = i;
            break;
        }
    }

    int mini = INT_MAX;
    int mindx = -1;

    for(int i = 0; i<idx; i++){
        if(str[i] - '0' < mini){
            mini = str[i] - '0';
            mindx = i;
        }
    }



    string ans = "";
    int rem = n -k;
    int curr = -1;
    if(pos[0].size()  > 0){
        ans += to_string(mini);
        curr = mindx;
        rem--;
    }

    debug(rem);
    debug(curr);
    int i = 0;
    while(i<10) {
        for(int j= 0 ; j<pos[i].size(); j++){
            if(pos[i][j] > curr and pos[i][j] + rem <= n and rem > 0){
                ans += to_string(i);
                rem--;
                i = 0;
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

