/**
 *    author: Saurav
 *    created: 2025.04.25 03:15:09
 *    We stop at Candidate Master in 2025
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
    vector<int> input(n+1);
    map<int,int> mp;
    for(int i = 1; i<=n; i++){
        cin>>input[i];
        mp[input[i]] = i;
    }
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;

        if(mp[x] < l or mp[x] > r){
            cout<<-1<<" ";
            continue;
        }

        vector<int> galat;
        vector<int> sahi;
        int jahajaana = mp[x];
        int lo = l;
        int hi = r;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(mid == jahajaana){
                break;
            }
            else if(mid < jahajaana){
                // we will go to right 
                if(input[mid] < x){
                    // sahi me push kro 
                    sahi.push_back(input[mid]);
                }
                else{
                    // galat me push kro 
                    galat.push_back(input[mid]);
                }
                lo = mid + 1;
            }
            else{
                // we will go to left 
                if(input[mid] > x){
                    // sahi me push kro 
                    sahi.push_back(input[mid]);
                }
                else{
                    // galat me push kro 
                    galat.push_back(input[mid]);
                }
                hi = mid - 1;
            }
        }

        print(galat);
        print(sahi);

        set<int> galatchhota;
        set<int> galatbada;
        set<int> sahiwale;

        for(auto ele : galat){
            if(ele < x){
                galatchhota.insert(ele);
            }
            else{
                galatbada.insert(ele);
            }
        }
        set<int> used;

        for(auto ele : sahi){
            used.insert(ele);
        }

        int ans = 0;

        if(galatchhota.empty() and galatbada.empty()){
            cout<<0<<" ";
            continue;
        }
        while(!galatchhota.empty() and !galatbada.empty()){
            used.insert(*galatchhota.begin());
            used.insert(*galatbada.begin());
            galatbada.erase(galatbada.begin());
            galatchhota.erase(galatchhota.begin());
            
            ans+= 2;
        }

        if(!galatchhota.empty()){
            int req = galatchhota.size();
            int hai = 0;
            for(int i = x+1; i<=n; i++){
                if(used.find(i) == used.end()){
                    hai++;
                }
                if(hai == req){
                    break;
                }
            }

            if(hai != req){
                cout<<-1<<" ";
                continue;
            }
            else{
                ans+= 2*hai;
                cout<<ans<<" ";
                continue;
            }
        }

        if(!galatbada.empty()){
            int req = galatbada.size();
            int hai = 0;
            for(int i = x-1; i>=1; i--){
                if(used.find(i) == used.end()){
                    hai++;
                }
                if(hai == req){
                    break;
                }
            }

            if(hai != req){
                cout<<-1<<" ";
                continue;
            }
            else{
                ans+= 2*hai;
                cout<<ans<<" ";
                continue;
            }
        }

        cout<<ans<<" ";
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

