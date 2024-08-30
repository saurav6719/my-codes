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
    int x0,y0;
    cin>>x0>>y0;
    int ax,ay;
    cin>>ax>>ay;
    int bx,by;
    cin>>bx>>by;
    int xs,ys;
    cin>>xs>>ys;
    int t;
    cin>>t;

    int t_copy = t;

    vector<pp> datanodes;
    set<pp> st;
    datanodes.push_back({x0,y0});
    
    for(int i = 0;i<100; i++){
        int lastx = datanodes.back().first;
        int lasty = datanodes.back().second;
        int newx = ((ax * lastx) + bx);
        int newy = ((ay * lasty) + by);
        if(newx > 2e16 or newy > 2e16) break;
        datanodes.push_back({newx, newy});
    }

    debug(datanodes.size());


    // for(auto ele : datanodes){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }


    int diff = 0;
    diff += abs(xs - datanodes[0].first);
    diff += abs(ys - datanodes[0].second);
    int ans = 0;
    int currx = xs;
    int curry = ys;

    int ans_copy = 0;
    int currx_copy = currx;
    int curry_copy = curry;


    // if(datanodes.size() == 1){
    //     cout<<0<<endl;
    //     return;
    // }

    for(auto ele : datanodes){
        st.insert(ele);
    }

    set<pp> st_copy = st;
    debug(diff);

    

    if(diff >= t){
        while(t>0){
        int mini = 1e17;
        int toremovex = -1;
        int toremovey = -1;
        for(auto ele : st){
            int x = ele.first;
            int y = ele.second;
            // if(x>xs or y> ys) break;
            int dist = abs(x - currx) + abs(y - curry);
            if(dist < mini ){
                mini = dist;
                toremovex = x;
                toremovey = y;
            }
        }
        debug(toremovex);
        debug(toremovey);
        t -= abs(currx - toremovex) + abs(curry - toremovey);
        if(t>=0) ans++;
        currx = toremovex;
        curry = toremovey;
        st.erase({currx, curry});
        }

        cout<<ans<<endl;
        return;
    }

    else{
        int maxi = -1;
        for(int i = 0; i<datanodes.size(); i++){
            int sum = 0;
            sum += abs(xs - datanodes[i].first);
            sum += abs(ys - datanodes[i].second);
            sum += abs(datanodes[i].first - datanodes[0].first);
            sum += abs(datanodes[i].second - datanodes[0].second);
            if(sum <= t) maxi = i;
        }

        debug(maxi);

        int maxi2 = -1;
        for(int i = 0; i<datanodes.size(); i++){
            int sum = 0;
            sum += abs(xs - datanodes[0].first);
            sum += abs(ys - datanodes[0].second);
            sum += abs(datanodes[0].first - datanodes[i].first);
            sum += abs(datanodes[0].second - datanodes[i].second);
            if(sum <= t) maxi2 = i;
            
        }
        debug(maxi2);

        ans = max(maxi, maxi2)+1;


    }

    cout<<ans;



}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

