/**
 *    author: Saurav
 *    created: 2024.12.24 20:16:55
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

bool isDivisibleBy(vector<int> &x, int num) {
    int rem = 0; // Remainder starts at 0

    for (int i = 0; i < x.size(); i++) {
        rem = rem * 10 + x[i]; // Add the current digit to the remainder
        rem %= num;            // Keep only the remainder modulo `num`
    }

    return rem == 0; // If the remainder is 0, the number is divisible
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


void solve(){
    int n,d;
    cin>>n>>d;

    vector<int> ans;

    if(n > 9){
        cout<<1<<" ";
        if(d == 3 or d==6 or d==9){
            cout<<3<<" ";
        }

        if(d == 5){
            cout<<5<<" ";
        }

        if(d == 3 or d==6 or d==9){
            cout<<9<<" ";
        }
    }

    for(int i = 1; i<=9; i+=2){

        int x = factorial(n);
        vector<int> v(x,d);
        if(isDivisibleBy(v, i)){
            ans.push_back(i);
        }
    }

    for(auto x : ans){
        cout<<x<<" ";
    }

    cout<<endl;
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

