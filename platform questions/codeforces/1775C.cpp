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

string getbinary(int x){
    bitset<64> b(x);
    return b.to_string();

    
}

long long binaryToDecimal(const std::string& bin) {
    return std::bitset<64>(bin).to_ullong();
}
void solve(){
    int n,x;
    cin>>n>>x;
    if(x > n) {
        cout<<-1<<endl;
        return;
    }
    if(x==n){
        cout<<n<<endl;
        return;
    }

    string str = getbinary(n);
    // print(str);
    int idx = -1;
    

    string str2 = getbinary(x);

    string ans  = str;

    for(int i = 0; i<64; i++){
        if(str[i] == '0' and str2[i] == '1'){
            cout<<-1<<endl;
            return;
        }
    }

    for(int i = 0; i<64; i++){
        if(str[i] == '1' and str2[i] == '0'){
            idx = i;
            break;
        }
    }

    ans[idx-1] = '1';

    for(int i = idx; i<64; i++){

        if(str2[i] == '1'){
            cout<<-1<<endl;
            return;
        }
        ans[i] = '0';
    }
    // print(ans);

    int final = binaryToDecimal(ans);

    if(final < n) {
        cout<<-1<<endl;
        return;
    }

    cout<<final<<endl;
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

