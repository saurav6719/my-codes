/**
 *    author: Saurav
 *    created: 2024.11.10 22:14:35
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
    int n,m,v;
    cin>>n>>m>>v;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> aagese(n);
    vector<int> pichese(n);

    int currpartitions = 0;

    for(int i = 0; i<n;){
        int j = i;
        int curr = 0;
        while(j<n and curr < v){
            curr += input[j];
            j ++;   
        }

        if(curr >= v){
            currpartitions ++;
            aagese[j-1] = currpartitions;
        }
        
        i = j;
    }

    for(int i = 1; i<n; i++){
        if(aagese[i] == 0) aagese[i] = aagese[i-1];
    }

    print(aagese);

    currpartitions = 0;
    for(int i = n-1; i>=0; ){
        int j = i;
        int curr = 0;
        while(j>=0 and curr < v){
            curr += input[j];
            j--;

        }
        if(curr >= v){
            currpartitions++;
            pichese[j+1] = currpartitions;
        }
        i = j;
    }

    for(int i = n-2; i>=0; i--){
        if(pichese[i] == 0) pichese[i] = pichese[i+1];
    }

    print(pichese);

    vector<int> prfsum(n);
    int ans = -1;

    for(int i = 0; i<n; i++){
        if(i == 0){
            prfsum[i] = input[i];
            continue;
        }
        prfsum[i] = prfsum[i-1] + input[i];
    }

    print(prfsum);

    map<int,int> mp;

    for(int i =  0;i<n; i++){
        mp[pichese[i]] = i;
    }
    mp[0] = n;

    for(int i = 0; i<n; i++){
        int aagesemade = aagese[i];
        int required = m - aagesemade;

        if(required < 0){
            continue;
        }
        else if(required == 0){
            ans = max(ans , prfsum[n-1] - prfsum[i]);
            continue;
        }

        if(mp.find(required) == mp.end()) continue;

        int lastnhitake = mp[required];

        if(lastnhitake <= i) continue;
        else if(lastnhitake == i+1){
            ans = max(ans, 0ll);
            continue;
        }



        ans = max(ans, prfsum[lastnhitake-1] - prfsum[i]);

        if(ans == 13){
            debug(i);
        }
    }

    map<int,int> mp2;
    for(int i = n-1; i>=0; i--){
        mp2[aagese[i]] = i;
    }
    mp[0] = -1;


    for(int i = n-1; i>=0; i--){
        int pichesemade = pichese[i];
        int required = m - pichesemade;

        if(required < 0) {
            continue;
        }
        if(required == 0){
            if(i>0){
                ans = max(ans , prfsum[i-1]);
            }
        }
        int aagesetake ;
        if(mp2.find(required) == mp2.end()) continue;
        aagesetake = mp2[required];
        if(aagesetake >= i) continue;
        else if(aagesetake == i-1) {
            ans = max(ans, 0ll);
            continue;
        }
        ans = max(ans , prfsum[i-1] - prfsum[aagesetake]);
        if(ans == 13) {
            debug(i);
            debug(pichesemade);
            debug(required);
        }
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

