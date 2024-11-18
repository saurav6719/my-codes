/**
 *    author: Saurav
 *    created: 2024.11.18 15:36:45
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
    string str;
    cin>>str;
    int n = str.size();
    vector<int> prfmod(n+1,0);
    for(int i = 1; i<=n; i++){
        prfmod[i] = (prfmod[i-1] + (str[i-1]-'0'))%9;
    }
    
    print(prfmod);
    int w,q;
    cin>>w>>q;

    map<int,int> wlengthmod;

    for(int i = 1;i<=n; i++){
        if(i+w-1 <= n){
            int v = prfmod[i+w-1] - prfmod[i-1];
            v = (v+9)%9;
            wlengthmod[i] = v;
        }
    }

    printmap(wlengthmod);

    map<int,set<int> > mpxx;

    for(auto ele : wlengthmod){
        mpxx[ele.second].insert(ele.first);
    }



    while(q--){
        int l,r;
        cin>>l>>r;
        int k;
        cin>>k;
        int vlr = prfmod[r] - prfmod[l-1];

        debug(vlr);

        map<int,int> mp;

        for(int i = 0; i<=8; i++){
            int l1 = i;
            l1 *= vlr;

            int l2 = (k - l1 + 900) % 9;

            mp[i] = l2; 
        }

        printmap(mp);

        int ans1 = n+5;
        int ans2 = n+5;

        for(int i = 0; i<=8; i++){
            int aa = i;
            int bb = mp[i];

            if(aa == bb){
                if(mpxx[aa].size() < 2) continue;
                int firstmini = *mpxx[aa].begin();
                auto it = mpxx[aa].begin();
                it++;
                int secondmini = *it;

                if(ans1 > firstmini){
                    ans1 = firstmini;
                    ans2 = secondmini;
                }
                else if(ans1 == firstmini){
                    ans2 = min(ans2,secondmini);
                }

            }
            else{
                if(mpxx[aa].size() == 0 || mpxx[bb].size() == 0) continue;
                int firstmini = *mpxx[aa].begin();
                int secondmini = *mpxx[bb].begin();

                if(ans1 > firstmini){
                    ans1 = firstmini;
                    ans2 = secondmini;
                }
                else if(ans1 == firstmini){
                    ans2 = min(ans2,secondmini);
                }
            }
        }
        if(ans1 == n+5){
            cout<<-1<<" "<<-1<<endl;
        }
        else{
            cout<<ans1<<" "<<ans2<<endl;
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

