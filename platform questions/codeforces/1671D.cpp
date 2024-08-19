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

void solvee(){
    int n,x;
    cin>>n>>x;
    vector<int> input(n);
 
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        mini = min(mini , input[i]);
        maxi = max(maxi , input[i]);
    }

    cout<<n<<"abc"<<x<<"abc";
    for(int i = 0; i<n; i++){
        cout<<input[i]<<'a';
    }
    cout<<endl;
}
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> input(n);
 
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        cin>>input[i];
        mini = min(mini , input[i]);
        maxi = max(maxi , input[i]);
    }

    print(input);
    debug(mini);debug(maxi);

    // vector<int> xx(200006, 1);

    // for(int i = mini ; i<=maxi; i++){
    //     xx[i] = 0;
    // }

    set<pp> segments;
    
    set<pp> segments2;
    
    pp one;
    if(mini > 1){
        one.first = 1;
        one.second  = min(mini -1, x);
        segments.insert(one);
    }

    if(maxi < x){
        one.first = maxi+1;
        one.second = x;
        segments.insert(one);
    }


    for(auto ele : segments){
        segments2.insert({ele.second, ele.first});
    }
    

    

    // for(auto ele : segments){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    int ans = 0;

    for(int i = 1; i<n; i++){
        ans += abs(input[i] - input[i-1]);
    }

    int ans2 = ans;

    vector<int> v;
    unordered_set<int> visited;

    for (int i = 0; i < n; i++) {
        v.push_back(input[i]);
        if (input[i] >= mini && input[i] <= maxi && visited.insert(input[i]).second) {
            v.push_back(input[i]);
        }
    }




    print(input);
    for (const auto& ele : segments) {
        int toadd = ele.second - ele.first;
        int currans = INT_MAX;

        // Consider all pairs of adjacent elements in vector `v`
        for (int i = 1; i < v.size(); i++) {
            int curr = abs(ele.first - v[i-1]) + toadd + abs(v[i] - ele.second);
            currans = min(currans, curr);
            debug(curr);
        }

        // Consider the segment extending to the start of `v`
        currans = min(currans, toadd + abs(v[0] - ele.second));

        // Consider the segment extending to the end of `v`
        currans = min(currans, toadd + abs(v.back() - ele.first));

        ans += currans;
    }
    

    for (const auto& ele : segments2) {
        debug(ele.first);
        debug(ele.second);
        int toadd = abs(ele.second - ele.first);
        int currans = INT_MAX;

        // Consider all pairs of adjacent elements in vector `v`
        for (int i = 1; i < v.size(); i++) {
            int curr = abs(ele.first - v[i-1]) + toadd + abs(v[i] - ele.second);
            currans = min(currans, curr);
            debug(curr);
        }

        // Consider the segment extending to the start of `v`
        currans = min(currans, toadd + abs(v[0] - ele.second));

        // Consider the segment extending to the end of `v`
        currans = min(currans, toadd + abs(v.back() - ele.first));
        debug(currans);

        ans2 += currans;
    }


    cout<<min(ans, ans2)<<endl;
    
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
    // t = 1;
    for(int i= 1; i<=t; i++){
        solve();
    }
return 0;
}

