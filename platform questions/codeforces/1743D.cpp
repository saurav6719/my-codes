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
string orrr(string &a, string &b){
    int len1 = a.size();
    int len2 = b.size();
    while(len2 < len1){
        b = '0' + b;
        len2++;
    }

    string ans = "";

    for(int i = 0; i<len1; i++){
        if(a[i] == '1' or b[i] == '1'){
            ans+= '1';
        }
        else ans+= '0';
    }

    return ans;
}

string comp(string&a, string &b){
    for(int i = 0; i<a.size(); i++){
        if(a[i] == b[i]) continue;
        if(a[i] == '1') return a;
        else return b;
    }
    return a;
}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    int pos0 = -1;
    int firstone = -1;
    for(int i = 0; i<n; i++){
        if(str[i] == '1') {
            firstone  =i ;
            break;
        }
    }
    for(int i = firstone; i<n; i++){
        if(str[i] == '0'){
            pos0 = i;
            break;
        }
    }

    

    

    string ans = orrr(str,str);

    if(pos0 == -1){
        cout<<str<<endl;
        return;
    }



    debug(pos0);
    int length = n - 1 - pos0 + 1;

    for(int i = 0; i<pos0; i++){
        string tocomp = str.substr(i, length);
        print(tocomp);
        string currans = orrr(str, tocomp);
        ans = comp(ans, currans);
    }

    int lo = 0;
    string ans_copy = "";
    while(ans[lo] == '0') lo++;

    ans_copy = ans.substr(lo);
    if(ans_copy.empty()){
        cout<<0<<endl;
        return;
    }
    // print(answer)
    ans = ans_copy;

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

