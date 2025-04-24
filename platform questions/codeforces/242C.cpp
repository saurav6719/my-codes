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
    int xi,yi, xf,yf;
    cin>>xi>>yi>>xf>>yf;

    int n;
    cin>>n;
    set<pp> st;

    pp final = {xf,yf};
    pp initial = {xi,yi};
    for(int i = 0; i<n; i++){
        int row;
        cin>>row;
        int colstart;
        cin>>colstart;
        int colend;
        cin>>colend;

        for(int j = colstart; j<= colend; j++){
            st.insert({row, j});
        }
    }

    queue<pp> qu;

    qu.push({xi, yi});


    map<pp, int> mp;

    mp[{xi, yi}] = 0;
    while(!qu.empty()){
        auto ff = qu.front();
        qu.pop();

        int xc = ff.first;
        int yc = ff.second;

        // All possible moves of a king (up, down, left, right, and 4 diagonals)
        vector<pp> directions = {
            {xc-1, yc},     // up
            {xc+1, yc},     // down
            {xc, yc-1},     // left
            {xc, yc+1},     // right
            {xc-1, yc-1},   // up-left
            {xc-1, yc+1},   // up-right
            {xc+1, yc-1},   // down-left
            {xc+1, yc+1}    // down-right
        };

        for(auto& move : directions){
            if(st.count(move) && mp.count(move) == 0){  // If move is valid and not visited
                mp[move] = mp[ff] + 1;  // Update distance
                if(move == final){       // If this is the destination
                    cout << mp[move];
                    return;
                }
                qu.push(move);  // Add the new position to the queue
            }
        }
    }

    cout<<-1;

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

