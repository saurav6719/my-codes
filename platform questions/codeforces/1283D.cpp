/**
 *    author: Saurav
 *    created: 2024.10.16 02:06:39
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
    int n,m;
    cin>>n>>m;vector<int> input(n);
    for(int i=0;i<n;i++) cin>>input[i];
    vector<pp> intervals;

    sort(input.begin(),input.end());

    set<int> xmas;
    for(auto ele : input){
        xmas.insert(ele);
    }

    for(int i = 0; i<n; i++){
        int j = i;
        while(j+1<n && input[j+1] == input[j]+1) j++;
        intervals.push_back({input[i],input[j]});
        i = j;
    }

    int cnt = 0;
    int currincr = 1;
    int ans =0;

    set<int> people;
    while(cnt < m){
        sort(intervals.begin(),intervals.end());
        vector<pp> newintervals;
        for(int i = 0; i<intervals.size(); i++){
            int j = i+1;
            while(j<intervals.size() and intervals[j].first - intervals[j-1].second <= 1) j++;
            newintervals.push_back({intervals[i].first,intervals[j-1].second});
            i = j-1;
        }
        // for(auto ele : newintervals){
        //     cout<<ele.first<<" "<<ele.second<<endl;
        // }
        vector<pp> nextintervals;
        intervals = newintervals;
        sort(intervals.begin(),intervals.end());

        for(auto ele : intervals){
            int mini = ele.first;
            int maxi = ele.second;
            
            if(people.count(mini-1) == 0 and xmas.count(mini-1) == 0){
                people.insert(mini - 1);
                debug(mini-1);
                cnt++;
                ans += currincr;
                if(cnt == m) break;
            }

            if(people.count(maxi+1) == 0 and xmas.count(maxi+1) == 0){
                people.insert(maxi + 1);
                debug(maxi+1);
                cnt++;
                ans += currincr;
                if(cnt == m) break;
            }
            
            nextintervals.push_back({mini-1,maxi+1});

        }
        currincr++;
        intervals = nextintervals;
    }

    cout<<ans<<endl;
    for(auto ele : people) cout<<ele<<" ";

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

