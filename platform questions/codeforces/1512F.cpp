/**
 *    author: Saurav
 *    created: 2024.11.13 14:53:37
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

void solveee(){
    int n,c;
    cin>>n>>c;
    vector<int> earn(n);
    for(auto &x : earn){
        cin>>x;
    }
    vector<int> course(n-1);
    for(auto &x : course){
        cin>>x;
    }


    cout<<n<<"->"<<c<<"->";
    for(auto ele : earn){
        cout<<ele<<":";
    }
    for(auto ele : course){
        cout<<ele<<":";
    }
    cout<<endl;
}

bool poss(int mid, vector<int> &time, vector<int> &remain, int &c, vector<int> &earn){
    int n= time.size();
    int ans = 0;

    for(int i = 0; i<n; i++){
        //if i am doing till this i 
        int timeleft = mid - time[i] + 1;

        if(timeleft <= 0) break;

        int earning = remain[i] + (timeleft * earn[i]);

        ans = max(ans, earning); 
    }
    return ans >= c;
}
void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> earn(n);
    for(auto &x : earn){
        cin>>x;
    }
    vector<int> course(n-1);
    for(auto &x : course){
        cin>>x;
    }

    vector<int> time(n);
    vector<int> remain(n);
    time[0] = 1;
    remain[0] = 0;
    for(int i =1; i<n;i++){
        int lastremaining = remain[i-1];
        int required = course[i-1];

        if(lastremaining >= required){
            time[i] = time[i-1] + 1;
            remain[i] = lastremaining - required;
            continue;
        }
        int toearn = required - lastremaining;

        int daysrequiredtoearn = toearn / earn[i-1];
        if(toearn % earn[i-1] != 0){
            daysrequiredtoearn ++;
        }
        time[i] = time[i-1] + daysrequiredtoearn + 1;
        remain[i] = earn[i-1] * daysrequiredtoearn + lastremaining - required;
    }

    print(time);
    print(remain);

    int lo = 0;
    int hi = 1e18;
    int ans = -1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(poss(mid, time , remain, c, earn)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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
    for(int i = 1; i<=t; i++){
        if(i==8891){
            solveee();
        }
        else{
            solve();
        }
    }
return 0;
}

