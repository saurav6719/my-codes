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
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    set<char> one;
    for(int i = 0; i<n; i++){
        one.insert(str[i]);
    }
    for(char i ='a' ; i<='z'; i++){
        if(one.count(i) == 0){
            cout<<i<<endl;
            return;
        }
    }
    set<string> two;

    int i = 0;
    int j = 1;
    while(j<n){
        string s = "";
        s += str[i];
        s += str[j];
        two.insert(s);
        i++;j++;
    }

    for(char i = 'a'; i<='z'; i++){
        for(char j = 'a'; j<='z'; j++){
            string s1 = "";
            s1+= i;
            s1+= j;
            if(two.count(s1) == 0){
                cout<<s1<<endl;
                return;
            }
        }
    }

    set<string> three;

    int a = 0;
    int b = 1;
    int c = 2;

    while(c<n){
        string s = "";
        s += str[a];
        s += str[b];
        s += str[c];
        three.insert(s);
        a++;
        b++;
        c++;
    }

    for(char i = 'a'; i<='z'; i++){
        for(char j = 'a'; j<='z'; j++){
            for(char k = 'a' ; k<='z'; k++){
                string s1 = "";
                s1+= i;
                s1+= j;
                s1+= k;
                if(three.count(s1) == 0){
                    cout<<s1<<endl;
                    return;
                }
            }
        }
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

