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
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Two possible target patterns
    string target1 = "";
    string target2 = "";
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            target1 += '0';
            target2 += '1';
        }
        else{
            target1 += '1';
            target2 += '0';
        }
    }
    
    // Calculate mismatches for both patterns
    int mismatches1 = 0, mismatches2 = 0;

    vector<int> mismatch1;

    vector<int> mismatch2;

    for(int i=0;i<n;i++){
        if(s[i] != target1[i]) {
            mismatches1++;
            mismatch1.push_back(i);
        }
        if(s[i] != target2[i]) {
            mismatches2++;
            mismatch2.push_back(i);
        }
    }

    debug(mismatches1);
    debug(mismatches2);

    
    // Each move can fix two mismatches
    // If mismatches are odd, it's impossible

    int contiguousblock1 = 0;
    int contiguousblock2 = 0;

    print(mismatch1);
    print(mismatch2);

    for(int i = 0; i<mismatch1.size()-1; i++){
        if(mismatch1.size() == 0) break;
        bool contiguosu = false;
        while(i < mismatch1.size()-1 && mismatch1[i+1] == mismatch1[i] + 1 and s[mismatch1[i]] == s[mismatch1[i+1]]){
            contiguosu = true;
            i++;
        }
        if(contiguosu) contiguousblock1++;
    }

    for(int i = 0; i<mismatch2.size()-1; i++){
        if(mismatch2.size() == 0) break;
        bool contiguosu = false;
        while(i < mismatch2.size()-1 && mismatch2[i+1] == mismatch2[i] + 1 and s[mismatch2[i]] == s[mismatch2[i+1]]){
            debug(mismatch2[i]);
            debug(mismatch2[i+1]);
            debug(s[mismatch2[i]]);
            debug(s[mismatch2[i+1]]);
            contiguosu = true;
            i++;
        }
        if(contiguosu) contiguousblock2++;
    }

    mismatches1 -= contiguousblock1;
    mismatches2 -= contiguousblock2;

    debug(mismatches1);
    debug(mismatches2);

    
    // Choose the minimum
    int ans = min(mismatches1, mismatches2);
    cout << ans;
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

