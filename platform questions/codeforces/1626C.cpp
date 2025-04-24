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

int sum (int l, int r){
    int left = (l-1) * (l) / 2;
    int right = r * (r+1) /2;
    return right - left;
}

void solvee(){
    int n;
    cin>>n;
    vector<int> seconds(n);
    for(int i = 0; i<n; i++){
        cin>>seconds[i];
    }

    vector<int> health(n);
    for(int i = 0; i<n; i++){
        cin>>health[i];
    }
    for(int i = 0; i<n; i++){
        cout<<seconds[i]<<"m"<<health[i]<<"n->";
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> seconds(n);
    for(int i = 0; i<n; i++){
        cin>>seconds[i];
    }

    vector<int> health(n);
    for(int i = 0; i<n; i++){
        cin>>health[i];
    }

    vector<int> timenew;
    vector<int> energynew;

    for(int i = 0; i<n; i++){
        int time = seconds[i];
        int energy = health[i];
        debug(time);
        debug(energy);
        int first = time - energy + 1;

        if(lower_bound(timenew.begin(), timenew.end(), first) == timenew.end()){
            debug(i);
            timenew.push_back(time);
            energynew.push_back(energy);
        }
        else{

            int xx = lower_bound(timenew.begin(), timenew.end(), first) - timenew.begin();
            debug(xx);
            int start = xx;
            if(timenew[start] == first) start++;
            debug(start);
            int yy = timenew.size();
            int maxi = INT_MIN;
            int maxitime = -1;
            int newhealth = -1;
            for(int j = start; j<yy; j++){
                int diff = time - timenew.back();
                newhealth = max(newhealth , energynew.back() + diff);
                timenew.pop_back();
                energynew.pop_back();

            }
            timenew.push_back(time);
            energynew.push_back(max(energy, newhealth));
        }
        print(timenew);
    }


    seconds = timenew;
    health = energynew;
    n = seconds.size();

    print(seconds);
    int ans =0;
    map<int,int> mp;
    vector<int> v;
    for(int i= 0; i<n; i++){
        int time = seconds[i];
        int energy = health[i];
        debug(time);
        debug(energy);
        int first = time - energy + 1;
        debug(first);
        if(lower_bound(v.begin(), v.end(), first) != v.end()){
            int lasttime = v.back();
            int lastenergy = mp[lasttime];
            int extratime = time - lasttime;
            ans += sum(lastenergy + 1, lastenergy + extratime);
            mp[time] = lastenergy + extratime;
        }
        else{
            ans += sum(1 , energy);
            mp[time] = energy;
        }

        v.push_back(time);

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
    for(int i = 1; i<=t; i++){
         solve();
    }
return 0;
}

