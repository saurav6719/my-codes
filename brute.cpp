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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

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
map<char,int> mp;
void solve(){
    string str;
    cin>>str;
    int n = str.size();

    map<char,int> freq;

    for(int i= 0; i<n; i++){
        freq[str[i]] = i;
    }

    int ans = 0;



    vector<bool> posneg(n+5);

    for(int i =0; i<n; i++){
        char ch = str[i];
        bool aagebada = false;
        for(char x = ch+1; x<='E'; x++){
            if(freq[x] > i) aagebada = true;
        }

        if(aagebada){
            ans -= mp[ch];
            posneg[i] = 0;
            
        }
        else{
            posneg[i] = 1;
            ans += mp[ch];
        }
    }

    print(posneg);

    debug(ans);

    int ghatana = 0;
    int badhana = 0;

    int orginalans = ans;

    for(int i = 0; i<n; i++){

        if(str[i] == 'E') continue;

        int curr = orginalans;
        debug(curr);
        

        

        debug(ghatana);
        
        // i pe change 

        if(posneg[i] == 1){
            curr -= 2*ghatana;
            curr -= mp[str[i]];
            curr += mp['E'];
        }
        else{
            curr -= 2*ghatana;
            curr += mp[str[i]];
            curr += mp['E'];
        }

        if(posneg[i] == true){
            ghatana += mp[str[i]];
        }

        ans = max(ans, curr);
        debug(i);
        debug(curr);
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

    mp['A'] = 1;
    mp['B'] = 10;
    mp['C'] = 100;
    mp['D'] = 1000;
    mp['E'] = 10000;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

