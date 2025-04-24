/**
 *    author: Saurav
 *    created: 2024.11.08 01:05:04
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
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    priority_queue<int> pq;
    int onecnt = 0;

    for(auto ele : input){
        if(ele > 1){
            pq.push(ele);
        }
        else onecnt++;
    }
    int ans = 0;

    vector<int> lasts;

    while(!pq.empty()){
        int ff = pq.top();
        // cout<<"one"<<endl;
        debug(ff);
        pq.pop();

        int noofisosceles = ff/2;

        if(onecnt >= noofisosceles){
            // cout<<"two"<<endl;
            ans += noofisosceles;
            debug(ans);
            onecnt -= noofisosceles;
            debug(onecnt);
            ff-= (noofisosceles*2);
            debug(ff);

            if(ff == 1){
                onecnt++;
                debug(onecnt);
            }
        }
        else{
            ans += onecnt;
            ff -= (2*onecnt);
            onecnt = 0;
            // cout<<"three"<<endl;
            debug(ans);
            debug(onecnt);
            debug(ff);

            while(!pq.empty() and ff > 1){
                // cout<<"four"<<endl;
                int ss = pq.top();
                pq.pop();
                debug(ss);

                int nowisosceles = ff/2;
                debug(nowisosceles);
                if(nowisosceles <= ss){

                    // cout<<"five"<<endl;
                    ans += nowisosceles;
                    ss -= nowisosceles;
                    ff -= (nowisosceles*2);

                    debug(ans);
                    debug(ss);
                    debug(ff);
                    if(ss > 1){
                        // cout<<"six"<<endl;
                        pq.push(ss);
                    }
                    if(ff == 1){
                        // cout<<"seven"<<endl;
                        onecnt++;
                    }
                    if(ss == 1){
                        // cout<<"eight"<<endl;
                        onecnt++;
                    }
                }
                else{
                    // cout<<"nine"<<endl;
                    ans += ss;
                    ff -= (2*ss);
                    debug(ans);
                    debug(ff);
                    if(ff == 1){
                        // cout<<"ten"<<endl;
                        onecnt++;
                    }
                }
            }

            if(ff > 1){
                // cout<<"eleven"<<endl;
                lasts.push_back(ff);
            }
        }
    }

    print(lasts);

    debug(ans);

    if(!lasts.empty() ){
        ans += lasts[0]/3;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

