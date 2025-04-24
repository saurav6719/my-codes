/**
 *    author: Saurav
 *    created: 2024.10.14 20:00:26
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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i=0 ;i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(),input.end());

    vector<int> missing;
    for(int i=  1; i<n; i++){
        if(input[i] - input[i-1] > 1){
            missing.push_back(input[i-1] + 1);
        }
    }

    missing.push_back(input.back()+1);



    int ans = 0;

    for(int i= 0; i<n; i++){
        int ele = input[i];
        // i se shuru 
        // i+k pe khatam 

        int kahantak = lower_bound(missing.begin(), missing.end(), ele)-missing.begin();
        int firstmissing = missing[kahantak];
        int xx = ele+k;
        if(firstmissing < xx) xx = firstmissing;
        int khatam = lower_bound(input.begin(),input.end(),xx) - input.begin();
        khatam--;
        ans = max(ans , khatam - i + 1) ;
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

