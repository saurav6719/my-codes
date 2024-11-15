/**
 *    author: Saurav
 *    created: 2024.11.15 17:52:35
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

    int n,q;
    cin>>n>>q;

    vector<int> v(n+1);

    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    vector<int> zerocount(n+1);

    for(int i=1;i<=n;i++){
        zerocount[i] = zerocount[i-1] + (v[i] == 0) ;
    }

    vector<int> prfxor(n+1);
    prfxor[0] = 0;
    for(int i=1;i<=n;i++){
        prfxor[i] = prfxor[i-1] ^ v[i];
    }

    map<int,vector<int> > mpodd;
    map<int,vector<int> > mpeven;

    for(int i = 1; i<=n; i++){
        if(i&1){
            mpodd[prfxor[i]].push_back(i);
        }
        else{
            mpeven[prfxor[i]].push_back(i);
        }
    } 


    while(q--){
        int l,r;
        cin>>l>>r;

        int x = prfxor[r] ^ prfxor[l-1];
        if(x != 0){
            cout<<-1<<endl;
            continue;
        }

        // if already all elements are zero return 0

        if(zerocount[r] - zerocount[l-1] == r-l+1){
            cout<<0<<endl;
            continue;
        }

        if((r-l+1)&1){
            cout<<1<<endl;
            continue;
        }

        // length is even and xor is 0 
        // i need to check whether any prefix xor 0 exists between l and r or not 

        int lastxor = prfxor[l-1];

        if(l & 1){
            auto &v = mpodd[lastxor];

            auto it = lower_bound(v.begin(),v.end(),l);

            if(it != v.end() && *it <= r){
                int zeroafter = 0;
                zeroafter = zerocount[r] - zerocount[*it];
                if(zeroafter == r - *it){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            else{
                cout<<-1<<endl;
            }
        } 

        else{
            auto &v = mpeven[lastxor];

            auto it = lower_bound(v.begin(),v.end(),l);

            if(it != v.end() && *it <= r){
                int zeroafter = 0;
                zeroafter = zerocount[r] - zerocount[*it];
                if(zeroafter == r - *it){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            else{
                cout<<-1<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

