/**
 *    author: Saurav
 *    created: 2024.11.17 21:03:36
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
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> hurdlepos;
    vector<int> powerreq;
    for(int i= 0; i<n; i++){
        int x;
        cin>>x;
        hurdlepos.push_back(x-1);
        int y;
        cin>>y;
        powerreq.push_back(y - x + 2);
    }

    
    

    int currpower =1;
    int ans = 0;
    priority_queue<int> pq;
    int currhurdle = 0;

    vector<int> pos;
    vector<int> val;

    for(int i = 0; i<m; i++){
        int poss;
        cin>>poss;
        int vall;
        cin>>vall;
        pos.push_back(poss);
        val.push_back(vall);
    }

    int xx = 1;
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        mp[hurdlepos[i]] = powerreq[i];
    }

    int yy = 0;

    

    for(int i = 0; i<m;i++){
        int currrequired = powerreq[yy];
        if(pos[i] > hurdlepos[yy]){
            if(xx < currrequired){
                cout<<-1<<endl;
                return ;
            }
            yy ++;
        }
        
        xx+=val[i];
    }

    for(int i = 0; i<m; i++){
        int position = pos[i];
        int value = val[i];
        // debug(position);
        // debug(value);
        if(currhurdle < n and position > hurdlepos[currhurdle]){
            int powerreqqq = powerreq[currhurdle];
            // debug(currhurdle);
            // debug(powerreqqq);
            // debug(currpower);
            bool inside = false;
            while(currpower < powerreqqq){
                inside = true;
                debug(powerreqqq);
                if(pq.empty()){
                    cout<<-1<<endl;
                    return ;
                }
                currpower += pq.top();
                pq.pop();
                ans ++;
                if(currpower >= powerreqqq){
                    currhurdle ++ ;
                    if(currhurdle == n){
                        debug(i);
                        cout<<ans<<endl;
                        return;
                    }
                }
            }


            if(inside == false){
                currhurdle ++;
                if(currhurdle == n){
                    cout<<ans<<endl;
                    return ;
                }
            }
        }

        pq.push(value);
    }

    if(currhurdle < n){
        while(currhurdle < n){
            int powerrequired = powerreq[currhurdle];
            bool inside = false;
            while(currpower < powerrequired){
                debug(powerrequired);
                debug(pq.top());
                inside = true;
                if(pq.empty()){
                    cout<<-1<<endl;
                    return ;
                }
                currpower += pq.top();
                pq.pop();
                ans ++;
                if(currpower >= powerrequired){
                    currhurdle ++;
                    if(currhurdle == n){
                        cout<<ans<<endl;
                        return ;
                    }
                }
            }

            if(inside == false){
                currhurdle ++;
                if(currhurdle == n){
                    cout<<ans<<endl;
                    return ;
                }
            }

            
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

