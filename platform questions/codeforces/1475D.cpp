/**
 *    author: Saurav
 *    created: 2024.10.15 19:28:23
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
    cin>>n>>m;
    vector<int> storage(n);
    vector<int> importance(n);

    int sum =0;
    for(int i=0;i<n;i++){
        cin>>storage[i];
        sum += storage[i];
    }
    for(int i=0;i<n;i++){
        cin>>importance[i];
    }

    if(m > sum){
        cout<<-1<<endl;
        return ;
    }

    vector<pair<double, int>> ratio(n);
    for(int i=0;i<n;i++){
        ratio[i] = {storage[i]/(double)importance[i], i};
    }
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());

    int mremaining = m;

    multiset<int> oneremaining;
    multiset<int> tworemaining;
    for(int i = 0; i<n; i++){
        if(importance[i] == 1){
            oneremaining.insert(storage[i]);
        }
        else{
            tworemaining.insert(storage[i]);
        }
    }

    int ans = 0;
    int sumtaken = 0;

    vector<pp> taken;

    for(int i =0; i<n; i++){
        int onetop;
        int twotop;
        if(oneremaining.size() > 0){
            onetop = *oneremaining.rbegin();
        }
        else{
            onetop = 0;
        }
        if(tworemaining.size() > 0){
            twotop = *tworemaining.rbegin();
        }
        else{
            twotop = 0;
        }

        if(mremaining <= onetop){
            ans++;
            sumtaken += onetop;
            taken.push_back({onetop, 1});
            break;
        }
        else if(mremaining <= twotop){
            ans += 2;
            sumtaken += twotop;
            taken.push_back({twotop, 2});
            break;
        }


        int idx = ratio[i].second;
        sumtaken += storage[idx];
        ans += importance[idx];
        mremaining -= storage[idx];
        taken.push_back({storage[idx], importance[idx]});

        if(importance[idx] == 1){
            oneremaining.erase(oneremaining.find(storage[idx]));
        }
        else{
            tworemaining.erase(tworemaining.find(storage[idx]));
        }

    }

    vector<pair<double,int> > takenratio;
    for(int i = 0; i<taken.size(); i++){
        takenratio.push_back({(double)taken[i].first/(double)taken[i].second,i});
    }

    sort(takenratio.begin(), takenratio.end());

    int extrataken = sumtaken - m;
    for(int i = 0; i<takenratio.size(); i++){
        int idx = takenratio[i].second;
        if(extrataken <= 0){
            break;
        }
        int takenstorage = taken[idx].first;
        int takenimportance = taken[idx].second;
        if(takenstorage <= extrataken){
            ans-= takenimportance;
            extrataken -= takenstorage;
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

