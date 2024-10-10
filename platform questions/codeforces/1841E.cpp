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
int score(string &str){
    int n = str.size();
    bool a=false, b=false, c=false, d=false, e=false;

    int ans = 0;
    for(int i = n-1; i>=0; i--){
        if(str[i] == 'A'){
            a = true;
            if(b or c or d or e) ans -= 1;
            else ans += 1;
        }
        if(str[i] == 'B'){
            b = true;

            if(c or d or e) ans -= 10;
            else ans += 10;
        }
        if(str[i] == 'C'){
            c = true;

            if(d or e) ans -= 100;
            else ans += 100;
        }
        if(str[i] == 'D'){
            d = true;
            if(e) ans -= 1000;
            else ans += 1000;
        }
        if(str[i] == 'E'){
            e = true;
            ans += 10000;
        }
    }
    return ans;
}
void solve(){
    string str;
    cin>>str;
    int firsta = -1;
    int firstb = -1;
    int firstc = -1; 
    int firstd = -1;
    int firste = -1;
    int n = str.size();

    int ans = score(str);
    debug(ans);

    for(int i = 0; i<n; i++){
        if(str[i] == 'A'){
            firsta = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(str[i] == 'B'){
            firstb = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(str[i] == 'C'){
            firstc = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(str[i] == 'D'){
            firstd = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(str[i] == 'E'){
            firste = i;
            break;
        }
    }

    if(firsta != -1){
        str[firsta] = 'B';
        ans = max(ans, score(str));
        str[firsta] = 'C';
        ans = max(ans, score(str));
        str[firsta] = 'D';
        ans = max(ans, score(str));
        str[firsta] = 'E';
        ans = max(ans, score(str));
        str[firsta] = 'A';
    }

    if(firstb != -1){
        str[firstb] = 'C';
        ans = max(ans, score(str));
        str[firstb] = 'D';
        ans = max(ans, score(str));
        str[firstb] = 'E';
        ans = max(ans, score(str));
        str[firstb] = 'B';
    }

    if(firstc != -1){
        str[firstc] = 'D';
        ans = max(ans, score(str));
        str[firstc] = 'E';
        ans = max(ans, score(str));
        str[firstc] = 'C';
    }

    if(firstd != -1){
        str[firstd] = 'E';
        ans = max(ans, score(str));
        str[firstd] = 'D';
    }

    int lasta = -1;
    int lastb = -1;
    int lastc = -1;
    int lastd = -1;
    int laste = -1;

    for(int i = n-1; i>=0; i--){
        if(str[i] == 'A'){
            lasta = i;
            break;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(str[i] == 'B'){
            lastb = i;
            break;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(str[i] == 'C'){
            lastc = i;
            break;
        }
    }

    for(int i = n-1; i>=0; i--){
        if(str[i] == 'D'){
            lastd = i;
            break;
        }
    }

    for(int i = n-1; i>=0; i--){
        if(str[i] == 'E'){
            laste = i;
            break;
        }
    }

    if(laste != -1){
        str[laste] = 'D';
        ans = max(ans, score(str));
        str[laste] = 'C';
        ans = max(ans, score(str));
        str[laste] = 'B';
        ans = max(ans, score(str));
        str[laste] = 'A';
        ans = max(ans, score(str));
        str[laste] = 'E';
    }


    if(lastd != -1){
        str[lastd] = 'C';
        ans = max(ans, score(str));
        str[lastd] = 'B';
        ans = max(ans, score(str));
        str[lastd] = 'A';
        ans = max(ans, score(str));
        str[lastd] = 'D';
    }

    if(lastc != -1){
        str[lastc] = 'B';
        ans = max(ans, score(str));
        str[lastc] = 'A';
        ans = max(ans, score(str));
        str[lastc] = 'C';
    }

    if(lastb != -1){
        str[lastb] = 'A';
        ans = max(ans, score(str));
        str[lastb] = 'B';
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}