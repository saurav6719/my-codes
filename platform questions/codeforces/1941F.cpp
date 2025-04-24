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

int ff(vector<int> &f, int x){
    //closest number to x;

    int xx = lower_bound(f.begin(), f.end(), x) - f.begin();
    if(xx == 0) return f[0];
    if(xx == f.size()) return f[f.size()-1];
    if(f[xx] - x < x - f[xx-1]) return f[xx];
    return f[xx-1];
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    map<int,int> mp;
    int maxi = 0;
    for(int i = 1; i<n; i++){
        mp[input[i] - input[i-1]]++; 
        maxi = max(maxi , input[i] - input[i-1]);
    }

    vector<int> d(m);
    for(int i=0;i<m;i++){
        cin>>d[i];
    }
    vector<int> f(k);
    for(int i=0;i<k;i++){
        cin>>f[i];
    }

    sort(f.begin(), f.end());



    if(mp[maxi] > 1){
        cout<<maxi<<endl;
        return;
    }

    debug(maxi);

    int low;
    int hi;

    for(int i = 1; i<n; i++){
        if(input[i] - input[i-1] == maxi){
            low = input[i-1];
            hi = input[i];
            break;
        }
    }

    debug(low);

    debug(hi);
    int mid1 = (low + hi)/2;


    vector<int> temp;
    for(int i= 0; i<m; i++){
        int req = mid1 - d[i];
        int req2 = -1;
        if(low + hi % 2 != 0){
            req2 = mid1 - d[i] + 1;
        }

        debug(i);
        debug(req);
        debug(req2);

        int closest = ff(f, req);
        if(closest+d[i] >low and closest + d[i] < hi)temp.push_back(closest + d[i]);
        if(req2 != -1){
            int closest2 = ff(f, req2);
            if(closest2+d[i] >low and closest2 + d[i] < hi)temp.push_back(closest2 + d[i]);
            debug(closest2);
        }

        debug(closest);
    }


    sort(temp.begin(), temp.end());

    print(temp);

    // if(temp.empty()){
    //     cout<<maxi<<endl;
    //     return;
    // }

    vector<int> diff;
    for(int i = 0; i<temp.size(); i++){
        int aa = temp[i] - low; 
        int bb = hi - temp[i];
        int maxi = max(aa, bb);
        diff.push_back(maxi);
    }

    print(diff);

    int ans = 0;

    if(!diff.empty())  ans = *min_element(diff.begin(), diff.end());

    if(!diff.empty()) mp[ans]++;
    if(!diff.empty()) mp[maxi]--;
    if(mp[maxi] == 0) mp.erase(maxi);

    int final = 0;

    for(auto ele : mp){
        final = max(ans, ele.first);
    }

    cout<<final<<endl;





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

