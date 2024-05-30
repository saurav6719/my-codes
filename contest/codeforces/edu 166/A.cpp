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
#include <cctype>
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
    for(int i = 1; i<n; i++){
        char ele = str[i];
        char prev = str[i-1];
        if(isalpha(prev) and isdigit(ele)){
            cout<<"NO"<<endl;
            return;
        }
    }

    vector<int>  digits ;
    vector<int> alphabets;
    for(int i = 0; i<n; i++){
        if(isdigit(str[i])){
            int di = str[i] - '0';
            digits.push_back(di);
        }
        else alphabets.push_back(str[i] - '0');
    }

    vector<int> di_copy = digits;
    vector<int> al_copy = alphabets;
    sort(di_copy.begin(), di_copy.end());
    sort(al_copy.begin(), al_copy.end());

    for(int i = 0; i<di_copy.size(); i++){
        if(digits[i] != di_copy[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    print(digits);
    print(alphabets);
    print(di_copy);
    print(al_copy);


 for(int i = 0; i<al_copy.size(); i++){
        if(alphabets[i] != al_copy[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;


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

