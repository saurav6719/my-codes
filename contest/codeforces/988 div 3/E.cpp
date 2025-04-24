/**
 *    author: Saurav
 *    created: 2024.11.17 20:04:13
 **/

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

int query(int l , int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int x ;
    cin>>x;
    return x;
}

void printres(string &str){
    cout<<"! "<<str<<endl;
    cout.flush();
}
void solve(){
    int n;
    cin>>n;

    string str(n,'#');

    map<pp, int> mp;

    for(int i = 1; i<n; i++){
        int x = query(i,i+1);

        if(x == 1){
            str[i-1] = '0';
            str[i] = '1';
        }
        else{
           if(str[i-1] != '#'){
                str[i] = '0';
           }
        }
    }

    int hashcnt = 0;

    for(auto ele : str){
        if(ele == '#') hashcnt ++;
    }

    if(hashcnt > 1){
        string ans = "IMPOSSIBLE";
        printres(ans);
    }
    else{
        for(auto &ele : str){
            if(ele == '#') ele = '0';
        }
        printres(str);
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

